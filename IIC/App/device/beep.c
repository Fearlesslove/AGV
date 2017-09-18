#include "beep.h"

void BEEP_Init(void)												//蜂鸣器初始化
{
	GPIO_InitTypeDef GPIO_InitStructure;							//定义GPIO结构体变量
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);			//GPIOA时钟初始化
	
	GPIO_InitStructure.GPIO_Pin = BEEP_Pin;							//蜂鸣器管脚定义
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;					//输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;				//100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					//推挽输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;					//上拉

	GPIO_Init(BEEP_GPIO, &GPIO_InitStructure);						//GPIOA结构体初始化
	GPIO_ResetBits(BEEP_GPIO, BEEP_Pin);							//BEEP对应的管脚置零，蜂鸣器不叫
}

void BEEP_ON(void)													//开启蜂鸣器
{
	GPIO_SetBits(BEEP_GPIO,BEEP_Pin);
}


void BEEP_OFF(void)													//关闭蜂鸣器
{
	GPIO_ResetBits(BEEP_GPIO,BEEP_Pin);
}

void BEEP_Change(void)												//蜂鸣器改变状态
{
	if (GPIO_ReadOutputDataBit(BEEP_GPIO,BEEP_Pin))
		GPIO_ResetBits(BEEP_GPIO,BEEP_Pin);
	else
		GPIO_SetBits(BEEP_GPIO,BEEP_Pin);
}






