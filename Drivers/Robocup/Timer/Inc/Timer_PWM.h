/*
 * Timer_PWM.h
 *
 *  Created on: Apr 19, 2020
 *      Author: dimagic
 */

#ifndef ROBOCUP_TIMER_PWM_INC_TIMER_PWM_H_
#define ROBOCUP_TIMER_PWM_INC_TIMER_PWM_H_

#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"

typedef struct
{
	TIM_TypeDef * TIMx;
	uint32_t Frequency;
	uint16_t TIM_channelx;
	GPIO_TypeDef * GPIOx;
	uint16_t GPIO_Pinx;
	uint8_t GPIO_AlternateFunctionx;
	uint8_t Duty_Cicle;
}TIM_PWM_Typedef;


#define TIMx_PWM_CLK (16000000UL)

void TIMx_PWM_Init(TIM_PWM_Typedef config);

void Change_PWM_Pulse(TIM_PWM_Typedef config);

void TIMx_PWM_Start(TIM_PWM_Typedef config);

void TIMx_PWM_Stop(TIM_PWM_Typedef config);


#endif /* ROBOCUP_TIMER_PWM_INC_TIMER_PWM_H_ */
