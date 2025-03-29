#ifndef MT6816_H
#define MT6816_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ch32v20x.h"
#include "stdbool.h"

/****************************************  У׼��������  ****************************************/
#define CALI_Encode_Bit					((int32_t)(14))																//(������λ��)(14λ�������)
#define CALI_Encode_Res					((int32_t)((0x00000001U) << CALI_Encode_Bit))	//(�������ֱ���)(2^14 = 16384)(16k�ֱ���)(ռ��32kУ׼�ռ�)
#define CALI_Gather_Encode_Res	((int32_t)(CALI_Encode_Res / Move_Step_NUM))	//(У׼ÿ�ɼ����������ֱ���)

#define	STOCKPILE_APP_CALI_ADDR					(0x08017C00)		//��ʼ��ַ
#define	STOCKPILE_APP_CALI_SIZE					(0x00008000)		//Flash����    32K    XDrive(APP_CALI)(������16K-2byteУ׼����-�����֧��14λ��������У׼����)
#define Stockpile_Page_Size						0x100U				//������С(Ĭ��256�ֽ�)
/********** MT6816_SPI **********/
typedef struct{
	//�ɼ�����
	uint16_t	sample_data;	//SPI��ȡ��������
	//�������
	uint16_t	angle;				//SPI����ĽǶ�
	bool			no_mag_flag;	//����������Ч��־
	bool			pc_flag;			//��żУ��λ
}MT6816_SPI_Signal_Typedef;

//MT6816_SPI
void REIN_MT6816_SPI_Signal_Init(void);		//MT6816_SPI�ɼ���ʼ��
void RINE_MT6816_SPI_Get_AngleData(void);	//MT6816_SPI�ɼ���ȡ�Ƕ�����

#endif

/********** MT6816 **********/
typedef struct{
	uint16_t	angle_data;				//�Ƕ�����
	uint16_t	rectify_angle;		//У׼�ĽǶ�����
	bool			rectify_valid;		//У׼������Ч��־
}MT6816_Typedef;
extern MT6816_Typedef	mt6816;

//MT6816
void REIN_MT6816_Init(void);							//MT6816��ʼ��
void REIN_MT6816_Get_AngleData(void);			//MT6816��ȡ�Ƕ�����

#ifdef __cplusplus
}
	 
#endif
