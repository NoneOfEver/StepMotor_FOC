#ifndef LOCATION_TRACKER_H
#define LOCATION_TRACKER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"
/****************************************  λ�ø�����  ****************************************/
/****************************************  λ�ø�����  ****************************************/
/****************************************  λ�ø�����  ****************************************/
/**
  * Location_Tracker��ṹ�嶨��
**/
typedef struct{
	//����(�ٶ�)
	#define	DE_MAX_SPEED	(Move_Rated_Speed)
	bool		valid_max_speed;
	int32_t	max_speed;
	//����(���ټ��ٶ�)
	#define	DE_UP_ACC			(Move_Rated_UpAcc / 10)
	bool		valid_up_acc;
	int32_t	up_acc;
	//����(���ټ��ٶ�)
	#define	DE_Down_ACC		(Move_Rated_DownAcc / 10)
	bool		valid_down_acc;
	int32_t	down_acc;
	float		down_acc_quick;	//����������		1.0f / (2.0f * down_acc)
	//��̬���õĸ��ٲ���
	int32_t		speed_locking_stop;			//����ֱ�ӱ���ͣ�����ٶ�
	//�����������
	int32_t		course_acc_integral;		//���̼��ٶȻ���(�Ŵ�CONTROL_FREQ_HZ��)
	int32_t		course_speed;						//�����ٶ�
	int32_t		course_speed_integral;	//�����ٶȻ���(�Ŵ�CONTROL_FREQ_HZ��)
	int32_t		course_location;				//����λ��
	//������ٿ�����
	int32_t		go_location;	//����λ��
	int32_t		go_speed;			//�����ٶ�
}Location_Tracker_Typedef;
extern Location_Tracker_Typedef	location_tck;

void Location_Tracker_Set_MaxSpeed(int32_t value);//λ�ø�������������ٶ�
void Location_Tracker_Set_UpAcc(int32_t value);		//λ�ø��������ü��ټ��ٶ�
void Location_Tracker_Set_DownAcc(int32_t value);	//λ�ø��������ü��ټ��ٶ�
void Location_Tracker_Set_Default(void);					//λ�ø����������ָ�

void Location_Tracker_Init(void);																					//λ�ø�������ʼ��
void Location_Tracker_NewTask(int32_t real_location, int32_t real_speed);	//λ�ø�������ʼ������
void Location_Tracker_Capture_Goal(int32_t goal_location);								//λ�ø������������λ�ú������ٶ�

#ifdef __cplusplus
}
#endif

#endif //LOCATION_TRACKER_H
