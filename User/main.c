//Application_User_Core
#include "dma.h"
#include "adc.h"

//Base_Drivers
#include "ch32v20x.h"
#include "mt6816.h"
#include "hw_elec.h"

//Control
#include "motor_control.h"
#include "encode_cali.h"
#include "debug.h"


/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    USART_Printf_Init(115200);
    SystemCoreClockUpdate();
    Delay_Init();
    //���������ʼ��(Base_Drivers)(LOOPֱ�ӽ���)
	DMA_Tx_Init();
    DMA_Rx_Init();
	ADC_Function_Init();	
	
	//���������ʼ��()
	REIN_MT6816_Init();		//MT6816��������ʼ��
	REIN_HW_Elec_Init();	//Ӳ������������
	
	//���Ƴ�ʼ��(Control)
	Calibration_Init();		//У׼����ʼ��
	Motor_Control_Init();	//������Ƴ�ʼ��
	
    while(1)
    {
        Calibration_Loop_Callback();							//У׼��������ص�					����У׼�����������ݽ���
    }
}
