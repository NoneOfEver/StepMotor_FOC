#include "stockpile.h"

////LL_Driver
//#include "stm32f0xx_ll_flash_ex.h"

////LL��FLASH�������
//extern void FLASH_PageErase(uint32_t PageAddress);

/*************************************************************** Flash_Start ***************************************************************/
/*************************************************************** Flash_Start ***************************************************************/
/*************************************************************** Flash_Start ***************************************************************/
//Flash������ʵ��
Stockpile_FLASH_Typedef	stockpile_app_firmware	= {STOCKPILE_APP_FIRMWARE_ADDR, STOCKPILE_APP_FIRMWARE_SIZE,	(STOCKPILE_APP_FIRMWARE_SIZE / Stockpile_Page_Size),	0};
Stockpile_FLASH_Typedef	stockpile_quick_cali		= {STOCKPILE_APP_CALI_ADDR, 		STOCKPILE_APP_CALI_SIZE,			(STOCKPILE_APP_CALI_SIZE / Stockpile_Page_Size),			0};
Stockpile_FLASH_Typedef stockpile_data					= {STOCKPILE_APP_DATA_ADDR,			STOCKPILE_APP_DATA_SIZE, 			(STOCKPILE_APP_DATA_SIZE / Stockpile_Page_Size),			0};

/**
  * @brief  Flash�������
  * @param  stockpile	Flash������ʵ��
  * @retval NULL
**/
void Stockpile_Flash_Data_Empty(Stockpile_FLASH_Typedef *stockpile)
{
	uint32_t count;
	HAL_FLASH_Unlock();	//LL_FLASH_Unlock();
	for(count = 0; count < stockpile->page_num; count++)
	{
		FLASH_EraseInitTypeDef erase_config;
		uint32_t page_error;
		erase_config.TypeErase   = FLASH_TYPEERASE_PAGES;																	//ҳ����		
		erase_config.PageAddress = stockpile->begin_add + (count * Stockpile_Page_Size);	//ҳ��ʼ��ַ
		erase_config.NbPages     = 1;																											//����ҳ����
		HAL_FLASHEx_Erase(&erase_config, &page_error);
		FLASH_WaitForLastOperation(HAL_MAX_DELAY);
		CLEAR_BIT(FLASH->CR, FLASH_CR_PER);
	}
	HAL_FLASH_Lock();	//LL_FLASH_Lock();
}

/**
  * @brief  Flash���ݿ�ʼд��
  * @param  stockpile	Flash������ʵ��
  * @retval NULL
**/
void Stockpile_Flash_Data_Begin(Stockpile_FLASH_Typedef *stockpile)
{
	HAL_FLASH_Unlock();	//LL_FLASH_Unlock();
	stockpile->asce_write_add = stockpile->begin_add;
}

/**
  * @brief  Flash���ݽ���д��
  * @param  stockpile	Flash������ʵ��
  * @retval NULL
**/
void Stockpile_Flash_Data_End(Stockpile_FLASH_Typedef *stockpile)
{
	HAL_FLASH_Lock();	//LL_FLASH_Lock();
}

/**
  * @brief  Flash����д��ַ
  * @param  stockpile	Flash������ʵ��
  * @param  write_add	д��ַ
  * @retval NULL
**/
void Stockpile_Flash_Data_Set_Write_Add(Stockpile_FLASH_Typedef *stockpile, uint32_t write_add)
{
	if(write_add < stockpile->begin_add)						return;
	if(write_add > stockpile->begin_add + stockpile->area_size)	return;
	stockpile->asce_write_add = write_add;
}

/**
  * @brief  Flash_16λ����д��
  * @param  stockpile	Flash������ʵ��
  * @param  data		�������ݻ�����
  * @param  num			��������
  * @retval NULL
**/
void Stockpile_Flash_Data_Write_Data16(Stockpile_FLASH_Typedef *stockpile, uint16_t *data, uint32_t num)
{
	if(stockpile->asce_write_add < stockpile->begin_add)									return;
	if((stockpile->asce_write_add + num * 2) > stockpile->begin_add + stockpile->area_size)	return;
	
	for(uint32_t i=0; i<num; i++)
	{
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, stockpile->asce_write_add, (uint64_t)data[i]) == HAL_OK)
			stockpile->asce_write_add += 2;
	}
}

/**
  * @brief  Flash_32λ����д��
  * @param  stockpile	Flash������ʵ��
  * @param  data		�����ݻ�����
  * @param  num			������
  * @retval NULL
**/
void Stockpile_Flash_Data_Write_Data32(Stockpile_FLASH_Typedef *stockpile, uint32_t *data, uint32_t num)
{
	if(stockpile->asce_write_add < stockpile->begin_add)									return;
	if((stockpile->asce_write_add + num * 4) > stockpile->begin_add + stockpile->area_size)	return;
	
	for(uint32_t i=0; i<num; i++)
	{
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, stockpile->asce_write_add, (uint64_t)data[i]) == HAL_OK)
			stockpile->asce_write_add += 4;
	}
}

/**
  * @brief  Flash_64λ����д��
  * @param  stockpile	Flash������ʵ��
  * @param  data		˫�����ݻ�����
  * @param  num			˫������
  * @retval NULL
**/
void Stockpile_Flash_Data_Write_Data64(Stockpile_FLASH_Typedef *stockpile, uint64_t *data, uint32_t num)
{
	if(stockpile->asce_write_add < stockpile->begin_add)									return;
	if((stockpile->asce_write_add + num * 8) > stockpile->begin_add + stockpile->area_size)	return;
	
	for(uint32_t i=0; i<num; i++)
	{
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, stockpile->asce_write_add, (uint64_t)data[i]) == HAL_OK)
			stockpile->asce_write_add += 8;
	}
}
/*************************************************************** Flash_End ***************************************************************/
/*************************************************************** Flash_End ***************************************************************/
/*************************************************************** Flash_End ***************************************************************/

