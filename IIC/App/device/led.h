#ifndef _LED_H_
#define _LED_H_

#include <stm32f4xx.h>

#define LED_0   GPIO_Pin_6                      //LED_0 PA6
#define LED_1   GPIO_Pin_7                      //LED_1 PA7
#define LED 	GPIO_Pin_6|GPIO_Pin_7           //LED   PA6|PA7

void    LED_Init(void);		                    //LED初始化
void    LED_ON(uint16_t ledpin);				//点亮对应管脚LED
void    LED_OFF(uint16_t ledpin);				//熄灭对应管脚LED
void    LED_Change(uint16_t ledpin);			//改变对应管脚LED的状态
uint8_t LED_GetStatus(uint16_t ledpin);			//获取对应管脚LED状态
void    LED_ShowStatues(uint16_t LED_x);		//使用相应管脚的LED来显示程序运行状态


#endif

