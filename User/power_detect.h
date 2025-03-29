#ifndef POWER_DETECT_H
#define POWER_DETECT_H

#ifdef __cplusplus
extern "C" {
#endif

//引用端口定义
#include "ch32v20x.h"

typedef struct{
	uint16_t	adc_voltage;	//电压ADC
	uint16_t	adc_current;	//电流ADC
	uint32_t	est_voltage;		//滤波电压
	uint32_t	est_current;		//滤波电流
}Power_Typedef;
extern Power_Typedef power;

inline void Power_Detection_Run(void);		//电源检测运行

#ifdef __cplusplus
}
#endif

#endif
