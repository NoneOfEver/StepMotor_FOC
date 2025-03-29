#ifndef SPEED_TRACKER_H
#define SPEED_TRACKER_H

#ifdef __cplusplus
extern "C" {
#endif

//引用端口定义
#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"
/****************************************  速度跟踪器  ****************************************/
/****************************************  速度跟踪器  ****************************************/
/****************************************  速度跟踪器  ****************************************/
/**
  * Speed_Tracker类结构体定义
**/
typedef struct{
	//配置(加速加速度)
	#define	DE_UP_ACC			(Move_Rated_UpAcc / 10)
	bool		valid_up_acc;
	int32_t	up_acc;
	//配置(减速加速度)
	#define	DE_DOWN_ACC		(Move_Rated_DownAcc / 10)
	bool		valid_down_acc;
	int32_t	down_acc;
	//计算过程数据
	int32_t		course_mut;	//过程加速度积分(放大CONTROL_FREQ_HZ倍)
	int32_t		course;			//过程速度
	//输出跟踪量
	int32_t		go_speed;		//立即速度
}Speed_Tracker_Typedef;
extern Speed_Tracker_Typedef	speed_tck;

void Speed_Tracker_Set_UpAcc(int32_t value);		//速度跟踪器设置加速加速度
void Speed_Tracker_Set_DownAcc(int32_t value);	//速度跟踪器设置减速加速度
void Speed_Tracker_Set_Default(void);						//速度跟踪器参数恢复

void Speed_Tracker_Init(void);												//速度跟踪器初始化
void Speed_Tracker_NewTask(int32_t real_speed);				//速度控制器开始新任务
void Speed_Tracker_Capture_Goal(int32_t goal_speed);	//速度跟踪器获得立即速度

#ifdef __cplusplus
}
#endif

#endif //SPEED_TRACKER_H
