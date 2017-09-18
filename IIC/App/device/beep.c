#include "beep.h"

void BEEP_Init(void)												//��������ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;							//����GPIO�ṹ�����
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);			//GPIOAʱ�ӳ�ʼ��
	
	GPIO_InitStructure.GPIO_Pin = BEEP_Pin;							//�������ܽŶ���
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;					//���ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;				//100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;					//�������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;					//����

	GPIO_Init(BEEP_GPIO, &GPIO_InitStructure);						//GPIOA�ṹ���ʼ��
	GPIO_ResetBits(BEEP_GPIO, BEEP_Pin);							//BEEP��Ӧ�Ĺܽ����㣬����������
}

void BEEP_ON(void)													//����������
{
	GPIO_SetBits(BEEP_GPIO,BEEP_Pin);
}


void BEEP_OFF(void)													//�رշ�����
{
	GPIO_ResetBits(BEEP_GPIO,BEEP_Pin);
}

void BEEP_Change(void)												//�������ı�״̬
{
	if (GPIO_ReadOutputDataBit(BEEP_GPIO,BEEP_Pin))
		GPIO_ResetBits(BEEP_GPIO,BEEP_Pin);
	else
		GPIO_SetBits(BEEP_GPIO,BEEP_Pin);
}






