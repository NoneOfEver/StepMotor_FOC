#ifndef HW_ELEC_H
#define HW_ELEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ch32v20x.h"
/**
  * ��Ȧ����
**/
typedef struct{
	uint16_t conver;		//SIN����ָ��
	int16_t  sin_data;	//SIN������ֵ
	uint16_t dac_reg;		//12λDAC��ֵ
}Coil_Typedef;

extern Coil_Typedef		coil_a;	//��������
extern Coil_Typedef		coil_b;	//��������

void REIN_HW_Elec_Init(void);																				//Ӳ���������Ƴ�ʼ��
void REIN_HW_Elec_SetSleep(void);																		//Ӳ��������������˯��
void REIN_HW_Elec_SetBrake(void);																		//Ӳ��������������ɲ��
void REIN_HW_Elec_SetDivideElec(uint32_t divide, int32_t elec_ma);	//Ӳ�������������ϸ�ֵ���

#ifdef __cplusplus
}
#endif

#endif

