#include "power_detect.h"
//Application_User_Core
#include "ADC.h"

Power_Typedef power;

/**
  * @brief  电源检测运行
  * @param  NULL
  * @retval NULL
**/
void Power_Detection_Run(void)
{
	//电压采样
	power.adc_voltage = whole_adc_data[ADC_POWER_U_GROUP][ADC_POWER_U_CHANNEL];
	power.est_voltage = ((power.est_voltage * 31) + (((uint32_t)power.adc_voltage * 36300) >> 12)) >> 5;
	
	//电流采样(没有硬件版本支持电流检测)
	power.adc_current = whole_adc_data[ADC_POWER_I_GROUP][ADC_POWER_I_CHANNEL];
	power.est_current = 0;
}





