#include <led.h>

void LED_Init(void){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = LED;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, LED);
}


void LED_ON(uint16_t ledpin)
{
	GPIO_ResetBits(GPIOA,ledpin);
}
	
void LED_OFF(uint16_t ledpin)
{
	GPIO_SetBits(GPIOA,ledpin);
}

void LED_Change(uint16_t ledpin)
{
	if (GPIO_ReadOutputDataBit(GPIOA,ledpin))
		GPIO_ResetBits(GPIOA,ledpin);
	else
		GPIO_SetBits(GPIOA,ledpin);
}

uint8_t LED_GetStatus(uint16_t ledpin)
{
	return !GPIO_ReadInputDataBit(GPIOA,ledpin);
}


	
	
	
