#include "usart.h"
#include "sys.h"

//////////////////////////////////////////////////////////////////
//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
void _sys_exit(int x) 
{ 
	x = x; 
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{ 	
	while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
	USART1->DR = (u8) ch;      
	return ch;
}
#endif

#if EN_USART1_RX	//���ʹ����USART1����

//����1�жϷ������
//ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���  

uint16_t 	USART_RX_STA1=0;

//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ

uint8_t 	USART_RX_BUF1[USART_REC_LEN];

//���ջ���,���USART_REC_LEN���ֽ�

#endif

#if EN_USART2_RX	//���ʹ����USART2����

uint16_t 	USART_RX_STA2=0;

//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ

uint8_t 	USART_RX_BUF2[USART_REC_LEN];

//���ջ���,���USART_REC_LEN���ֽ�

#endif

//��ʼ��UART1	bound:������

void UART1_Init(uint32_t bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
		
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USART1, &USART_InitStructure);
		
	USART_Cmd(USART1, ENABLE);		
		
#if EN_USART1_RX	
	USART_ITConfig(USART1, USART_IT_RXNE,ENABLE);
	USART_ClearFlag(USART1,USART_FLAG_TC);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
#endif
}


void UART2_Init(uint32_t bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3;		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USART2, &USART_InitStructure);
	
	USART_Cmd(USART2, ENABLE);		
	
#if EN_USART2_RX	
	USART_ITConfig(USART2, USART_IT_RXNE,ENABLE);
	USART_ClearFlag(USART2,USART_FLAG_TC);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
#endif
}




void USART1_IRQHandler(void)
{
	uint8_t Res;
#if SYSTEM_SUPPORT_OS
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		Res =USART_ReceiveData(USART1);
		
		USART_RX_BUF1[USART_RX_STA1&0X3FFF]=Res ;
		USART_RX_STA1++;
		if(USART_RX_STA1>(USART_REC_LEN-1))USART_RX_STA1=0;	  	 
	} 
}		
		
void USART2_IRQHandler(void)
{
	uint8_t Res;
#if SYSTEM_SUPPORT_OS
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		Res =USART_ReceiveData(USART2);
		
		if((USART_RX_STA2&0x8000)==0)
		{
			if(USART_RX_STA2&0x4000)
			{
				if(Res!=0x0a)USART_RX_STA2=0;
				else USART_RX_STA2|=0x8000; 
			}
			else
			{	
				if(Res==0x0d)USART_RX_STA2|=0x4000;
				else
				{
					USART_RX_BUF2[USART_RX_STA2&0X3FFF]=Res ;
					USART_RX_STA2++;
					if(USART_RX_STA2>(USART_REC_LEN-1))USART_RX_STA2=0;	  
				}		 
			}
		}   		 
  } 
}		







