/*
 * Timer_encoder.h
 *
 *  Created on: Sep 26, 2020
 *      Author: dimagic
 */

#ifndef ROBOCUP_TIMER_ENC_TIMER_ENCODER_H_
#define ROBOCUP_TIMER_ENC_TIMER_ENCODER_H_

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"

typedef struct
{
	TIM_TypeDef * TIMx;
	uint16_t TIM_channelx;
	GPIO_TypeDef * GPIOx_ch1;
	GPIO_TypeDef * GPIOx_ch2;
	uint16_t GPIO_Pinx_ch1;
	uint16_t GPIO_Pinx_ch2;
	uint8_t GPIO_AlternateFunctionx;
	IRQn_Type TIMx_IRQ;
}TIM_ENC_Typedef;


#define TIMx_ENC_CLK (1000000UL)


void TIMx_ENC_Init(TIM_ENC_Typedef config);

void TIMx_ENC_Start(TIM_ENC_Typedef config);

void TIMx_ENC_Stop(TIM_ENC_Typedef config);



#endif /* ROBOCUP_TIMER_ENC_TIMER_ENCODER_H_ */
