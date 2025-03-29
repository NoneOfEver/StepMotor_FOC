//Oneself
#include "Current_Tracker.h"

//Control
#include "Control_Config.h"

/****************************************  ����������  ****************************************/
/****************************************  ����������  ****************************************/
/****************************************  ����������  ****************************************/
//Current_Tracker��ṹ��
Current_Tracker_Typedef	current_tck;

/**
  * �������������������仯��
  * @param  value:	�����ݶ�
  * @retval NULL
**/
void Current_Tracker_Set_UpRate(int32_t value)
{
	value = abs(value);
	if((value > 0) && (value <= Move_Rated_UpCurrentRate))
	{
		current_tck.up_rate = value;
		current_tck.valid_up_rate = true;
	}
	else{
		current_tck.valid_up_rate = false;
	}
}

/**
  * �������������ü����仯��
  * @param  value:	�����ݶ�
  * @retval NULL
**/
void Current_Tracker_Set_DownRate(int32_t value)
{
	value = abs(value);
	if((value > 0) && (value <= Move_Rated_DownCurrentRate))
	{
		current_tck.down_rate = value;
		current_tck.valid_down_rate = true;
	}
	else{
		current_tck.valid_down_rate = false;
	}
}

/**
  * ���������������ָ�
  * @param  NULL
  * @retval NULL
**/
void Current_Tracker_Set_Default(void)
{
	Current_Tracker_Set_UpRate(De_Up_Rate);
	Current_Tracker_Set_DownRate(De_Down_Rate);
}

/**
  * ������������ʼ��
  * @param  NULL
  * @retval NULL
**/
void Current_Tracker_Init(void)
{
	//ǰ��������Чʱ,����Ĭ������
	if(!current_tck.valid_up_rate)			{	Current_Tracker_Set_UpRate(De_Up_Rate);			}
	if(!current_tck.valid_down_rate)		{	Current_Tracker_Set_DownRate(De_Down_Rate);	}

	//�����������
	current_tck.course_mut = 0;
	current_tck.course = 0;
	//���������
	current_tck.go_current = 0;
}

/**
  * ������������ʼ��
  * @param  real_current	ʵʱ����
  * @retval NULL
**/
void Current_Tracker_NewTask(int16_t real_current)
{
	//���¼����������
	current_tck.course_mut = 0;				//���̵���
	current_tck.course = real_current;	//���̵���
}

/**
  * ������������������
  * @param  value	�ݶ�
**/
#define Current_Course_Integral(value)	\
{	\
	current_tck.course_mut += value;											\
	current_tck.course += current_tck.course_mut / CONTROL_FREQ_HZ;		\
	current_tck.course_mut = current_tck.course_mut % CONTROL_FREQ_HZ;	\
}

/**
  * ���������������������
  * @param  tracker			����������ʵ��
  * @param  goal_current	Ŀ�����
  * @retval NULL
**/
void Current_Tracker_Capture_Goal(int32_t goal_current)
{
	//���ε�����
	int32_t electric_sub = goal_current - current_tck.course;	//������	= ������Ŀ����� - ����������

	/********************��������Ŀ�����********************/
	if(electric_sub == 0)
	{
		current_tck.course = goal_current;		//��������״̬
	}
	/********************ʸ������С��Ŀ��********************/
	else if(electric_sub > 0)
	{
		if(current_tck.course >= 0)
		{
			Current_Course_Integral(current_tck.up_rate);
			if(current_tck.course >= goal_current)
			{
				current_tck.course_mut = 0;
				current_tck.course = goal_current;
			}
		}
		else// if(current_tck.course < 0)
		{
			Current_Course_Integral(current_tck.down_rate);
			if((int32_t)current_tck.course >= 0)
			{
				current_tck.course_mut = 0;
				current_tck.course = 0;
			}
		}
	}
	/********************ʸ����������Ŀ��********************/
	else if(electric_sub < 0)
	{
		if(current_tck.course <= 0)
		{
			Current_Course_Integral(-current_tck.up_rate);
			if((int32_t)current_tck.course <= (int32_t)goal_current)
			{
				current_tck.course_mut = 0;
				current_tck.course = goal_current;
			}
		}
		else// if(current_tck.course > 0)
		{
			Current_Course_Integral(-current_tck.down_rate);
			if((int32_t)current_tck.course <= 0)
			{
				current_tck.course_mut = 0;
				current_tck.course = 0;
			}
		}
	}

	//���
	current_tck.go_current = (int32_t)current_tck.course;
}

