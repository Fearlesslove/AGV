#ifndef _USART_H_
#define _USART_H_

#include <stm32f4xx.h>
#include <stdio.h>


#define USART_REC_LEN  			200 	
#define EN_USART1_RX 			1		
#define EN_USART2_RX 			1		

extern uint8_t  USART_RX_BUF1[USART_REC_LEN]; 
extern uint16_t USART_RX_STA1;	
extern uint8_t  USART_RX_BUF2[USART_REC_LEN]; 
extern uint16_t USART_RX_STA2;


void UART_Init(uint32_t bound);







#endif




