#include "pwm.h"
#include "led.h"

//TIM3 PWM部分初始化 
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数

void TIM3_PWM_Init(u32 arr,u32 psc)	
{		 					 

	
	GPIO_InitTypeDef GPIO_InitStructure;									
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;							
	TIM_OCInitTypeDef  TIM_OCInitStructure;										
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    					//TIM3时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);					//PORTB时钟使能
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource0,GPIO_AF_TIM3);					//PB0复用为定时器TIM3
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_TIM3);					//PB1复用为定时器TIM3

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;					//PB0	PB1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;							//复用
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;						//100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;							//推挽输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;							//上拉

	GPIO_Init(GPIOB,&GPIO_InitStructure);									//PB0 PB1初始化
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;								//定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;				//向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;									//自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);							//定时器3初始化
	
	//TIM3 Channel1 PWM模式初始化

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;						//选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;			//比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;				//输出极性:TIM输出比较极性低
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);								//根据T指定的参数初始化外设TIM3 4OC3
		
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;						//选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;			//比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;				//输出极性:TIM输出比较极性高
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);								//根据T指定的参数初始化外设TIM3 4OC4


	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);						//使能TIM3在CCR3上的预装载寄存器
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);						//使能TIM3在CCR4上的预装载寄存器



  	TIM_ARRPreloadConfig(TIM3,ENABLE); 										//ARPE使能
	
	TIM_Cmd(TIM3, ENABLE);
 
										  
}  


