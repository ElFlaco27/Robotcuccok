/*
 * WheelSpeedProvider.c
 *
 *  Created on: Sep 26, 2020
 *      Author: dimagic
 */

#include "WheelSpeedProvider.h"

volatile uint32_t Enc1_value;
volatile uint32_t Enc1_value_old;
volatile uint32_t Enc1_diff;

void Init_Wheel_Speed_Provision(void)
{
	TIM_ENC_Typedef TIM_handler = {0};

	#ifdef MOTOR1
		TIM_handler.TIMx = ENC_1A_TIM;
		TIM_handler.TIM_channelx = ENC_1A_TIM_CHANNEL;
		TIM_handler.GPIOx_ch1 = ENC_1A_GPIO;
		TIM_handler.GPIOx_ch2 = ENC_1B_GPIO;
		TIM_handler.GPIO_Pinx_ch1 = ENC_1A_GPIO_PIN;
		TIM_handler.GPIO_Pinx_ch2 = ENC_1B_GPIO_PIN;
		TIM_handler.GPIO_AlternateFunctionx = ENC_1A_GPIO_AF;

		TIMx_ENC_Init(TIM_handler);
		TIMx_ENC_Start(TIM_handler);
	#endif
	#ifdef MOTOR2
		TIM_handler.TIMx = ENC_2A_TIM;
		TIM_handler.TIM_channelx = ENC_2A_TIM_CHANNEL;
		TIM_handler.GPIOx_ch1 = ENC_2A_GPIO;
		TIM_handler.GPIOx_ch2 = ENC_2B_GPIO;
		TIM_handler.GPIO_Pinx_ch1 = ENC_2A_GPIO_PIN;
		TIM_handler.GPIO_Pinx_ch2 = ENC_2B_GPIO_PIN;
		TIM_handler.GPIO_AlternateFunctionx = ENC_2A_GPIO_AF;

		TIMx_ENC_Init(TIM_handler);
		TIMx_ENC_Start(TIM_handler);
	#endif
	#ifdef MOTOR3
		TIM_handler.TIMx = ENC_2A_TIM;
		TIM_handler.TIM_channelx = ENC_2A_TIM_CHANNEL;
		TIM_handler.GPIOx_ch1 = ENC_2A_GPIO;
		TIM_handler.GPIOx_ch2 = ENC_2B_GPIO;
		TIM_handler.GPIO_Pinx_ch1 = ENC_2A_GPIO_PIN;
		TIM_handler.GPIO_Pinx_ch2 = ENC_2B_GPIO_PIN;
		TIM_handler.GPIO_AlternateFunctionx = ENC_2A_GPIO_AF;

		TIMx_ENC_Init(TIM_handler);
		TIMx_ENC_Start(TIM_handler);
	#endif
	#ifdef MOTOR4
		TIM_handler.TIMx = ENC_2A_TIM;
		TIM_handler.TIM_channelx = ENC_2A_TIM_CHANNEL;
		TIM_handler.GPIOx_ch1 = ENC_2A_GPIO;
		TIM_handler.GPIOx_ch2 = ENC_2B_GPIO;
		TIM_handler.GPIO_Pinx_ch1 = ENC_2A_GPIO_PIN;
		TIM_handler.GPIO_Pinx_ch2 = ENC_2B_GPIO_PIN;
		TIM_handler.GPIO_AlternateFunctionx = ENC_2A_GPIO_AF;

		TIMx_ENC_Init(TIM_handler);
		TIMx_ENC_Start(TIM_handler);
	#endif
}


void Provide_Wheel_Speeds(void)
{
	WheelSpeed_Typedef Provided_wheel_speeds;
	uint32_t temp;
	Enc1_value_old = Enc1_value;
	Enc1_value = ENC_1A_TIM->CNT;
	temp= ENC_1A_TIM->CNT;
	Enc1_diff = Enc1_value - Enc1_value_old;

}
