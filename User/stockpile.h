#ifndef STOCKPILE_H
#define STOCKPILE_H

#ifdef __cplusplus
extern "C" {
#endif

//Ӧ�ô洢����
#include "stockpile_config.h"
#include "ch32v20x.h"
/*************************************************************** FLASH_Start ***************************************************************/
/*************************************************************** FLASH_Start ***************************************************************/
/*************************************************************** FLASH_Start ***************************************************************/
/******************ҳ����(����оƬ�����޸��������)***********************/
#define Stockpile_Page_Size		0x400U		//������С(Ĭ��1024�ֽ�)
#if (Stockpile_Page_Size != FLASH_PAGE_SIZE)	//��HAL���ȡ��Flashҳ��С�Ƚ�,��������Ƿ���Ч	
#endif

/**
* Flash������ṹ��
**/
typedef struct{
	//����
	uint32_t	begin_add;			//��ʼ��ַ
	uint32_t	area_size;			//�����С
	uint32_t	page_num;				//оƬʵ��ҳ����
	//������
	uint32_t	asce_write_add;	//д��ַ
}Stockpile_FLASH_Typedef;

/********** Flash������ʵ�� **********/
extern Stockpile_FLASH_Typedef stockpile_app_firmware;
extern Stockpile_FLASH_Typedef stockpile_quick_cali;
extern Stockpile_FLASH_Typedef stockpile_data;

void Stockpile_Flash_Data_Empty(Stockpile_FLASH_Typedef *stockpile);			//Flash�������
void Stockpile_Flash_Data_Begin(Stockpile_FLASH_Typedef *stockpile);			//Flash���ݿ�ʼд��
void Stockpile_Flash_Data_End(Stockpile_FLASH_Typedef *stockpile);				//Flash���ݽ���д��
void Stockpile_Flash_Data_Set_Write_Add(Stockpile_FLASH_Typedef *stockpile, uint32_t write_add);					//Flash����д��ַ
void Stockpile_Flash_Data_Write_Data16(Stockpile_FLASH_Typedef *stockpile, uint16_t *data, uint32_t num);	//Flash_16λ����д��
void Stockpile_Flash_Data_Write_Data32(Stockpile_FLASH_Typedef *stockpile, uint32_t *data, uint32_t num);	//Flash_32λ����д��
void Stockpile_Flash_Data_Write_Data64(Stockpile_FLASH_Typedef *stockpile, uint64_t *data, uint32_t num);	//Flash_64λ����д��

/*************************************************************** FLASH_End ***************************************************************/
/*************************************************************** FLASH_End ***************************************************************/
/*************************************************************** FLASH_End ***************************************************************/

#ifdef __cplusplus
}
#endif

#endif
