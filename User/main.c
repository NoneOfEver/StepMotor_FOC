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
    //基本外设初始化(Base_Drivers)(LOOP直接进行)
	DMA_Tx_Init();
    DMA_Rx_Init();
	ADC_Function_Init();	
	
	//基本外设初始化()
	REIN_MT6816_Init();		//MT6816传感器初始化
	REIN_HW_Elec_Init();	//硬件电流控制器
	
	//控制初始化(Control)
	Calibration_Init();		//校准器初始化
	Motor_Control_Init();	//电机控制初始化
	
    while(1)
    {
        Calibration_Loop_Callback();							//校准器主程序回调					用于校准环节最后的数据解算
    }
}
