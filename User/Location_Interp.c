//Oneself
#include "Location_Interp.h"

//Control
#include "control_config.h"

/****************************************  λ�ò�����  ****************************************/
/****************************************  λ�ò�����  ****************************************/
/****************************************  λ�ò�����  ****************************************/
//Location_Interpʵ��
Location_Interp_Typedef location_interp;

/**
  * λ�ò�������ʼ��
  * @param  interp	λ�ò岹��ʵ��
  * @retval NULL
**/
void Location_Interp_Init(void)
{
	//Դ�ź�����
	location_interp.record_location = 0;
	location_interp.record_location_last = 0;
	location_interp.est_location = 0;
	location_interp.est_speed_mut = 0;
	location_interp.est_speed = 0;
	//������ٿ�����
	location_interp.go_location = 0;
	location_interp.go_speed = 0;
}

/**
  * λ�ò�������ʼ������
  * @param  interp			λ�ò岹��ʵ��
  * @param  real_location	ʵʱλ��
  * @param  real_speed		ʵʱ�ٶ�
  * @retval NULL
**/
void Location_Interp_NewTask(int32_t real_location, int32_t real_speed)
{
	//����Դ�ź�����
	location_interp.record_location = real_location;
	location_interp.record_location_last = real_location;
	location_interp.est_location = real_location;
	location_interp.est_speed = real_speed;
}

/**
  * λ�ò������������λ�ú������ٶ�
  * @param  interp			λ�ò岹��ʵ��
  * @param  goal_location	Ŀ��λ��
  * @param  NULL
  * @retval NULL
**/
void Location_Interp_Capture_Goal(int32_t goal_location)
{
	//��¼Դ�ź�
	location_interp.record_location_last = location_interp.record_location;
	location_interp.record_location = goal_location;

	//����Դ�ź��ٶ�
	location_interp.est_speed_mut += (	((location_interp.record_location - location_interp.record_location_last) * CONTROL_FREQ_HZ)
							  + ((int32_t)(location_interp.est_speed  << 6) - (int32_t)(location_interp.est_speed))
							 );
	location_interp.est_speed 	   = (location_interp.est_speed_mut >> 6);							//(��64ȡ��)(��0ȡ��)(��������λ)
	location_interp.est_speed_mut  = (location_interp.est_speed_mut - (location_interp.est_speed << 6));	//(��64ȡ��)(��0ȡ��)(��������λ)
	//����Դ�ź�λ��
	location_interp.est_location = location_interp.record_location;

	//���
	location_interp.go_location = location_interp.est_location;
	location_interp.go_speed = location_interp.est_speed;
}



