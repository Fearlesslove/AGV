#include "led.h"
#include "delay.h"

void LED_Init(void)		//LED��ʼ��
{
	
	GPIO_InitTypeDef GPIO_InitStructure;					//����ṹ�����
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	//GPIOAʱ�ӳ�ʼ��
	
	GPIO_InitStructure.GPIO_Pin = LED;						//GPIO�ܽų�ʼ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			//���ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		//100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//�������ģʽ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//����ģʽ

	GPIO_Init(GPIOA, &GPIO_InitStructure);					//GPIOA��ʼ��
	GPIO_SetBits(GPIOA, LED);								//LED�øߣ�����
}


void LED_ON(uint16_t ledpin)								//������Ӧ�ܽ�LED
{
	GPIO_ResetBits(GPIOA,ledpin);							//��Ӧ�ܽ�����	����
}
	
void LED_OFF(uint16_t ledpin)								//Ϩ���Ӧ�ܽ�LED
{
	GPIO_SetBits(GPIOA,ledpin);								//��Ӧ�ܽ��ø�	Ϩ��
}

void LED_Change(uint16_t ledpin)							//�ı��Ӧ�ܽ�LED��״̬
{
	if (GPIO_ReadOutputDataBit(GPIOA,ledpin))
		GPIO_ResetBits(GPIOA,ledpin);
	else
		GPIO_SetBits(GPIOA,ledpin);
}

uint8_t LED_GetStatus(uint16_t ledpin)						//��ȡ��Ӧ�ܽ�LED״̬
{
	return !GPIO_ReadInputDataBit(GPIOA,ledpin);
}


void LED_ShowStatues(uint16_t LED_x)						//ʹ����Ӧ�ܽŵ�LED����ʾ��������״̬
{
		LED_ON(LED_x);
		delay_ms(20);
		LED_OFF(LED_x);
		delay_ms(20);	
}

	
	
	
