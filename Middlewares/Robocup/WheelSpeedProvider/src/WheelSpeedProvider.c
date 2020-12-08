/*
 * WheelSpeedProvider.c
 *
 *  Created on: Sep 26, 2020
 *      Author: dimagic
 */

#include "WheelSpeedProvider.h"
#include "Common_Data.h"
#include "Port_config.h"

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
	uint32_t temp_old;
	uint32_t temp_new;
	uint32_t temp_diff;
	Enc1_value_old = Enc1_value;
	temp_old= Enc1_value_old;
	Enc1_value = ENC_1_TIM_CNT;
	temp_new=Enc1_value;
	if((ENC_1_TIM_DIR == FORWARD_DIR) && (Enc1_value < Enc1_value_old))
	{
		Enc1_diff = Enc1_value - (0xFFFF - Enc1_value_old);
	}
	else if((ENC_1_TIM_DIR == BACKWARD_DIR) && (Enc1_value > Enc1_value_old))
	{
		Enc1_diff = Enc1_value_old - (0xFFFF - Enc1_value);
	}
	else if(ENC_1_TIM_DIR == BACKWARD_DIR)
	{
		Enc1_diff = Enc1_value_old - Enc1_value;
	}
	else
	{
		Enc1_diff = Enc1_value - Enc1_value_old;
	}

	temp_diff= Enc1_diff;
	Provided_wheel_speeds.WheelSpeed_1= (float)((2*(float)Enc1_diff*M_PI)/(ENCODER_COUNT*MOT_TO_WHEEL_RATIO*(float)0.01))*RAD_PER_S_TO_RPM;

	if(ENC_1_TIM_DIR == BACKWARD_DIR)
	{
		Provided_wheel_speeds.WheelSpeed_1 = Provided_wheel_speeds.WheelSpeed_1 * -1;
	}

	Write_Provided_Wheel_Speeds(&Provided_wheel_speeds);
}
