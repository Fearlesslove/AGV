#include "key.h"
#include "delay.h"

//按键初始化

void KEY_Init(void)		
{
	GPIO_InitTypeDef GPIO_InitStructure;											//定义GPIO初始化结构体
  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE, ENABLE);		//AHB1时钟总线上的GPIOA	GPIOE的时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4;							//PE3 PE4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;									//输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;								//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;									//上拉

	GPIO_Init(GPIOE, &GPIO_InitStructure);											//PE3 PE4初始化
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;										//PA0
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN ;									//下拉

	GPIO_Init(GPIOA, &GPIO_InitStructure);											//PA0初始化
}

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0按下
//2，KEY1按下
//3，KEY2按下 
//4，WKUP按下 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY2>WK_UP!!

uint8_t KEY_Scan(uint8_t mode)		
{	 
	static uint8_t key_up=1;														//按键按松开标志
	if(mode)key_up=1;		  														//支持连按
	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
	{
		delay_ms(10); 																//去抖动
		key_up=0;
		if(KEY0==0)
			return 1;
		else if(KEY1==0)
			return 2;
		else if(WK_UP==1)
			return 3;
	}
	else if
		(KEY0==1&&KEY1==1&&WK_UP==0)key_up=1; 	    
 	return 0;																		// 无按键按下
}
