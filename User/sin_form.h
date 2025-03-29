#ifndef SIN_FORM_H
#define SIN_FORM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

////sin_pi_d2 (��Ӧԭʼsin����ͼ��0~pi/2)
//#define sin_pi_d2_dpix			256		//ˮƽ�ֱ���
//#define sin_pi_d2_dpiybit		12		//��ֱ�ֱ���λ��(4096)
//extern const int16_t sin_pi_d2[sin_pi_d2_dpix + 1];

//sin_pi_m2 (��Ӧԭʼsin����ͼ��0~pi*2)
#define sin_pi_m2_dpix			1024	//ˮƽ�ֱ���
#define sin_pi_m2_dpiybit		12		//��ֱ�ֱ���λ��(4096)
extern const int16_t sin_pi_m2[sin_pi_m2_dpix + 1];

#ifdef __cplusplus
}
#endif
	 
#endif	//SIN_FORM_H
