#include "MT6816.h"
#include "SPI.h"


//��������������λ��(Quick)(Flash)
uint16_t *Read_QuickCali_DATA = (uint16_t*)STOCKPILE_APP_CALI_ADDR;

//GPIO���
#define MT6816_SPI_CS_H()		GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET)
#define MT6816_SPI_CS_L()		GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET)

/****************************** MT6816_SPI ******************************/
MT6816_SPI_Signal_Typedef	mt6816_spi;

/**
  * @brief  MT6816_SPI�ɼ���ʼ��
  * @param  NULL
  * @retval NULL
**/
void REIN_MT6816_SPI_Signal_Init(void)
{
	//�ɼ�����
	mt6816_spi.sample_data = 0;
	//�������
	mt6816_spi.angle = 0;
	//��������
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//CS
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    //spi2
    SPI_FullDuplex_Init();
}

/**
  * @brief  MT6816_SPI�ɼ���ȡ�Ƕ�����
  * @param  NULL
  * @retval NULL
**/
void RINE_MT6816_SPI_Get_AngleData(void)
{
	uint16_t data_t[2];
	uint16_t data_r[2];
	uint8_t h_count;
	
	data_t[0] = (0x80 | 0x03) << 8;
	data_t[1] = (0x80 | 0x04) << 8;
	
	for(uint8_t i=0; i<3; i++){
		//��ȡSPI����
		MT6816_SPI_CS_L();
        SPI_I2S_SendData(SPI2,data_t[0]);
        data_r[0] = SPI_I2S_ReceiveData(SPI2);
		MT6816_SPI_CS_H();
		MT6816_SPI_CS_L();
        SPI_I2S_SendData(SPI2,data_t[1]);
        data_r[1] = SPI_I2S_ReceiveData(SPI2);
		MT6816_SPI_CS_H();
		mt6816_spi.sample_data = ((data_r[0] & 0x00FF) << 8) | (data_r[1] & 0x00FF);
		
		//��żУ��
		h_count = 0;
		for(uint8_t j=0; j<16; j++){
			if(mt6816_spi.sample_data & (0x0001 << j))
				h_count++;
		}
		if(h_count & 0x01){
			mt6816_spi.pc_flag = false;
		}
		else{
			mt6816_spi.pc_flag = true;
			break;
		}
	}
	
	if(mt6816_spi.pc_flag){
		mt6816_spi.angle = mt6816_spi.sample_data >> 2;
		mt6816_spi.no_mag_flag = (bool)(mt6816_spi.sample_data & (0x0001 << 1));
	}
}


/****************************** MT6816 ******************************/
MT6816_Typedef	mt6816;

/**
  * @brief  MT6816��ʼ��
  * @param  NULL
  * @retval NULL
**/
void REIN_MT6816_Init(void)
{
	REIN_MT6816_SPI_Signal_Init();		//��ʼ��SPI�ӿ�

	//��ʼ���׶λ�ȡһ�νǶ�����(���˴�������)(��δ������λ���һ�ζ�ȡ���ݶ�ʧ��ԭ��)
	REIN_MT6816_Get_AngleData();
	
	//���У׼�������Ƿ���Ч
	mt6816.rectify_valid = true;
	for(uint16_t i=0; i<(CALI_Encode_Res); i++){
		if(Read_QuickCali_DATA[i] == 0xFFFF)
			mt6816.rectify_valid = false;
	}
}

/**
  * @brief  MT6816��ȡ�Ƕ�����
  * @param  NULL
  * @retval NULL
**/
void REIN_MT6816_Get_AngleData(void)
{
	RINE_MT6816_SPI_Get_AngleData();
	mt6816.angle_data = mt6816_spi.angle;
	mt6816.rectify_angle = Read_QuickCali_DATA[mt6816.angle_data];
}


















