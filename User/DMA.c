#include "DMA.h"
#include "SPI.h"
#include "ADC.h"
/*********************************************************************
 * @fn      DMA_Tx_Init
 *
 * @brief   Initializes the DMAy Channelx configuration.
 *
 * @param   DMA_CHx - x can be 1 to 7.
 *          ppadr - Peripheral base address.
 *          memadr - Memory base address.
 *          bufsize - DMA channel buffer size.
 *
 * @return  none
 */
void DMA_Tx_Init()
{
    //ADC DMA configuration
    DMA_InitTypeDef DMA_ADC_InitStructure = {0};

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    DMA_DeInit(DMA1_Channel8);
    DMA_ADC_InitStructure.DMA_PeripheralBaseAddr = (u32)&ADC1->RDATAR;
    DMA_ADC_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&whole_adc_data[0][0];
    DMA_ADC_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_ADC_InitStructure.DMA_BufferSize = 2;
    DMA_ADC_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_ADC_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_ADC_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_ADC_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_ADC_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_ADC_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
    DMA_ADC_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel8, &DMA_ADC_InitStructure);

    //SPI_TX DMA configuration
    DMA_InitTypeDef DMA_SPI_TX_InitStructure = {0};

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    DMA_DeInit(DMA1_Channel3);

    DMA_SPI_TX_InitStructure.DMA_PeripheralBaseAddr = (u32)&SPI1->DATAR;
    DMA_SPI_TX_InitStructure.DMA_MemoryBaseAddr =  (u32)TxData;
    DMA_SPI_TX_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_SPI_TX_InitStructure.DMA_BufferSize = SPI_BUFFER_SIZE;
    DMA_SPI_TX_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_SPI_TX_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_SPI_TX_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_SPI_TX_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_SPI_TX_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_SPI_TX_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
    DMA_SPI_TX_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel3, &DMA_SPI_TX_InitStructure);

}


/*********************************************************************
 * @fn      DMA_Rx_Init
 *
 * @brief   Initializes the SPI1 DMA Channelx configuration.
 *
 * @param   DMA_CHx - x can be 1 to 7.
 *          ppadr - Peripheral base address.
 *          memadr - Memory base address.
 *          bufsize - DMA channel buffer size.
 *
 * @return  none
 */
void DMA_Rx_Init()
{
    //SPI_RX DMA configuration
    DMA_InitTypeDef DMA_SPI_RX_InitStructure = {0};

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    DMA_DeInit(DMA1_Channel2);

    DMA_SPI_RX_InitStructure.DMA_PeripheralBaseAddr = (u32)&SPI1->DATAR;
    DMA_SPI_RX_InitStructure.DMA_MemoryBaseAddr = (u32)RxData;
    DMA_SPI_RX_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_SPI_RX_InitStructure.DMA_BufferSize = SPI_BUFFER_SIZE;
    DMA_SPI_RX_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_SPI_RX_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_SPI_RX_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_SPI_RX_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_SPI_RX_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_SPI_RX_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_SPI_RX_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel2, &DMA_SPI_RX_InitStructure);
}
