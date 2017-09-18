#include "key.h"
#include "delay.h"

//������ʼ��

void KEY_Init(void)		
{
	GPIO_InitTypeDef GPIO_InitStructure;											//����GPIO��ʼ���ṹ��
  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE, ENABLE);		//AHB1ʱ�������ϵ�GPIOA	GPIOE��ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4;							//PE3 PE4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;									//����ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;								//100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;									//����

	GPIO_Init(GPIOE, &GPIO_InitStructure);											//PE3 PE4��ʼ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;										//PA0
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN ;									//����

	GPIO_Init(GPIOA, &GPIO_InitStructure);											//PA0��ʼ��
}

//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����
//3��KEY2���� 
//4��WKUP���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>WK_UP!!

uint8_t KEY_Scan(uint8_t mode)		
{	 
	static uint8_t key_up=1;														//�������ɿ���־
	if(mode)key_up=1;		  														//֧������
	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
	{
		delay_ms(10); 																//ȥ����
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
 	return 0;																		// �ް�������
}
