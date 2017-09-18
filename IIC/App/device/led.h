#ifndef _LED_H_
#define _LED_H_

#include <stm32f4xx.h>

#define LED_0   GPIO_Pin_6                      //LED_0 PA6
#define LED_1   GPIO_Pin_7                      //LED_1 PA7
#define LED 	GPIO_Pin_6|GPIO_Pin_7           //LED   PA6|PA7

void    LED_Init(void);		                    //LED��ʼ��
void    LED_ON(uint16_t ledpin);				//������Ӧ�ܽ�LED
void    LED_OFF(uint16_t ledpin);				//Ϩ���Ӧ�ܽ�LED
void    LED_Change(uint16_t ledpin);			//�ı��Ӧ�ܽ�LED��״̬
uint8_t LED_GetStatus(uint16_t ledpin);			//��ȡ��Ӧ�ܽ�LED״̬
void    LED_ShowStatues(uint16_t LED_x);		//ʹ����Ӧ�ܽŵ�LED����ʾ��������״̬


#endif

