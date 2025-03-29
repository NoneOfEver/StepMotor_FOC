#ifndef MOVE_RECONSTRUCT_H
#define MOVE_RECONSTRUCT_H

#ifdef __cplusplus
extern "C" {
#endif

//���ö˿ڶ���
#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"

/****************************************  �˶��ع���  ****************************************/
/****************************************  �˶��ع���  ****************************************/
/****************************************  �˶��ع���  ****************************************/
//�ع�������
#define Reconstruct_Max_OverTime		((uint16_t)(50000))
#define Reconstruct_Min_OverTime		((uint16_t)(50))

/**
  * Move_Reconstruct��ṹ�嶨��
**/
typedef struct{
	//����(���ټ��ٶ�)
	#define	DE_DOWN_ACC		(Move_Rated_DownAcc / 10)
	bool		valid_down_acc;
	int32_t	down_acc;
	//����(��ʱʱ��ms)
	#define	DE_OverTime		(200)
	bool		valid_overtime;
	uint16_t	overtime;
	//��̬���ٲ���
	int32_t		dyn_speed_acc;			//��̬���ٶ�
	//Դ�źż�¼
	int32_t		record_timer;			//�ź�Դ��ʱ��
	bool		overtime_flag;			//��ʱ��־
	int32_t		record_speed;			//��¼���ٶ�
	int32_t		record_location;		//��¼��λ��
	//�����������
	int32_t		speed_course_dec;		//��������е��ٶ�(С�ٶȻ���)(�Ŵ�ΪCONTROL_FREQ_HZ��)
	int32_t		speed_course;			//��������е��ٶ�(���ٶ�)
	int32_t		location_course_dec;	//��������е�λ��(Сλ�ƻ���)(�Ŵ�ΪCONTROL_FREQ_HZ��)
	int32_t		location_course;		//��������е�λ��(��λ��)
	//������ٿ�����
	int32_t		go_location;			//����λ��
	int32_t		go_speed;				//�����ٶ�
}Move_Reconstruct_Typedef;
extern Move_Reconstruct_Typedef move_reco;

void Move_Reconstruct_Set_DownAcc(int32_t value);		//�˶��ع������ü��ټ��ٶ�
void Move_Reconstruct_Set_OverTime(uint16_t value);	//�˶��ع������ó�ʱʱ��
void Move_Reconstruct_Set_Default(void);						//�˶��ع��������ָ�

void Move_Reconstruct_Init(void);																							//�˶��ع�����ʼ��
void Move_Reconstruct_NewTask(int32_t real_location, int32_t real_speed);			//�˶��ع�����ʼ������
void Move_Reconstruct_Capture_Goal(int32_t goal_location, int32_t goal_speed);//�˶��ع����������λ�ú������ٶ�

#ifdef __cplusplus
}
#endif

#endif




