#include "encoder.h"
#include "led.h"
#include "usart.h"

TIM_ICInitTypeDef  TIM5_ICInitStructure;

// ��ʱ��5ͨ��1���ؼ������
// arrΪ�Զ���װֵ	ע��TIM2 TIM5Ϊ32λ
// pscΪʱ��Ԥ��Ƶ��

void TIM5_CH1_Cap_Init(uint32_t arr,uint16_t psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);    						//TIM5ʱ��ʹ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);						//PORTAʱ��ʹ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;									//PA0						
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								//����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							//100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								//�������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;								//��������
	GPIO_Init(GPIOA,&GPIO_InitStructure);										//��ʼ��PA0

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM5);						//PA0���ö�ʱ��TIM5
  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;									//��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;					//���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;										//�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 						//ʱ�ӷ�Ƶ����
	
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);
	
	//��ʼ��TIM5���벶�����

	TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1; 							//CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
	TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;				//�����ز���
	TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 			//ӳ�䵽TI1��
	TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 					//���������Ƶ,����Ƶ 
	TIM5_ICInitStructure.TIM_ICFilter = 0x00;									//IC1F=0000 ���������˲��� ���˲�
	TIM_ICInit(TIM5, &TIM5_ICInitStructure);
		  
	TIM_ITConfig(TIM5,TIM_IT_Update|TIM_IT_CC1,ENABLE);							//��������ж� ,����CC1IE�����ж�
	
  	TIM_Cmd(TIM5,ENABLE);														//ʹ�ܶ�ʱ��5			
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;						//��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;							//�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);												//����ָ���Ĳ�����ʼ��VIC�Ĵ���
}

TIM_ICInitTypeDef  TIM5_ICInitStructure;

// ��ʱ��5ͨ��2���ؼ������
// arrΪ�Զ���װֵ	ע��TIM2 TIM5Ϊ32λ
// pscΪʱ��Ԥ��Ƶ��

void TIM5_CH2_Cap_Init(uint32_t arr,uint16_t psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM5);
  
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period=arr;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);
	


	TIM5_ICInitStructure.TIM_Channel = TIM_Channel_2;
	TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1; 
	TIM5_ICInitStructure.TIM_ICFilter = 0x00;
	TIM_ICInit(TIM5, &TIM5_ICInitStructure);
		
	TIM_ITConfig(TIM5,TIM_IT_Update|TIM_IT_CC2,ENABLE);	
	
 	TIM_Cmd(TIM5,ENABLE );
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		
	NVIC_Init(&NVIC_InitStructure);	
	
	
}


TIM_ICInitTypeDef  TIM3_ICInitStructure;

void TIM3_CH1_Cap_Init(uint16_t arr,uint16_t psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource8,GPIO_AF_TIM3);
  
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period=arr;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
	


	TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1; 
	TIM5_ICInitStructure.TIM_ICFilter = 0x00;
	TIM_ICInit(TIM3, &TIM3_ICInitStructure);
		
	TIM_ITConfig(TIM3,TIM_IT_Update|TIM_IT_CC1,ENABLE);	
	
  	TIM_Cmd(TIM3,ENABLE );

 
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	
}


//����״̬
//[7]:0,û�гɹ��Ĳ���;1,�ɹ�����һ��.
//[6]:0,��û���񵽵͵�ƽ;1,�Ѿ����񵽵͵�ƽ��.
//[5:0]:����͵�ƽ������Ĵ���(����32λ��ʱ����˵,1us��������1,���ʱ��:4294��)


uint8_t  	TIM5CH1_CAPTURE_STA=0;	//���벶��״̬	    				
uint32_t	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ(TIM2/TIM5��32λ)

uint8_t  	TIM5CH2_CAPTURE_STA=0;		    				
uint32_t	TIM5CH2_CAPTURE_VAL;

//��ʱ��5�жϷ������

void TIM5_IRQHandler(void)
{ 		    

 	if((TIM5CH1_CAPTURE_STA&0X80)==0)											//��δ�ɹ�����
	{
		if(TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)						//���
		{	     
			if(TIM5CH1_CAPTURE_STA&0X40)										//�Ѿ����񵽸ߵ�ƽ��
			{
				if((TIM5CH1_CAPTURE_STA&0X3F)==0X3F)							//�ߵ�ƽ̫����
				{
					TIM5CH1_CAPTURE_STA|=0X80;									//��ǳɹ�������һ��
					TIM5CH1_CAPTURE_VAL=0XFFFFFFFF;
				}else TIM5CH1_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)							//����1���������¼�
		{	
			if(TIM5CH1_CAPTURE_STA&0X40) 										//����һ���½���
			{	  			
				TIM5CH1_CAPTURE_STA|=0X80;										//��ǳɹ�����һ�θߵ�ƽ����
				TIM5CH1_CAPTURE_VAL=TIM_GetCapture1(TIM5);						//��ȡ��ǰ�Ĳ���ֵ
	 			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Rising);				//CC1P=0 ����Ϊ�����ز���
			}else  																//��δ��ʼ,��һ�β���������
			{
				TIM5CH1_CAPTURE_STA=0;											//���
				TIM5CH1_CAPTURE_VAL=0;
				TIM5CH1_CAPTURE_STA|=0X40;										//��ǲ�����������
				TIM_Cmd(TIM5,DISABLE );											//�رն�ʱ��5
	 			TIM_SetCounter(TIM5,0);
	 			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Falling);				//CC1P=1 ����Ϊ�½��ز���
				TIM_Cmd(TIM5,ENABLE );											//ʹ�ܶ�ʱ��5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_CC1|TIM_IT_Update);						//����жϱ�־λ

	if((TIM5CH2_CAPTURE_STA&0X80)==0)	
	{
		if(TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
		{	     
			if(TIM5CH2_CAPTURE_STA&0X40)
			{
				if((TIM5CH2_CAPTURE_STA&0X3F)==0X3F)
				{
					TIM5CH2_CAPTURE_STA|=0X80;
					TIM5CH2_CAPTURE_VAL=0XFFFFFFFF;
				}else TIM5CH2_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(TIM5, TIM_IT_CC2) != RESET)
		{	
			if(TIM5CH2_CAPTURE_STA&0X40) 		
			{	  			
				TIM5CH2_CAPTURE_STA|=0X80;
				TIM5CH2_CAPTURE_VAL=TIM_GetCapture2(TIM5);
	 			TIM_OC2PolarityConfig(TIM5,TIM_ICPolarity_Rising);
			}else  							
			{
				TIM5CH2_CAPTURE_STA=0;
				TIM5CH2_CAPTURE_VAL=0;
				TIM5CH2_CAPTURE_STA|=0X40;
				TIM_Cmd(TIM5,DISABLE );
	 			TIM_SetCounter(TIM5,0);
	 			TIM_OC2PolarityConfig(TIM5,TIM_ICPolarity_Falling);
				TIM_Cmd(TIM5,ENABLE );
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_CC2|TIM_IT_Update);

}



uint8_t  TIM3CH1_CAPTURE_STA=0;	    				
uint32_t	TIM3CH1_CAPTURE_VAL;
 
void TIM3_IRQHandler(void)
{ 		    

 	if((TIM3CH1_CAPTURE_STA&0X80)==0)	
	{
		if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
		{	     
			if(TIM3CH1_CAPTURE_STA&0X40)
			{
				if((TIM3CH1_CAPTURE_STA&0X3F)==0X3F)
				{
					TIM3CH1_CAPTURE_STA|=0X80;		
					TIM3CH1_CAPTURE_VAL=0XFFFFFFFF;
				}else TIM3CH1_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(TIM3, TIM_IT_CC1) != RESET)
		{	
			if(TIM3CH1_CAPTURE_STA&0X40)		 		
			{	  			
				TIM3CH1_CAPTURE_STA|=0X80;		
				TIM3CH1_CAPTURE_VAL=TIM_GetCapture1(TIM3);
	 			TIM_OC1PolarityConfig(TIM3,TIM_ICPolarity_Rising); 
			}else  								
			{
				TIM3CH1_CAPTURE_STA=0;		
				TIM3CH1_CAPTURE_VAL=0;
				TIM3CH1_CAPTURE_STA|=0X40;	
				TIM_Cmd(TIM3,DISABLE ); 	
	 			TIM_SetCounter(TIM3,0);
	 			TIM_OC1PolarityConfig(TIM3,TIM_ICPolarity_Falling);
				TIM_Cmd(TIM3,ENABLE ); 	
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM3, TIM_IT_CC1|TIM_IT_Update); 
}





