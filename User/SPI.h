#include "ch32v20x.h"

/* SPI Mode Definition */
#define HOST_MODE     0
#define SLAVE_MODE    1

/* SPI Communication Mode Selection */
#define SPI_MODE   HOST_MODE
//#define SPI_MODE      SLAVE_MODE

/* Global define */
#define SPI_BUFFER_SIZE          18

/* Global Variable */
extern u16 TxData[SPI_BUFFER_SIZE];
extern u16 RxData[SPI_BUFFER_SIZE];

void SPI_FullDuplex_Init(void);
