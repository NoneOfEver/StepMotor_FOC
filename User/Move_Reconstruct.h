#ifndef MOVE_RECONSTRUCT_H
#define MOVE_RECONSTRUCT_H

#ifdef __cplusplus
extern "C" {
#endif

//引用端口定义
#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"

/****************************************  运动重构器  ****************************************/
/****************************************  运动重构器  ****************************************/
/****************************************  运动重构器  ****************************************/
//重构器配置
#define Reconstruct_Max_OverTime		((uint16_t)(50000))
#define Reconstruct_Min_OverTime		((uint16_t)(50))

/**
  * Move_Reconstruct类结构体定义
**/
typedef struct{
	//配置(减速加速度)
	#define	DE_DOWN_ACC		(Move_Rated_DownAcc / 10)
	bool		valid_down_acc;
	int32_t	down_acc;
	//配置(超时时间ms)
	#define	DE_OverTime		(200)
	bool		valid_overtime;
	uint16_t	overtime;
	//动态跟踪参数
	int32_t		dyn_speed_acc;			//动态加速度
	//源信号记录
	int32_t		record_timer;			//信号源计时器
	bool		overtime_flag;			//超时标志
	int32_t		record_speed;			//记录的速度
	int32_t		record_location;		//记录的位置
	//计算过程数据
	int32_t		speed_course_dec;		//计算过程中的速度(小速度积分)(放大为CONTROL_FREQ_HZ倍)
	int32_t		speed_course;			//计算过程中的速度(大速度)
	int32_t		location_course_dec;	//计算过程中的位置(小位移积分)(放大为CONTROL_FREQ_HZ倍)
	int32_t		location_course;		//计算过程中的位置(大位移)
	//输出跟踪控制量
	int32_t		go_location;			//立即位置
	int32_t		go_speed;				//立即速度
}Move_Reconstruct_Typedef;
extern Move_Reconstruct_Typedef move_reco;

void Move_Reconstruct_Set_DownAcc(int32_t value);		//运动重构器设置减速加速度
void Move_Reconstruct_Set_OverTime(uint16_t value);	//运动重构器设置超时时间
void Move_Reconstruct_Set_Default(void);						//运动重构器参数恢复

void Move_Reconstruct_Init(void);																							//运动重构器初始化
void Move_Reconstruct_NewTask(int32_t real_location, int32_t real_speed);			//运动重构器开始新任务
void Move_Reconstruct_Capture_Goal(int32_t goal_location, int32_t goal_speed);//运动重构器获得立即位置和立即速度

#ifdef __cplusplus
}
#endif

#endif




