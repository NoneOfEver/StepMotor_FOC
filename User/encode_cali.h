#ifndef ENCODE_CALI_H
#define ENCODE_CALI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ch32v20x.h"
#include "stdbool.h"
#include "stdlib.h"
//���õ������
#include "control_config.h"
//У׼���ݼ�鱨��
typedef enum{
	//�޴���
	CALI_No_Error = 0x00,						//�����޴���
	//ԭʼ���ݳ���
	CALI_Error_Average_Dir,					//ƽ��ֵ�������
	CALI_Error_Average_Continuity,	//ƽ��ֵ�����Դ���
	CALI_Error_PhaseStep,						//��Ծ��������
	//�������ݳ���
	CALI_Error_Analysis_Quantity,		//��������������
}CALI_Error;

//У׼״̬
typedef enum{
	CALI_Disable = 0x00,						//ʧ��
	CALI_Forward_Encoder_AutoCali,	//��������ת�Զ�У׼
	CALI_Forward_Measure,						//�������
	CALI_Reverse_Ret,								//�������
	CALI_Reverse_Gap,								//��������
	CALI_Reverse_Measure,						//�������
	CALI_Operation,									//����
}CALI_State;

/**
  * ControlУ׼�ṹ�嶨��
**/
typedef struct{
	//�ź�
	bool				trigger;			//����У׼
	CALI_Error	error_code;		//У׼�������
	uint32_t		error_data;		//У׼��������
	//��ȡ����
	CALI_State	state;					//У׼״̬
	uint32_t		out_location;		//���λ��
	#define			Gather_Quantity	16	//ÿ���ɼ���ɼ�����
	uint16_t		gather_count;												//�ɼ�����
	uint16_t		coder_data_gather[Gather_Quantity];	//�ɼ���ÿ������
	uint16_t 		coder_data_f[Move_Step_NUM+1];	//У׼��ȡ������
	uint16_t 		coder_data_r[Move_Step_NUM+1];	//У׼��ȡ������
	bool				dir;		//У׼���ݷ���
	//ȫ����У׼��������
	int32_t		rcd_x, rcd_y;			//Ѱ�������±꼰��Ծ��ֵ
	uint32_t	result_num;				//ͳ������
}Encode_Cali_Typedef;
extern Encode_Cali_Typedef encode_cali;

void Calibration_Init(void);								//У׼����ʼ��
void Calibration_Interrupt_Callback(void);	//У׼���жϻص�(�ȶ��жϵ���)
void Calibration_Loop_Callback(void);				//У׼��������ص�(���жϵ���)

#ifdef __cplusplus
}
#endif

#endif
