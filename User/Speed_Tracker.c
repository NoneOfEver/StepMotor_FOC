//Oneself
#include "Speed_Tracker.h"

//Control
#include "Control_Config.h"

/****************************************  �ٶȸ�����  ****************************************/
/****************************************  �ٶȸ�����  ****************************************/
/****************************************  �ٶȸ�����  ****************************************/
//Speed_Tracker��ṹ��
Speed_Tracker_Typedef	speed_tck;

/**
  * �ٶȸ��������ü��ټ��ٶ�
  * @param  tracker		�ٶȸ�����ʵ��
  * @retval true:�ɹ� / false:����
**/
void Speed_Tracker_Set_UpAcc(int32_t value)
{
	value = abs(value);
	if((value > 0) && (value <= Move_Rated_UpAcc))
	{
		speed_tck.up_acc = value;
		speed_tck.valid_up_acc = true;
	}
	else{
		speed_tck.valid_up_acc = false;
	}
}

/**
  * �ٶȸ��������ü��ټ��ٶ�
  * @param  tracker		�ٶȸ�����ʵ��
  * @retval true:�ɹ� / false:����
**/
void Speed_Tracker_Set_DownAcc(int32_t value)
{
	value = abs(value);
	if((value > 0) && (value <= Move_Rated_DownAcc))
	{
		speed_tck.down_acc = value;
		speed_tck.valid_down_acc = true;
	}
	else{
		speed_tck.valid_down_acc = true;
	}
}

/**
  * �ٶȸ����������ָ�
  * @param  NULL
  * @retval NULL
**/
void Speed_Tracker_Set_Default(void)
{
	Speed_Tracker_Set_UpAcc(DE_UP_ACC);
	Speed_Tracker_Set_DownAcc(DE_DOWN_ACC);
}

/**
  * �ٶȸ�������ʼ��
  * @param  tracker		�ٶȸ�����ʵ��
  * @retval NULL
**/
void Speed_Tracker_Init(void)
{
	//ǰ��������Чʱ,����Ĭ������
	if(!speed_tck.valid_up_acc)			{	Speed_Tracker_Set_UpAcc(DE_UP_ACC);			}
	if(!speed_tck.valid_down_acc)		{	Speed_Tracker_Set_DownAcc(DE_DOWN_ACC);	}
	
	//�����������
	speed_tck.course_mut = 0;
	speed_tck.course = 0;
	//���������
	speed_tck.go_speed = 0;
}

/**
  * �ٶȸ�������ʼ������
  * @param  tracker			�ٶȸ�����ʵ��
  * @param  real_speed		ʵʱ�ٶ�
  * @retval NULL
**/
void Speed_Tracker_NewTask(int32_t real_speed)
{
	//���¼����������
	speed_tck.course_mut = 0;		//���̼��ٶȻ���
	speed_tck.course = real_speed;		//�����ٶ�
}

/**
  * �ٶȸ������ٶȻ���
  * @param  value	���ٶ�
**/
#define Speed_Course_Integral(value)	\
{	\
	speed_tck.course_mut += value;											\
	speed_tck.course += speed_tck.course_mut / CONTROL_FREQ_HZ;		\
	speed_tck.course_mut = speed_tck.course_mut % CONTROL_FREQ_HZ;	\
}

/**
  * �ٶȸ�������������ٶ�
  * @param  tracker			�ٶȸ�����ʵ��
  * @param  goal_speed		Ŀ���ٶ�
  * @retval NULL
**/
void Speed_Tracker_Capture_Goal(int32_t goal_speed)
{
	//�����ٶȲ�
	int32_t speed_sub = goal_speed - speed_tck.course;

	/********************�ٶȵ���Ŀ���ٶ�********************/
	if(speed_sub == 0)
	{
		speed_tck.course = goal_speed;		//��������״̬
	}
	/********************ʸ���ٶ�С��Ŀ��********************/
	else if(speed_sub > 0)
	{
		if(speed_tck.course >= 0)
		{
			Speed_Course_Integral(speed_tck.up_acc);
			if(speed_tck.course >= goal_speed)
			{
				speed_tck.course_mut = 0;
				speed_tck.course = goal_speed;
			}
		}
		else
		{
			Speed_Course_Integral(speed_tck.down_acc);
			if(speed_tck.course >= 0)
			{
				speed_tck.course_mut = 0;
				speed_tck.course = 0;
			}
		}
	}
	/********************ʸ���ٶȴ���Ŀ��********************/
	else if(speed_sub < 0)
	{
		if(speed_tck.course <= 0)
		{
			Speed_Course_Integral(-speed_tck.up_acc);
			if(speed_tck.course <= goal_speed)
			{
				speed_tck.course_mut = 0;
				speed_tck.course = goal_speed;
			}
		}
		else
		{
			Speed_Course_Integral(-speed_tck.down_acc);
			if(speed_tck.course <= 0)
			{
				speed_tck.course_mut = 0;
				speed_tck.course = 0;
			}
		}
	}

	//���
	speed_tck.go_speed = (int32_t)speed_tck.course;
}

