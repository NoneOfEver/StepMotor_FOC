#include "power_detect.h"
//Application_User_Core
#include "ADC.h"

Power_Typedef power;

/**
  * @brief  ��Դ�������
  * @param  NULL
  * @retval NULL
**/
void Power_Detection_Run(void)
{
	//��ѹ����
	power.adc_voltage = whole_adc_data[ADC_POWER_U_GROUP][ADC_POWER_U_CHANNEL];
	power.est_voltage = ((power.est_voltage * 31) + (((uint32_t)power.adc_voltage * 36300) >> 12)) >> 5;
	
	//��������(û��Ӳ���汾֧�ֵ������)
	power.adc_current = whole_adc_data[ADC_POWER_I_GROUP][ADC_POWER_I_CHANNEL];
	power.est_current = 0;
}





