#include "led.h"
#include "delay.h"

void LED_Init(void)		//LED初始化
{
	
	GPIO_InitTypeDef GPIO_InitStructure;					//定义结构体变量
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	//GPIOA时钟初始化
	
	GPIO_InitStructure.GPIO_Pin = LED;						//GPIO管脚初始化
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//推挽输出模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//上拉模式

	GPIO_Init(GPIOA, &GPIO_InitStructure);					//GPIOA初始化
	GPIO_SetBits(GPIOA, LED);								//LED置高，灯灭
}


void LED_ON(uint16_t ledpin)								//点亮对应管脚LED
{
	GPIO_ResetBits(GPIOA,ledpin);							//对应管脚置零	点亮
}
	
void LED_OFF(uint16_t ledpin)								//熄灭对应管脚LED
{
	GPIO_SetBits(GPIOA,ledpin);								//对应管脚置高	熄灭
}

void LED_Change(uint16_t ledpin)							//改变对应管脚LED的状态
{
	if (GPIO_ReadOutputDataBit(GPIOA,ledpin))
		GPIO_ResetBits(GPIOA,ledpin);
	else
		GPIO_SetBits(GPIOA,ledpin);
}

uint8_t LED_GetStatus(uint16_t ledpin)						//获取对应管脚LED状态
{
	return !GPIO_ReadInputDataBit(GPIOA,ledpin);
}


void LED_ShowStatues(uint16_t LED_x)						//使用相应管脚的LED来显示程序运行状态
{
		LED_ON(LED_x);
		delay_ms(20);
		LED_OFF(LED_x);
		delay_ms(20);	
}

	
	
	
