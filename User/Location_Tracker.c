//Oneself
#include "Location_Tracker.h"

//Control
#include "Control_Config.h"

/****************************************  λ�ø�����  ****************************************/
/****************************************  λ�ø�����  ****************************************/
/****************************************  λ�ø�����  ****************************************/
//Location_Tracker�ṹ��
Location_Tracker_Typedef	location_tck;

/**
  * λ�ø�������������ٶ�
  * @param  value		����ٶ�
  * @retval true:�ɹ� / false:����
**/
void Location_Tracker_Set_MaxSpeed(int32_t value)
{
	value = abs(value);
	if((value > 0) && (value <= Move_Rated_Speed))
	{
		location_tck.max_speed = value;
		location_tck.valid_max_speed = true;
	}
	else
	{
		location_tck.valid_max_speed = false;
	}
}

/**
  * λ�ø��������ü��ټ��ٶ�
  * @param  value		���ټ��ٶ�	
  * @retval true:�ɹ� / false:����
**/
void Location_Tracker_Set_UpAcc(int32_t value)
{
	value = abs(value);
	if((value > 0) && (value <= Move_Rated_UpAcc))
	{
		location_tck.up_acc = value;
		location_tck.valid_up_acc = true;
	}
	else
	{
		location_tck.valid_up_acc = false;
	}
}

/**
  * λ�ø��������ü��ټ��ٶ�
  * @param  tracker		λ�ø�����ʵ��
  * @param  value		���ټ��ٶ�	
  * @retval true:�ɹ� / false:����
**/
void Location_Tracker_Set_DownAcc(int32_t value)
{
	value = abs(value);
	if((value > 0) && (value <= Move_Rated_UpAcc))
	{
		location_tck.down_acc = value;
		location_tck.down_acc_quick = 0.5f / (float)location_tck.down_acc;
		location_tck.valid_down_acc = true;
	}
	else
	{
		location_tck.valid_down_acc = false;
	}
}

/**
  * λ�ø����������ָ�
  * @param  NULL
  * @retval NULL
**/
void Location_Tracker_Set_Default(void)
{
	Location_Tracker_Set_MaxSpeed(DE_MAX_SPEED);
	Location_Tracker_Set_UpAcc(DE_UP_ACC);
	Location_Tracker_Set_DownAcc(DE_Down_ACC);
}

/**
  * λ�ø�������ʼ��
  * @param  tracker		λ�ø�����ʵ��
  * @retval NULL
**/
void Location_Tracker_Init()
{
	//ǰ��������Чʱ,����Ĭ������
	if(!location_tck.valid_max_speed)	{	Location_Tracker_Set_MaxSpeed(DE_MAX_SPEED);		}
	if(!location_tck.valid_up_acc)		{	Location_Tracker_Set_UpAcc(DE_UP_ACC);	}
	if(!location_tck.valid_down_acc)	{	Location_Tracker_Set_DownAcc(DE_Down_ACC);	}
	
	
	//��̬���õĸ��ٲ���
	location_tck.speed_locking_stop = Move_Pulse_NUM;	//ÿ��1תʱ������ͣ	(��ѵ�ֵӦ��Ϊ���ٶ�/1000�����Ǵ����������ٶȣ�������ȡֵ)
																								//(��ȷ�������Ӧ��Ϊ������λ������ת��Ϊ��������)
	//������̲���
	location_tck.course_acc_integral = 0;
	location_tck.course_speed = 0;
	location_tck.course_speed_integral = 0;
	location_tck.course_location = 0;
	//������ٿ�����
	location_tck.go_location = 0;
	location_tck.go_speed = 0;
}

/**
  * λ�ø�������ʼ������
  * @param  tracker			λ�ø�����ʵ��
  * @param  real_location	ʵʱλ��
  * @param  real_speed		ʵʱ�ٶ�
  * @retval NULL
**/
void Location_Tracker_NewTask(int32_t real_location, int32_t real_speed)
{
	//���¼����������
	location_tck.course_acc_integral = 0;			//���̼��ٶȻ���
	location_tck.course_speed = real_speed;			//�����ٶ�
	location_tck.course_speed_integral = 0;			//�����ٶȻ���
	location_tck.course_location = real_location;	//����λ��
}

/**
  * λ�ø������ٶȻ���
  * @param  value	���ٶ�
**/
#define Speed_Course_Integral(value)	\
{	\
	location_tck.course_acc_integral += value;											\
	location_tck.course_speed += location_tck.course_acc_integral / CONTROL_FREQ_HZ;		\
	location_tck.course_acc_integral = location_tck.course_acc_integral % CONTROL_FREQ_HZ;	\
}								//(C���Գ���������0ȡ����ֱ��ȡ�༴��)

/**
  * λ�ø�����λ�û���
  * @param  value	�ٶ�
**/
#define Location_Course_Integral(value)	\
{	\
	location_tck.course_speed_integral += value;											\
	location_tck.course_location += location_tck.course_speed_integral / CONTROL_FREQ_HZ;		\
	location_tck.course_speed_integral = location_tck.course_speed_integral % CONTROL_FREQ_HZ;	\
}								//(C���Գ���������0ȡ����ֱ��ȡ�༴��)

/**
  * λ�ø������������λ�ú������ٶ�
  * @param  tracker			λ�ø�����ʵ��
  * @param  goal_location	Ŀ��λ��
  * @retval NULL
**/
void Location_Tracker_Capture_Goal(int32_t goal_location)
{
	//����λ�ò�
	int32_t location_sub = goal_location - location_tck.course_location;

	/********************����Ŀ��********************/
	if(location_sub == 0)
	{
		/******************** �ٶ�С��ɲͣ�ٶ�********************/
		if((location_tck.course_speed >= -location_tck.speed_locking_stop) && (location_tck.course_speed <= location_tck.speed_locking_stop))
		{
			//���뾲ֹ->ȡ����������
			location_tck.course_acc_integral = 0;
			location_tck.course_speed = 0;
			location_tck.course_speed_integral = 0;
		}
		/********************�ٶ� > 0********************/
		else if(location_tck.course_speed > 0)
		{
			//������ٵ�0
			Speed_Course_Integral(-location_tck.down_acc)
			if(location_tck.course_speed <= 0)
			{
				location_tck.course_acc_integral = 0;
				location_tck.course_speed = 0;
			}
		}
		/********************�ٶ� < 0********************/
		else if(location_tck.course_speed < 0)
		{
			//������ٵ�0
			Speed_Course_Integral(location_tck.down_acc)
			if(location_tck.course_speed >= 0)
			{
				location_tck.course_acc_integral = 0;
				location_tck.course_speed = 0;
			}
		}
	}
	/********************δ����Ŀ��********************/
	else
	{
		/********************�ٶ�Ϊ0********************/
		if(location_tck.course_speed == 0)
		{
			if(location_sub > 0)
			{
				Speed_Course_Integral(location_tck.up_acc)	//��ʼ�������
			}
			else
			{
				Speed_Course_Integral(-location_tck.up_acc)	//��ʼ�������
			}
		}
		/********************�ٶ���λ�Ʒ���ͬ��(������)********************/
		else if((location_sub > 0) && (location_tck.course_speed > 0))
		{
			if(location_tck.course_speed <= location_tck.max_speed)
			{
				//������Ҫ�ļ���λ��
				int32_t need_down_location = (int32_t)((float)location_tck.course_speed * (float)location_tck.course_speed * (float)location_tck.down_acc_quick);	//��������
				if(abs(location_sub) > need_down_location)
				{
					//������ٵ�����ٶ�
					if(location_tck.course_speed < location_tck.max_speed)
					{
						Speed_Course_Integral(location_tck.up_acc);
						if(location_tck.course_speed >= location_tck.max_speed)
						{
							location_tck.course_acc_integral = 0;
							location_tck.course_speed = location_tck.max_speed;
						}
					}
					//��������
					//else if(location_tck.course_speed == location_tck.max_speed_max)
					//{}
					//������->����
					else if(location_tck.course_speed > location_tck.max_speed)
					{
						Speed_Course_Integral(-location_tck.down_acc);
					}
				}
				else
				{
					//������ٵ�0
					Speed_Course_Integral(-location_tck.down_acc);
					if(location_tck.course_speed <= 0)
					{
						location_tck.course_acc_integral = 0;
						location_tck.course_speed = 0;
					}
				}
			}
			else
			{
				//������ٵ�0
				Speed_Course_Integral(-location_tck.down_acc);
				if(location_tck.course_speed <= 0)
				{
					location_tck.course_acc_integral = 0;
					location_tck.course_speed = 0;
				}
			}
		}
		/********************�ٶ���λ�Ʒ���ͬ��(������)********************/
		else if((location_sub < 0) && (location_tck.course_speed < 0))
		{
			if(location_tck.course_speed >= -location_tck.max_speed)
			{
				//������Ҫ�ļ���λ��(��������յ�����)
				int32_t need_down_location = (int32_t)((float)location_tck.course_speed * (float)location_tck.course_speed * (float)location_tck.down_acc_quick);	//��������
				if(abs(location_sub) > need_down_location)
				{
					//������ٵ�����ٶ�
					if(location_tck.course_speed > -location_tck.max_speed)
					{
						Speed_Course_Integral(-location_tck.up_acc);
						if(location_tck.course_speed <= -location_tck.max_speed)
						{
							location_tck.course_acc_integral = 0;
							location_tck.course_speed = -location_tck.max_speed;
						}
					}
					//��������
					//else if(location_tck.course_speed == -location_tck.max_speed_max)
					//{}
					//������->����
					else if(location_tck.course_speed < -location_tck.max_speed)
					{
						Speed_Course_Integral(location_tck.down_acc);
					}
				}
				else
				{
					//������ٵ�0
					Speed_Course_Integral(location_tck.down_acc);
					if(location_tck.course_speed >= 0)
					{
						location_tck.course_acc_integral = 0;
						location_tck.course_speed = 0;
					}
				}
			}
			else
			{
				//������ٵ�0
				Speed_Course_Integral(location_tck.down_acc);
				if(location_tck.course_speed >= 0)
				{
					location_tck.course_acc_integral = 0;
					location_tck.course_speed = 0;
				}
			}
		}
		/********************�ٶ���λ�Ʒ�����********************/
		else if((location_sub < 0) && (location_tck.course_speed > 0))
		{
			//������ٵ�0
			Speed_Course_Integral(-location_tck.down_acc);
			if(location_tck.course_speed <= 0)
			{
				location_tck.course_acc_integral = 0;
				location_tck.course_speed = 0;
			}
		}
		else if(((location_sub > 0) && (location_tck.course_speed < 0)))
		{
			//������ٵ�0
			Speed_Course_Integral(location_tck.down_acc);
			if(location_tck.course_speed >= 0)
			{
				location_tck.course_acc_integral = 0;
				location_tck.course_speed = 0;
			}
		}		
	}

	//λ�û���
	Location_Course_Integral(location_tck.course_speed);

	//���
	location_tck.go_location = (int32_t)location_tck.course_location;
	location_tck.go_speed = (int32_t)location_tck.course_speed;
}

