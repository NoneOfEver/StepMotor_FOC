/*************************************************************** Stockpile_Start ***************************************************************/
/*********************STM32F103xx*************************/
//�����������
//Flash Size(bytes)/RAM size(bytes)
// ������   1M / 96K                                     RG               VG           ZG
// ������ 768K / 96K                                     RF               VF           ZF
// ������ 512K / 64K                                     RE               VE           ZE
// ������ 384K / 64K                                     RD               VD           ZD
// ������ 256K / 48K                                     RC               VC           ZC
// ������ 128K / 20K      TB           CB                RB               VB
// ������  64K / 20K      T8           C8                R8               V8
// С����  32K / 10K      T6           C6                R6
// С����  16K /  6K      T4           C4                R4
//        						 36pin-QFN	48pin-LQFP/QFN	64pin-BGA/CSP/LQFP  100pin-LQFP  144pin-BGA/LQFP  
/*************************************************************** Stockpile_End ***************************************************************/
/*************************************************************** Stockpile_End ***************************************************************/
/*************************************************************** Stockpile_End ***************************************************************/

#ifndef STOCKPILE_CONFIG_H
#define STOCKPILE_CONFIG_H

/* ROM sizes */
/* ROM sizes */
/* ROM sizes */

//DAPLINK_ROM_BL
#define		DAPLINK_ROM_BL_START						(0x08000000)		//��ʼ��ַ
#define		DAPLINK_ROM_BL_SIZE							(0x0000BC00)		//Flash����    47K		DAPLink_BL(DAPLINK_ROM_BL)
//DAPLINK_ROM_CONFIG_ADMIN
#define		DAPLINK_ROM_CONFIG_ADMIN_START	(0x0800BC00)		//��ʼ��ַ
#define		DAPLINK_ROM_CONFIG_ADMIN_SIZE		(0x00000400)		//Flash����     1K		DAPLink_BL(DAPLINK_ROM_CONFIG_ADMIN)
//APP_FIRMWARE
#define		STOCKPILE_APP_FIRMWARE_ADDR			(0x0800C000)		//��ʼ��ַ
#define		STOCKPILE_APP_FIRMWARE_SIZE			(0x0000BC00)		//Flash����    47K    XDrive(APP_FIRMWARE)
//APP_CALI
#define		STOCKPILE_APP_CALI_ADDR					(0x08017C00)		//��ʼ��ַ
#define		STOCKPILE_APP_CALI_SIZE					(0x00008000)		//Flash����    32K    XDrive(APP_CALI)(������16K-2byteУ׼����-�����֧��14λ��������У׼����)
//APP_DATA
#define		STOCKPILE_APP_DATA_ADDR					(0x0801FC00)		//��ʼ��ַ
#define		STOCKPILE_APP_DATA_SIZE					(0x00000400)		//Flash����     1K    XDrive(APP_DATA)

/* RAM sizes */
/* RAM sizes */
/* RAM sizes */

#define STOCKPILE_RAM_APP_START           (0x20000000)
#define STOCKPILE_RAM_APP_SIZE            (0x00004F00)		//19K768�ֽ�

#define STOCKPILE_RAM_SHARED_START        (0x20004F00)
#define STOCKPILE_RAM_SHARED_SIZE         (0x00000100)		//256�ֽ�

#endif
