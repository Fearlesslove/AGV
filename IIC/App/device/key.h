#ifndef __KEY_H_
#define __KEY_H_
#include "sys.h"



#define KEY0 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) //PE4
#define KEY1 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)	//PE3 
#define WK_UP 	    GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)	//PA0

#define KEY0_PRES   1
#define KEY1_PRES	2
#define WKUP_PRES   3


void    KEY_Init(void);	            //按键初始化
uint8_t KEY_Scan(uint8_t mode);		//按键扫描



#endif

