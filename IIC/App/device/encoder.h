#ifndef __ENCODER_H
#define __ENCODER_H
#include "sys.h"

extern uint8_t  TIM5CH1_CAPTURE_STA;		    				
extern uint32_t	TIM5CH1_CAPTURE_VAL;

extern uint8_t  TIM5CH2_CAPTURE_STA;		    				
extern uint32_t	TIM5CH2_CAPTURE_VAL;

extern uint8_t  TIM3CH1_CAPTURE_STA;	    				
extern uint32_t	TIM3CH1_CAPTURE_VAL;

void TIM5_CH1_Cap_Init(u32 arr,uint16_t psc);
void TIM5_CH2_Cap_Init(u32 arr,uint16_t psc);
void TIM3_CH1_Cap_Init(uint16_t arr,uint16_t psc);

#endif























