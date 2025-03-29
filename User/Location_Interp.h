#ifndef LOCATION_INTERP_H
#define LOCATION_INTERP_H

#ifdef __cplusplus
extern "C" {
#endif

//���ö˿ڶ���
#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"

/****************************************  λ�ò�����(����ϸ����ǿ)  ****************************************/
/****************************************  λ�ò�����(����ϸ����ǿ)  ****************************************/
/****************************************  λ�ò�����(����ϸ����ǿ)  ****************************************/
/**
  * Location_Interp��ṹ�嶨��
**/
typedef struct{
	//Դ�ź�����
	int32_t		record_location;				//��¼��λ��
	int32_t		record_location_last;		//��¼��λ��
	int32_t		est_location;						//���Ƶ�λ��
	int32_t		est_speed_mut;					//�����ٶȱ�ֵ(�Ŵ�n��)
	int32_t		est_speed;							//���Ƶ��ٶ�

	//������ٿ�����
	int32_t		go_location;		//����λ��
	int32_t		go_speed;				//�����ٶ�
}Location_Interp_Typedef;
extern Location_Interp_Typedef location_interp;

void Location_Interp_Init(void);																					//λ�ò�������ʼ��
void Location_Interp_NewTask(int32_t real_location, int32_t real_speed);	//λ�ò�������ʼ������
void Location_Interp_Capture_Goal(int32_t goal_location);									//λ�ò������������λ�ú������ٶ�

#ifdef __cplusplus
}
#endif

#endif









