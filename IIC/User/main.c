#include "public.h"

#define key_mode 0

int main(void)
{
	int16_t led0pwmval=1,led1pwmval=1,times=0;    
	uint8_t dir=1;
	uint8_t key;
	uint8_t t,len;
	long long temp1=0,temp2=0;  

	
	delay_init(168);		
	LED_Init();
	KEY_Init();
	// EXTIX_Init();
	UART1_Init(115200);
    UART1_Init(115200);

	// IIC_Init();

 	TIM3_PWM_Init(600-1,84-1);  				
	// TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1);
	// TIM5_CH2_Cap_Init(0XFFFFFFFF,84-1);
	// TIM3_CH1_Cap_Init(0XFFFF,84-1);
	// TIM4_Int_Init(5000-1,8400-1);

	while(1) 
	{ 
 		// if(TIM5CH1_CAPTURE_STA&0X80)      					
		// {
		// 	temp1=TIM5CH1_CAPTURE_STA&0X3F; 
		// 	temp1*=0XFFFFFFFF;		 		   
		// 	temp1+=TIM5CH1_CAPTURE_VAL;		  
		// 	printf("RIGHT_HIGH:%lld us\r\n",temp1); 
		// 	TIM5CH1_CAPTURE_STA=0;
		// }

		// if(TIM5CH2_CAPTURE_STA&0X80)      
		// {
		// 	temp2=TIM5CH2_CAPTURE_STA&0X3F; 
		// 	temp2*=0XFFFFFFFF;		 		   
		// 	temp2+=TIM5CH2_CAPTURE_VAL;		  
		// 	printf("LEFT_HIGH:%lld us\r\n",temp2); 
		// 	TIM5CH2_CAPTURE_STA=0;
		// }

		
		
		if(dir)
			led0pwmval+=1;
		else 
			led0pwmval-=1; 
 		if(led0pwmval>600)
			dir=0;
		if(led0pwmval<300)
		{
			dir=1;
			led0pwmval=300;
		}
		TIM_SetCompare3(TIM3,led0pwmval);
				
		if(dir)
			led1pwmval+=8;
		else 
			led1pwmval-=8; 
 		if(led0pwmval>600)
			dir=0;
		if(led0pwmval<300)
			dir=1;
		TIM_SetCompare4(TIM3,led1pwmval);


		key=KEY_Scan(key_mode);
		if(key)
		{
			switch(key)
			{
				case WKUP_PRES:
					USART_SendData(USART1,1);
                	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束

                	USART_SendData(USART1,0x0d);
                	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束

                	USART_SendData(USART1,0x0a);
                	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束


					LED_Change(LED_0);
					break;
				case KEY0_PRES:
					USART_SendData(USART1,2);
                    while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束

                    USART_SendData(USART1,0x0d);
                	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束

                	USART_SendData(USART1,0x0a);
                	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
					LED_OFF(LED_0);
					break;
				case KEY1_PRES:
					USART_SendData(USART1,4);
                    while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束	
                    USART_SendData(USART1,0x0d);
                	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束

                	USART_SendData(USART1,0x0a);
                	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束                
					LED_ON(LED_0);
					break;
			}
		}
		
		if(USART_RX_STA1&0x8000)
		{					   
			len=USART_RX_STA1&0x3fff;
			printf("\r\n接收到的数据为：\r\n");
			for(t=0;t<len;t++)
			{
				USART_SendData(USART1, USART_RX_BUF1[t]);
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
			}
			printf("\r\n\r\n");            
			USART_RX_STA1=0;
		}
		else
		{
			times++;
			if(times%200==0)
			{
				printf("\r\n最小系统板测试\r\n");
			}
			if(times%20==0)printf("请输入数据\r\n");    
		}


		if(USART_RX_STA2&0x8000)
		{					   
			len=USART_RX_STA2&0x3fff;
			printf("\r\n接收到的数据为：\r\n");
			for(t=0;t<len;t++)
			{
				USART_SendData(USART2, USART_RX_BUF2[t]);
				while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
			}
			printf("\r\n\r\n");
			
			USART_RX_STA2=0;
		}
		else
		{
			times++;
			if(times%200==0)
			{
				printf("\r\n最小系统板测试\r\n");
			}
			if(times%20==0)printf("请输入数据\r\n");    
		}

		LED_ShowStatues(LED_1);
	}
}
