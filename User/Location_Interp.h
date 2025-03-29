#ifndef LOCATION_INTERP_H
#define LOCATION_INTERP_H

#ifdef __cplusplus
extern "C" {
#endif

//引用端口定义
#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"

/****************************************  位置补插器(不带细分增强)  ****************************************/
/****************************************  位置补插器(不带细分增强)  ****************************************/
/****************************************  位置补插器(不带细分增强)  ****************************************/
/**
  * Location_Interp类结构体定义
**/
typedef struct{
	//源信号数据
	int32_t		record_location;				//记录的位置
	int32_t		record_location_last;		//记录的位置
	int32_t		est_location;						//估计的位置
	int32_t		est_speed_mut;					//估计速度倍值(放大n倍)
	int32_t		est_speed;							//估计的速度

	//输出跟踪控制量
	int32_t		go_location;		//立即位置
	int32_t		go_speed;				//立即速度
}Location_Interp_Typedef;
extern Location_Interp_Typedef location_interp;

void Location_Interp_Init(void);																					//位置补插器初始化
void Location_Interp_NewTask(int32_t real_location, int32_t real_speed);	//位置补插器开始新任务
void Location_Interp_Capture_Goal(int32_t goal_location);									//位置补插器获得立即位置和立即速度

#ifdef __cplusplus
}
#endif

#endif









