#ifndef _BEEP_H_
#define _BEEP_H_

#include <stm32f4xx.h>

#define BEEP_Pin    GPIO_Pin_1          //BEEP PA1
#define BEEP_GPIO   GPIOA               //GPIOA

void BEEP_Init(void);		            //��������ʼ��
void BEEP_ON(void);				        //����������
void BEEP_OFF(void);			        //�رշ�����
void BEEP_Change(void);			        //�������ı�״̬





#endif

