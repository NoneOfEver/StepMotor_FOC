/******
	************************************************************************
	******
	** @project : XDrive_Step
	** @brief   : Stepper motor with multi-function interface and closed loop function. 
	** @brief   : ���ж๦�ܽӿںͱջ����ܵĲ������
	** @author  : unlir (֪��֪��)
	** @contacts: QQ.1354077136
	******
	** @address : https://github.com/unlir/XDrive
	******
	************************************************************************
	******
	** {Stepper motor with multi-function interface and closed loop function.}
	** Copyright (c) {2020}  {unlir(֪��֪��)}
	** 
	** This program is free software: you can redistribute it and/or modify
	** it under the terms of the GNU General Public License as published by
	** the Free Software Foundation, either version 3 of the License, or
	** (at your option) any later version.
	** 
	** This program is distributed in the hope that it will be useful,
	** but WITHOUT ANY WARRANTY; without even the implied warranty of
	** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	** GNU General Public License for more details.
	** 
	** You should have received a copy of the GNU General Public License
	** along with this program.  If not, see <http://www.gnu.org/licenses/>.
	******
	************************************************************************
******/

/*****
  ** @file     : Current_Tracker.c/h
  ** @brief    : ����������
  ** @versions : 1.1.7
  ** @time     : 2019/12/06
  ** @reviser  : unli (JiXi XuanCheng China)
  ** @explain  : null
*****/

#ifndef CURRENT_TRACKER_H
#define CURRENT_TRACKER_H

#ifdef __cplusplus
extern "C" {
#endif

//���ö˿ڶ���
#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"

/****************************************  ����������  ****************************************/
/****************************************  ����������  ****************************************/
/****************************************  ����������  ****************************************/
/**
  * Electric_Tracker��ṹ�嶨��
**/
typedef struct{
	//����(�������ݶ�)
	#define	De_Up_Rate		(Move_Rated_UpCurrentRate / 10)
	bool		valid_up_rate;
	int32_t	up_rate;
	//����(�����ݶ�)
	#define	De_Down_Rate	(Move_Rated_DownCurrentRate / 10)
	bool		valid_down_rate;
	int32_t	down_rate;
	//�����������
	int32_t	course_mut;	//��������еĵ���(С��������)(�Ŵ�ΪCONTROL_FREQ_HZ��)
	int32_t	course;			//��������еĵ���(�����)
	//���������
	int32_t	go_current;	//��������
}Current_Tracker_Typedef;
extern Current_Tracker_Typedef	current_tck;

void Current_Tracker_Set_UpRate(int32_t value);		//�������������������仯��
void Current_Tracker_Set_DownRate(int32_t value);	//�������������ü����仯��
void Current_Tracker_Set_Default(void);						//���������������ָ�

void Current_Tracker_Init(void);													//������������ʼ��
void Current_Tracker_NewTask(int16_t real_current);				//������������ʼ������
void Current_Tracker_Capture_Goal(int32_t goal_current);	//���������������������

#ifdef __cplusplus
}
#endif

#endif //ELECTRIC_TRACKER_H
