#ifndef POWER_DETECT_H
#define POWER_DETECT_H

#ifdef __cplusplus
extern "C" {
#endif

//���ö˿ڶ���
#include "ch32v20x.h"

typedef struct{
	uint16_t	adc_voltage;	//��ѹADC
	uint16_t	adc_current;	//����ADC
	uint32_t	est_voltage;		//�˲���ѹ
	uint32_t	est_current;		//�˲�����
}Power_Typedef;
extern Power_Typedef power;

inline void Power_Detection_Run(void);		//��Դ�������

#ifdef __cplusplus
}
#endif

#endif
