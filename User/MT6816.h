#ifndef MT6816_H
#define MT6816_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ch32v20x.h"
#include "stdbool.h"

/****************************************  校准器配置区  ****************************************/
#define CALI_Encode_Bit					((int32_t)(14))																//(编码器位宽)(14位输出精度)
#define CALI_Encode_Res					((int32_t)((0x00000001U) << CALI_Encode_Bit))	//(编码器分辨率)(2^14 = 16384)(16k分辨率)(占用32k校准空间)
#define CALI_Gather_Encode_Res	((int32_t)(CALI_Encode_Res / Move_Step_NUM))	//(校准每采集步编码器分辨率)

#define	STOCKPILE_APP_CALI_ADDR					(0x08017C00)		//起始地址
#define	STOCKPILE_APP_CALI_SIZE					(0x00008000)		//Flash容量    32K    XDrive(APP_CALI)(可容纳16K-2byte校准数据-即最大支持14位编码器的校准数据)
#define Stockpile_Page_Size						0x100U				//扇区大小(默认256字节)
/********** MT6816_SPI **********/
typedef struct{
	//采集数据
	uint16_t	sample_data;	//SPI读取到的数据
	//输出数据
	uint16_t	angle;				//SPI输出的角度
	bool			no_mag_flag;	//磁铁数据有效标志
	bool			pc_flag;			//奇偶校验位
}MT6816_SPI_Signal_Typedef;

//MT6816_SPI
void REIN_MT6816_SPI_Signal_Init(void);		//MT6816_SPI采集初始化
void RINE_MT6816_SPI_Get_AngleData(void);	//MT6816_SPI采集获取角度数据

#endif

/********** MT6816 **********/
typedef struct{
	uint16_t	angle_data;				//角度数据
	uint16_t	rectify_angle;		//校准的角度数据
	bool			rectify_valid;		//校准数据有效标志
}MT6816_Typedef;
extern MT6816_Typedef	mt6816;

//MT6816
void REIN_MT6816_Init(void);							//MT6816初始化
void REIN_MT6816_Get_AngleData(void);			//MT6816获取角度数据

#ifdef __cplusplus
}
	 
#endif
