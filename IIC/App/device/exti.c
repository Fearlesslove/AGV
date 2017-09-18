#include "exti.h"
#include "beep.h"
#include "delay.h"
#include "led.h"
#include "key.h"

//�ⲿ�жϳ�ʼ������
//��ʼ��PE3~4,PA0Ϊ�ж�����

void EXTIX_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	
	KEY_Init();		//������Ӧ��IO�ڳ�ʼ��
 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);						//ʹ��SYSCFGʱ��
	
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);			//PE3 ���ӵ��ж���3
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);			//PE4 ���ӵ��ж���4
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);			//PA0 ���ӵ��ж���0
	
	/* ����EXTI_Line0 */
	
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;												//LINE0
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;								//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; 						//�����ش���
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;													//ʹ��LINE0
  EXTI_Init(&EXTI_InitStructure);																		//����
	
	/* ����EXTI_Line3,4 */

	EXTI_InitStructure.EXTI_Line =	EXTI_Line3 | EXTI_Line4;					//LINE3 LINE4
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;								//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;						//�½��ش���
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;													//�ж���ʹ��
  EXTI_Init(&EXTI_InitStructure);																		//����
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;									//�ⲿ�ж�0
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;			//��ռ���ȼ�0
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;							//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;										//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);																		//����
	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;									//�ⲿ�ж�3
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;			//��ռ���ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;							//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;										//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);																		//����
	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;									
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	   
}


//�ⲿ�ж�0�������

void EXTI0_IRQHandler(void)
{
	delay_ms(10);																											//����
	if(WK_UP==1)	 
	{
		BEEP_Change(); 																									//��������ת
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line0); 															//���LINE0�ϵ��жϱ�־λ
}	


void EXTI3_IRQHandler(void)
{
	delay_ms(10);
	if(KEY1==0)	 
	{
		LED_Change(LED_0);
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line3);  
}

void EXTI4_IRQHandler(void)
{
	delay_ms(10);
	if(KEY0==0)	 
	{				 
		LED_Change(LED_0);	
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line4);  
}






