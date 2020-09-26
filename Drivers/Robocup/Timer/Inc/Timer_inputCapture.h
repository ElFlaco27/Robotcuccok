/*
 * Timer_inputCapture.h
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#ifndef ROBOCUP_TIMER_INPUTCAPTURE_INC_TIMER_INPUTCAPTURE_H_
#define ROBOCUP_TIMER_INPUTCAPTURE_INC_TIMER_INPUTCAPTURE_H_

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"

typedef struct
{
	TIM_TypeDef * TIMx;
	uint16_t TIM_channelx;
	GPIO_TypeDef * GPIOx;
	uint16_t GPIO_Pinx;
	uint8_t GPIO_AlternateFunctionx;
	IRQn_Type TIMx_IRQ;
}TIM_IC_Typedef;


#define TIMx_IC_CLK (1000000UL)


void TIMx_IC_Init(TIM_IC_Typedef config);

void TIMx_IC_Start(TIM_IC_Typedef config);

void TIMx_IC_Stop(TIM_IC_Typedef config);


#endif /* ROBOCUP_TIMER_INPUTCAPTURE_INC_TIMER_INPUTCAPTURE_H_ */
