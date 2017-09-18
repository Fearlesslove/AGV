#include "pwm.h"
#include "led.h"

//TIM3 PWM���ֳ�ʼ�� 
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��

void TIM3_PWM_Init(u32 arr,u32 psc)	
{		 					 

	
	GPIO_InitTypeDef GPIO_InitStructure;									
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;							
	TIM_OCInitTypeDef  TIM_OCInitStructure;										
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    					//TIM3ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);					//PORTBʱ��ʹ��
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource0,GPIO_AF_TIM3);					//PB0����Ϊ��ʱ��TIM3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_TIM3);					//PB1����Ϊ��ʱ��TIM3

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;					//PB0	PB1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;							//����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;						//100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;							//�������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;							//����

	GPIO_Init(GPIOB,&GPIO_InitStructure);									//PB0 PB1��ʼ��
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;								//��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;				//���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;									//�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);							//��ʱ��3��ʼ��
	
	//TIM3 Channel1 PWMģʽ��ʼ��

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;						//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;			//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;				//�������:TIM����Ƚϼ��Ե�
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);								//����Tָ���Ĳ�����ʼ������TIM3 4OC3
		
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;						//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;			//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;				//�������:TIM����Ƚϼ��Ը�
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);								//����Tָ���Ĳ�����ʼ������TIM3 4OC4


	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);						//ʹ��TIM3��CCR3�ϵ�Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);						//ʹ��TIM3��CCR4�ϵ�Ԥװ�ؼĴ���



  	TIM_ARRPreloadConfig(TIM3,ENABLE); 										//ARPEʹ��
	
	TIM_Cmd(TIM3, ENABLE);
 
										  
}  


