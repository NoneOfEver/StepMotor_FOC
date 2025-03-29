#ifndef SPEED_TRACKER_H
#define SPEED_TRACKER_H

#ifdef __cplusplus
extern "C" {
#endif

//���ö˿ڶ���
#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"
/****************************************  �ٶȸ�����  ****************************************/
/****************************************  �ٶȸ�����  ****************************************/
/****************************************  �ٶȸ�����  ****************************************/
/**
  * Speed_Tracker��ṹ�嶨��
**/
typedef struct{
	//����(���ټ��ٶ�)
	#define	DE_UP_ACC			(Move_Rated_UpAcc / 10)
	bool		valid_up_acc;
	int32_t	up_acc;
	//����(���ټ��ٶ�)
	#define	DE_DOWN_ACC		(Move_Rated_DownAcc / 10)
	bool		valid_down_acc;
	int32_t	down_acc;
	//�����������
	int32_t		course_mut;	//���̼��ٶȻ���(�Ŵ�CONTROL_FREQ_HZ��)
	int32_t		course;			//�����ٶ�
	//���������
	int32_t		go_speed;		//�����ٶ�
}Speed_Tracker_Typedef;
extern Speed_Tracker_Typedef	speed_tck;

void Speed_Tracker_Set_UpAcc(int32_t value);		//�ٶȸ��������ü��ټ��ٶ�
void Speed_Tracker_Set_DownAcc(int32_t value);	//�ٶȸ��������ü��ټ��ٶ�
void Speed_Tracker_Set_Default(void);						//�ٶȸ����������ָ�

void Speed_Tracker_Init(void);												//�ٶȸ�������ʼ��
void Speed_Tracker_NewTask(int32_t real_speed);				//�ٶȿ�������ʼ������
void Speed_Tracker_Capture_Goal(int32_t goal_speed);	//�ٶȸ�������������ٶ�

#ifdef __cplusplus
}
#endif

#endif //SPEED_TRACKER_H
