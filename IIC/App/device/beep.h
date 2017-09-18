#ifndef _BEEP_H_
#define _BEEP_H_

#include <stm32f4xx.h>

#define BEEP_Pin    GPIO_Pin_1          //BEEP PA1
#define BEEP_GPIO   GPIOA               //GPIOA

void BEEP_Init(void);		            //蜂鸣器初始化
void BEEP_ON(void);				        //开启蜂鸣器
void BEEP_OFF(void);			        //关闭蜂鸣器
void BEEP_Change(void);			        //蜂鸣器改变状态





#endif

