#include "encoder.h"
#include "led.h"
#include "usart.h"

TIM_ICInitTypeDef  TIM5_ICInitStructure;

// 定时器5通道1边沿检测配置
// arr为自动重装值	注意TIM2 TIM5为32位
// psc为时钟预分频数

void TIM5_CH1_Cap_Init(uint32_t arr,uint16_t psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);    						//TIM5时钟使能
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);						//PORTA时钟使能
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;									//PA0						
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;								//复用
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;							//100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								//推挽输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;								//下拉电阻
	GPIO_Init(GPIOA,&GPIO_InitStructure);										//初始化PA0

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource0,GPIO_AF_TIM5);						//PA0复用定时器TIM5
  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;									//定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;					//向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;										//自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 						//时钟分频因子
	
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseStructure);
	
	//初始化TIM5输入捕获参数

	TIM5_ICInitStructure.TIM_Channel = TIM_Channel_1; 							//CC1S=01 	选择输入端 IC1映射到TI1上
	TIM5_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;				//上升沿捕获
	TIM5_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 			//映射到TI1上
	TIM5_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 					//配置输入分频,不分频 
	TIM5_ICInitStructure.TIM_ICFilter = 0x00;									//IC1F=0000 配置输入滤波器 不滤波
	TIM_ICInit(TIM5, &TIM5_ICInitStructure);
		  
	TIM_ITConfig(TIM5,TIM_IT_Update|TIM_IT_CC1,ENABLE);							//允许更新中断 ,允许CC1IE捕获中断
	
  	TIM_Cmd(TIM5,ENABLE);														//使能定时器5			
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;						//抢占优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;							//子优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);												//根据指定的参数初始化VIC寄存器
}

TIM_ICInitTypeDef  TIM5_ICInitStructure;

// 定时器5通道2边沿检测配置
// arr为自动重装值	注意TIM2 TIM5为32位
// psc为时钟预分频数

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


//捕获状态
//[7]:0,没有成功的捕获;1,成功捕获到一次.
//[6]:0,还没捕获到低电平;1,已经捕获到低电平了.
//[5:0]:捕获低电平后溢出的次数(对于32位定时器来说,1us计数器加1,溢出时间:4294秒)


uint8_t  	TIM5CH1_CAPTURE_STA=0;	//输入捕获状态	    				
uint32_t	TIM5CH1_CAPTURE_VAL;	//输入捕获值(TIM2/TIM5是32位)

uint8_t  	TIM5CH2_CAPTURE_STA=0;		    				
uint32_t	TIM5CH2_CAPTURE_VAL;

//定时器5中断服务程序

void TIM5_IRQHandler(void)
{ 		    

 	if((TIM5CH1_CAPTURE_STA&0X80)==0)											//还未成功捕获
	{
		if(TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)						//溢出
		{	     
			if(TIM5CH1_CAPTURE_STA&0X40)										//已经捕获到高电平了
			{
				if((TIM5CH1_CAPTURE_STA&0X3F)==0X3F)							//高电平太长了
				{
					TIM5CH1_CAPTURE_STA|=0X80;									//标记成功捕获了一次
					TIM5CH1_CAPTURE_VAL=0XFFFFFFFF;
				}else TIM5CH1_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(TIM5, TIM_IT_CC1) != RESET)							//捕获1发生捕获事件
		{	
			if(TIM5CH1_CAPTURE_STA&0X40) 										//捕获到一个下降沿
			{	  			
				TIM5CH1_CAPTURE_STA|=0X80;										//标记成功捕获到一次高电平脉宽
				TIM5CH1_CAPTURE_VAL=TIM_GetCapture1(TIM5);						//获取当前的捕获值
	 			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Rising);				//CC1P=0 设置为上升沿捕获
			}else  																//还未开始,第一次捕获上升沿
			{
				TIM5CH1_CAPTURE_STA=0;											//清空
				TIM5CH1_CAPTURE_VAL=0;
				TIM5CH1_CAPTURE_STA|=0X40;										//标记捕获到了上升沿
				TIM_Cmd(TIM5,DISABLE );											//关闭定时器5
	 			TIM_SetCounter(TIM5,0);
	 			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Falling);				//CC1P=1 设置为下降沿捕获
				TIM_Cmd(TIM5,ENABLE );											//使能定时器5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(TIM5, TIM_IT_CC1|TIM_IT_Update);						//清除中断标志位

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





