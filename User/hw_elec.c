//Oneself
#include "hw_elec.h"
#include "ch32v20x_tim.h"
#include "sin_form.h"
#include "stdlib.h"
//GPIO输出
#define Out_AP_H()		GPIOA -> BSHR = GPIO_Pin_0
#define Out_AP_L()		GPIOA -> BCR = GPIO_Pin_0
#define Out_AM_H()		GPIOA -> BSHR = GPIO_Pin_1
#define Out_AM_L()		GPIOA -> BCR = GPIO_Pin_1
#define Out_BP_H()		GPIOA -> BSHR = GPIO_Pin_3
#define Out_BP_L()		GPIOA -> BCR = GPIO_Pin_3
#define Out_BM_H()		GPIOA -> BSHR = GPIO_Pin_6
#define Out_BM_L()		GPIOA -> BCR = GPIO_Pin_6
//TIM输出
#define Out_PWMtoDAC_A(value)		(TIM_SetCompare3(TIM2, value))
#define Out_PWMtoDAC_B(value)		(TIM_SetCompare2(TIM3, value))

//硬件电流实例
Coil_Typedef		coil_a;	//电流控制
Coil_Typedef		coil_b;	//电流控制

void REIN_GPIO_HwElec_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
  /* GPIO Ports Clock Enable*/
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  /*Configure GPIO pin Output Level*/
	GPIOA -> BCR = GPIO_Pin_0;		//AP引脚启动输出低电平
	GPIOA -> BCR = GPIO_Pin_1;		//AM引脚启动输出低电平
	GPIOA -> BCR = GPIO_Pin_3;		//BP引脚启动输出低电平
	GPIOA -> BCR = GPIO_Pin_6;		//BM引脚启动输出低电平
	/*Configure GPIO pins*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//高速
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	/*Configure GPIO pins*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//高速
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	/*Configure GPIO pins*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//高速
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	/*Configure GPIO pins*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//高速
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void REIN_TIM_HwElec_Init(void)
{
	/* AFIO初始化 */
	GPIO_InitTypeDef GPIO_InitStructure = {0};
	/*GPIO Ports Clock Enable*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//CLK
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	/*Configure GPIO pins*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//CLK
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);		
	/* TIM初始化 */
	TIM_OCInitTypeDef TIM_OCInitStructure={0};
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure={0};
	/*TIM Clock Enable*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2|RCC_APB1Periph_TIM3, ENABLE );			//启用TIM时钟
	/*Configure TIM*/
	TIM_TimeBaseInitStructure.TIM_Period = (1024 - 1);									//10位周期(70.312KHz)
	TIM_TimeBaseInitStructure.TIM_Prescaler = 2-1;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit( TIM2, &TIM_TimeBaseInitStructure);

	TIM_TimeBaseInitStructure.TIM_Period = (1024 - 1);									//10位周期(70.312KHz)
	TIM_TimeBaseInitStructure.TIM_Prescaler = 2-1;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit( TIM3, &TIM_TimeBaseInitStructure);


	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init( TIM2, &TIM_OCInitStructure );

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init( TIM3, &TIM_OCInitStructure );

	TIM_CtrlPWMOutputs(TIM2, ENABLE );
	TIM_CtrlPWMOutputs(TIM3, ENABLE );

	TIM_OC1PreloadConfig( TIM2, TIM_OCPreload_Disable );
    TIM_OC1PreloadConfig( TIM3, TIM_OCPreload_Disable );

	TIM_ARRPreloadConfig( TIM2, ENABLE );
    TIM_ARRPreloadConfig( TIM3, ENABLE );
	
    TIM_Cmd( TIM2, ENABLE );
    TIM_Cmd( TIM3, ENABLE );
}

/**
  * @brief  12位基准电压混合输出
  * @param  elec_va: 电流通道a基准
  * @param  elec_vb: 电流通道b基准
  * @retval NULL
  */
void CurrentControl_VREF_12Bit_MixOut(uint16_t elec_va, uint16_t elec_vb)
{
	Out_PWMtoDAC_A((elec_va >> 2));
	Out_PWMtoDAC_B((elec_vb >> 2));
}

/**
  * @brief  硬件电流控制初始化
  * @param  NULL
  * @retval NULL
**/
void REIN_HW_Elec_Init(void)
{
	//外设配置
	REIN_GPIO_HwElec_Init();
	REIN_TIM_HwElec_Init();
}

/**
  * @brief  设置睡眠
  * @param  NULL
  * @retval NULL
  */
void REIN_HW_Elec_SetSleep(void)
{
	coil_a.dac_reg = 0;
	coil_b.dac_reg = 0;
	CurrentControl_VREF_12Bit_MixOut(coil_a.dac_reg, coil_b.dac_reg);
	Out_AP_L();	Out_AM_L();
	Out_BP_L();	Out_BM_L();
}

/**
  * @brief  设置驱动刹车
  * @param  NULL
  * @retval NULL
  */
void REIN_HW_Elec_SetBrake(void)
{
	coil_a.dac_reg = 0;
	coil_b.dac_reg = 0;
	CurrentControl_VREF_12Bit_MixOut(coil_a.dac_reg, coil_b.dac_reg);
	Out_AP_H();	Out_AM_H();
	Out_BP_H();	Out_BM_H();
}

/**
  * @brief  设置输出细分电流
  * @param  divide:  细分 (0 ~ 细分数)
  * @param  dac_reg: 电流 (0 ~ 3300mA)
  * @retval NULL
  */
void REIN_HW_Elec_SetDivideElec(uint32_t divide, int32_t elec_ma)
{
	//由细分数获得数组指针
	coil_b.conver = (divide) & (0x000003FF);								//对1024取余
	coil_a.conver = (coil_b.conver + (256)) & (0x000003FF);	//对1024取余
	
	//由数据指针获得整形数据(空间换时间方案)
	coil_a.sin_data = sin_pi_m2[coil_a.conver];
	coil_b.sin_data = sin_pi_m2[coil_b.conver];

	//由整形数据获得DAC寄存器数据
	uint32_t dac_reg = abs(elec_ma);								//电压电流关系为1:1(检流电阻为0.1欧)
	dac_reg = (uint32_t)(dac_reg * 5083) >> 12; 		//(dac_reg * 4095 / 3300)的变种
	dac_reg = dac_reg & (0x00000FFF);								//(对4096取余)(向小取整)(舍弃符号位)
	coil_a.dac_reg = (uint32_t)(dac_reg * abs(coil_a.sin_data)) >> sin_pi_m2_dpiybit;	//(--- / sin_1024_dpiy)的变种
	coil_b.dac_reg = (uint32_t)(dac_reg * abs(coil_b.sin_data)) >> sin_pi_m2_dpiybit;	//(--- / sin_1024_dpiy)的变种

	//DAC输出
	CurrentControl_VREF_12Bit_MixOut(coil_a.dac_reg, coil_b.dac_reg);
	if(coil_a.sin_data > 0)				{	Out_AP_H();		Out_AM_L();		}
	else if(coil_a.sin_data < 0)	{	Out_AP_L();		Out_AM_H();		}
	else 													{	Out_AP_H();		Out_AM_H();		}
	if(coil_b.sin_data > 0)				{	Out_BP_H();		Out_BM_L();		}
	else if(coil_b.sin_data < 0)	{	Out_BP_L();		Out_BM_H();		}
	else													{	Out_BP_H();		Out_BM_H();		}
}
