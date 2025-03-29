//Oneself
#include "Move_Reconstruct.h"

//Control.h
#include "Control_Config.h"

/****************************************  �˶��ع���  ****************************************/
/****************************************  �˶��ع���  ****************************************/
/****************************************  �˶��ع���  ****************************************/
//Move_Reconstructʵ��
Move_Reconstruct_Typedef move_reco;

/**
  * �˶��ع������ü��ټ��ٶ�
  * @param  reconstruct		�˶��ع���ʵ��
  * @retval true:�ɹ� / false:����
**/
void Move_Reconstruct_Set_DownAcc(int32_t value)
{
	value = abs(value);
	if((value > 0) && (value <= Move_Rated_DownAcc))
	{
		move_reco.down_acc = value;
		move_reco.valid_down_acc = true;
	}
	else{
		move_reco.valid_down_acc = false;
	}
}

/**
  * �˶��ع������ó�ʱʱ��
  * @param  reconstruct		�˶��ع���ʵ��
  * @retval true:�ɹ� / false:����
**/
void Move_Reconstruct_Set_OverTime(uint16_t value)
{
	if((value >= Reconstruct_Min_OverTime) && (value <= Reconstruct_Max_OverTime))
	{
		move_reco.overtime = value;
		move_reco.valid_overtime = true;
	}
	else{
		move_reco.valid_overtime = false;
	}
}

/**
  * �˶��ع��������ָ�
  * @param  NULL
  * @retval NULL
**/
void Move_Reconstruct_Set_Default(void)
{
	Move_Reconstruct_Set_DownAcc(DE_DOWN_ACC);
	Move_Reconstruct_Set_OverTime(DE_OverTime);	
}

/**
  * �˶��ع�����ʼ��
  * @param  reconstruct		�˶��ع���ʵ��
  * @retval NULL
**/
void Move_Reconstruct_Init(void)
{
	//ǰ��������Чʱ,����Ĭ������
	if(!move_reco.valid_down_acc)	{	Move_Reconstruct_Set_DownAcc(DE_DOWN_ACC);	}
	if(!move_reco.valid_overtime)	{	Move_Reconstruct_Set_OverTime(DE_OverTime);	}
	
	//��̬���ٲ���
	move_reco.dyn_speed_acc = 0;
	//Դ�źż�¼
	move_reco.record_timer = 0;
	move_reco.overtime_flag = false;
	move_reco.record_speed = 0;
	move_reco.record_location = 0;
	//�����������
	move_reco.speed_course_dec = 0;
	move_reco.speed_course = 0;
	move_reco.location_course_dec = 0;
	move_reco.location_course = 0;
	//������ٿ�����
	move_reco.go_location = 0;
	move_reco.go_speed = 0;
}

/**
  * �˶��ع�����ʼ������
  * @param  reconstruct		�˶��ع���ʵ��
  * @param  real_location	ʵʱλ��
  * @param  real_speed		ʵʱ�ٶ�
  * @retval NULL
**/
void Move_Reconstruct_NewTask(int32_t real_location, int32_t real_speed)
{
	//Դ�źż�¼
	move_reco.record_timer = 0;			//�ź�Դ��ʱ������
	move_reco.overtime_flag = false;		//��ʱ��־��λ
	//���¼����������
	move_reco.speed_course_dec = 0;				//�����ٶ�
	move_reco.speed_course = real_speed;			//�����ٶ�
	move_reco.location_course_dec = 0;			//����λ��
	move_reco.location_course = real_location;	//����λ��
}

/**
  * �˶��ع����ٶȻ���
  * @param  value	���ٶ�
**/
#define Speed_Course_Integral(value)	\
{	\
	move_reco.speed_course_dec += value;												\
	move_reco.speed_course += move_reco.speed_course_dec / CONTROL_FREQ_HZ;		\
	move_reco.speed_course_dec = move_reco.speed_course_dec % CONTROL_FREQ_HZ;	\
}								//(C���Գ���������0ȡ����ֱ��ȡ�༴��)

/**
  * �˶��ع���λ�û���
  * @param  value	�ٶ�
**/
#define Location_Course_Integral(value)	\
{	\
	move_reco.location_course_dec += value;												\
	move_reco.location_course += move_reco.location_course_dec / CONTROL_FREQ_HZ;		\
	move_reco.location_course_dec = move_reco.location_course_dec % CONTROL_FREQ_HZ;	\
}								//(C���Գ���������0ȡ����ֱ��ȡ�༴��)

/**
  * �˶��ع����������λ�ú������ٶ�
  * @param  reconstruct		�˶��ع���ʵ��
  * @param  goal_location	Ŀ��λ��
  * @param  goal_speed		Ŀ���ٶ�
  * @retval NULL
**/
void Move_Reconstruct_Capture_Goal(int32_t goal_location, int32_t goal_speed)
{
	//������Ŀ��
	if( (goal_speed != move_reco.record_speed)
	 || (goal_location != move_reco.record_location))
	{
		//Դ�źż�¼
		move_reco.record_timer = 0;
		move_reco.record_speed = goal_speed;
		move_reco.record_location = goal_location;
		//���¶�̬���ٲ���
		move_reco.dyn_speed_acc = (int32_t)(   (float)(goal_speed + move_reco.speed_course) * (float)(goal_speed - move_reco.speed_course)
											    / (float)(2 * (goal_location - move_reco.location_course))
											  );
		//��������
		move_reco.overtime_flag = false;
	}
	else
	{
		//Դ�źų�ʱ����
		if(move_reco.record_timer >= (200 * 1000))
			move_reco.overtime_flag = true;
		else
			move_reco.record_timer += CONTROL_PERIOD_US;
	}

	//����˶�����
	if(move_reco.overtime_flag)
	{//��ʱ->��ʼ����Ϊ0
		if(move_reco.speed_course == 0)
		{
			move_reco.speed_course_dec = 0;
			move_reco.speed_course = 0;
		}
		else if(move_reco.speed_course > 0)
		{
			Speed_Course_Integral(-move_reco.down_acc);
			if(move_reco.speed_course <= 0)
			{
				move_reco.speed_course_dec = 0;
				move_reco.speed_course = 0;
			}
		}
		else
		{
			Speed_Course_Integral(move_reco.down_acc);
			if(move_reco.speed_course >= 0)
			{
				move_reco.speed_course_dec = 0;
				move_reco.speed_course = 0;
			}
		}
	}
	else
	{//δ��ʱ->����Ԥ����ٶȱ���
		Speed_Course_Integral(move_reco.dyn_speed_acc);
	}

	//λ�û���
	Location_Course_Integral(move_reco.speed_course);

	//���
	move_reco.go_location = (int32_t)move_reco.location_course;
	move_reco.go_speed = (int32_t)move_reco.speed_course;
}



