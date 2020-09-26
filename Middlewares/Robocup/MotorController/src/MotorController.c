/*
 * MotorController.c
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#include "MotorController.h"
#include "Common_Data.h"



void Motor_Init(void)
{
	TIM_PWM_Typedef TIM_handler = {0};
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

#ifdef MOTOR1
	TIM_handler.TIMx = Motor1_A_TIM;
	TIM_handler.TIM_channelx = Motor1_A_TIM_CHANNEL;
	TIM_handler.GPIOx = Motor1_A_GPIO;
	TIM_handler.GPIO_Pinx = Motor1_A_GPIO_PIN;
	TIM_handler.GPIO_AlternateFunctionx = Motor1_A_GPIO_AF;
	TIM_handler.Frequency = PWM_FREQUENCY;

	TIMx_PWM_Init(TIM_handler);

	TIM_handler.TIMx = Motor1_B_TIM;
	TIM_handler.TIM_channelx = Motor1_B_TIM_CHANNEL;
	TIM_handler.GPIOx = Motor1_B_GPIO;
	TIM_handler.GPIO_Pinx = Motor1_B_GPIO_PIN;
	TIM_handler.GPIO_AlternateFunctionx = Motor1_B_GPIO_AF;
	TIM_handler.Frequency = PWM_FREQUENCY;

	TIMx_PWM_Init(TIM_handler);

	GPIO_InitStruct.Pin = Motor1_EN_PIN;
	HAL_GPIO_Init(Motor1_EN_GPIO, &GPIO_InitStruct);
#endif
#ifdef MOTOR2
	TIM_handler.TIMx = Motor2_A_TIM;
	TIM_handler.TIM_channelx = Motor2_A_TIM_CHANNEL;
	TIM_handler.GPIOx = Motor2_A_GPIO;
	TIM_handler.GPIO_Pinx = Motor2_A_GPIO_PIN;
	TIM_handler.GPIO_AlternateFunctionx = Motor2_A_GPIO_AF;
	TIM_handler.Frequency = PWM_FREQUENCY;

	TIMx_PWM_Init(TIM_handler);

	TIM_handler.TIMx = Motor2_B_TIM;
	TIM_handler.TIM_channelx = Motor2_B_TIM_CHANNEL;
	TIM_handler.GPIOx = Motor2_B_GPIO;
	TIM_handler.GPIO_Pinx = Motor2_B_GPIO_PIN;
	TIM_handler.GPIO_AlternateFunctionx = Motor2_B_GPIO_AF;
	TIM_handler.Frequency = PWM_FREQUENCY;

	TIMx_PWM_Init(TIM_handler);
	GPIO_InitStruct.Pin = Motor2_EN_PIN;
	HAL_GPIO_Init(Motor2_EN_GPIO, &GPIO_InitStruct);
#endif
#ifdef MOTOR3
	TIM_handler.TIMx = Motor3_A_TIM;
	TIM_handler.TIM_channelx = Motor3_A_TIM_CHANNEL;
	TIM_handler.GPIOx = Motor3_A_GPIO;
	TIM_handler.GPIO_Pinx = Motor3_A_GPIO_PIN;
	TIM_handler.GPIO_AlternateFunctionx = Motor3_A_GPIO_AF;
	TIM_handler.Frequency = PWM_FREQUENCY;

	TIMx_PWM_Init(TIM_handler);

	TIM_handler.TIMx = Motor3_B_TIM;
	TIM_handler.TIM_channelx = Motor3_B_TIM_CHANNEL;
	TIM_handler.GPIOx = Motor3_B_GPIO;
	TIM_handler.GPIO_Pinx = Motor3_B_GPIO_PIN;
	TIM_handler.GPIO_AlternateFunctionx = Motor3_B_GPIO_AF;
	TIM_handler.Frequency = PWM_FREQUENCY;

	TIMx_PWM_Init(TIM_handler);
	GPIO_InitStruct.Pin = Motor3_EN_PIN;
	HAL_GPIO_Init(Motor3_EN_GPIO, &GPIO_InitStruct);
#endif
#ifdef MOTOR4
	TIM_handler.TIMx = Motor4_A_TIM;
	TIM_handler.TIM_channelx = Motor4_A_TIM_CHANNEL;
	TIM_handler.GPIOx = Motor4_A_GPIO;
	TIM_handler.GPIO_Pinx = Motor4_A_GPIO_PIN;
	TIM_handler.GPIO_AlternateFunctionx = Motor4_A_GPIO_AF;
	TIM_handler.Frequency = PWM_FREQUENCY;

	TIMx_PWM_Init(TIM_handler);

	TIM_handler.TIMx = Motor4_B_TIM;
	TIM_handler.TIM_channelx = Motor4_B_TIM_CHANNEL;
	TIM_handler.GPIOx = Motor4_B_GPIO;
	TIM_handler.GPIO_Pinx = Motor4_B_GPIO_PIN;
	TIM_handler.GPIO_AlternateFunctionx = Motor4_B_GPIO_AF;
	TIM_handler.Frequency = PWM_FREQUENCY;

	TIMx_PWM_Init(TIM_handler);
	GPIO_InitStruct.Pin = Motor4_EN_PIN;
	HAL_GPIO_Init(Motor4_EN_GPIO, &GPIO_InitStruct);
#endif
}

void Motor_Start(void)
{
	TIM_PWM_Typedef TIM_handler = {0};

#ifdef MOTOR1
	TIM_handler.TIMx = Motor1_A_TIM;
	TIM_handler.TIM_channelx = Motor1_A_TIM_CHANNEL;

	TIMx_PWM_Start(TIM_handler);

	TIM_handler.TIMx = Motor1_B_TIM;
	TIM_handler.TIM_channelx = Motor1_B_TIM_CHANNEL;

	TIMx_PWM_Start(TIM_handler);
	HAL_GPIO_WritePin(Motor1_EN_GPIO,Motor1_EN_PIN,1);
#endif
#ifdef MOTOR2
	TIM_handler.TIMx = Motor2_A_TIM;
	TIM_handler.TIM_channelx = Motor2_A_TIM_CHANNEL;

	TIMx_PWM_Start(TIM_handler);

	TIM_handler.TIMx = Motor2_B_TIM;
	TIM_handler.TIM_channelx = Motor2_B_TIM_CHANNEL;

	TIMx_PWM_Start(TIM_handler);
	HAL_GPIO_WritePin(Motor2_EN_GPIO,Motor2_EN_PIN,1);
#endif
#ifdef MOTOR3
	TIM_handler.TIMx = Motor3_A_TIM;
	TIM_handler.TIM_channelx = Motor3_A_TIM_CHANNEL;

	TIMx_PWM_Start(TIM_handler);

	TIM_handler.TIMx = Motor3_B_TIM;
	TIM_handler.TIM_channelx = Motor3_B_TIM_CHANNEL;

	TIMx_PWM_Start(TIM_handler);
	HAL_GPIO_WritePin(Motor3_EN_GPIO,Motor3_EN_PIN,1);
#endif
#ifdef MOTOR4
	TIM_handler.TIMx = Motor4_A_TIM;
	TIM_handler.TIM_channelx = Motor4_A_TIM_CHANNEL;

	TIMx_PWM_Start(TIM_handler);

	TIM_handler.TIMx = Motor4_B_TIM;
	TIM_handler.TIM_channelx = Motor4_B_TIM_CHANNEL;

	TIMx_PWM_Start(TIM_handler);
	HAL_GPIO_WritePin(Motor4_EN_GPIO,Motor4_EN_PIN,1);
#endif
}

void Motor_Stop(void)
{
	TIM_PWM_Typedef TIM_handler = {0};

#ifdef MOTOR1
	TIM_handler.TIMx = Motor1_A_TIM;
	TIM_handler.TIM_channelx = Motor1_A_TIM_CHANNEL;

	TIMx_PWM_Stop(TIM_handler);

	TIM_handler.TIMx = Motor1_B_TIM;
	TIM_handler.TIM_channelx = Motor1_B_TIM_CHANNEL;

	TIMx_PWM_Stop(TIM_handler);
#endif
#ifdef MOTOR2
	TIM_handler.TIMx = Motor2_A_TIM;
	TIM_handler.TIM_channelx = Motor2_A_TIM_CHANNEL;

	TIMx_PWM_Stop(TIM_handler);

	TIM_handler.TIMx = Motor2_B_TIM;
	TIM_handler.TIM_channelx = Motor2_B_TIM_CHANNEL;

	TIMx_PWM_Stop(TIM_handler);
#endif
#ifdef MOTOR3
	TIM_handler.TIMx = Motor3_A_TIM;
	TIM_handler.TIM_channelx = Motor3_A_TIM_CHANNEL;

	TIMx_PWM_Stop(TIM_handler);

	TIM_handler.TIMx = Motor3_B_TIM;
	TIM_handler.TIM_channelx = Motor3_B_TIM_CHANNEL;

	TIMx_PWM_Stop(TIM_handler);
#endif
#ifdef MOTOR4
	TIM_handler.TIMx = Motor4_A_TIM;
	TIM_handler.TIM_channelx = Motor4_A_TIM_CHANNEL;

	TIMx_PWM_Stop(TIM_handler);

	TIM_handler.TIMx = Motor4_B_TIM;
	TIM_handler.TIM_channelx = Motor4_B_TIM_CHANNEL;

	TIMx_PWM_Stop(TIM_handler);
#endif
}

void Motorx_Set_Speed(void)
{
	TIM_PWM_Typedef TIM_handler = {0};
	WheelSpeed_Typedef Calculated_wheel_speeds;

	Read_Calculated_Wheel_Speeds(&Calculated_wheel_speeds);

	if(Calculated_wheel_speeds.WheelSpeed_1 > 100)
	{
		Calculated_wheel_speeds.WheelSpeed_1 = 100;
	}
	else if(Calculated_wheel_speeds.WheelSpeed_1 < (-100))
	{
		Calculated_wheel_speeds.WheelSpeed_1 = -100;
	}
	if(Calculated_wheel_speeds.WheelSpeed_2 > 100)
	{
		Calculated_wheel_speeds.WheelSpeed_2 = 100;
	}
	else if(Calculated_wheel_speeds.WheelSpeed_2 < (-100))
	{
		Calculated_wheel_speeds.WheelSpeed_2 = -100;
	}
	if(Calculated_wheel_speeds.WheelSpeed_3 > 100)
	{
		Calculated_wheel_speeds.WheelSpeed_3 = 100;
	}
	else if(Calculated_wheel_speeds.WheelSpeed_3 < (-100))
	{
		Calculated_wheel_speeds.WheelSpeed_3 = -100;
	}
	if(Calculated_wheel_speeds.WheelSpeed_4 > 100)
	{
		Calculated_wheel_speeds.WheelSpeed_4 = 100;
	}
	else if(Calculated_wheel_speeds.WheelSpeed_4 < (-100))
	{
		Calculated_wheel_speeds.WheelSpeed_4 = -100;
	}

	if(ZERO_SPEED <= Calculated_wheel_speeds.WheelSpeed_1)
	{
		TIM_handler.TIMx = Motor1_A_TIM;
		TIM_handler.TIM_channelx = Motor1_A_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;

		TIM_handler.Duty_Cicle = (uint8_t)Calculated_wheel_speeds.WheelSpeed_1;
		Change_PWM_Pulse(TIM_handler);

		TIM_handler.TIMx = Motor1_B_TIM;
		TIM_handler.TIM_channelx = Motor1_B_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = 0;
		Change_PWM_Pulse(TIM_handler);
	}
	else
	{
		TIM_handler.TIMx = Motor1_A_TIM;
		TIM_handler.TIM_channelx = Motor1_A_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;

		TIM_handler.Duty_Cicle = 0;
		Change_PWM_Pulse(TIM_handler);

		TIM_handler.TIMx = Motor1_B_TIM;
		TIM_handler.TIM_channelx = Motor1_B_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = (uint8_t)(Calculated_wheel_speeds.WheelSpeed_1 * -1);
		Change_PWM_Pulse(TIM_handler);
	}

#ifdef MOTOR2
	if(ZERO_SPEED <= Calculated_wheel_speeds.WheelSpeed_2)
	{
		TIM_handler.TIMx = Motor2_A_TIM;
		TIM_handler.TIM_channelx = Motor2_A_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = (uint8_t)Calculated_wheel_speeds.WheelSpeed_2;
		Change_PWM_Pulse(TIM_handler);

		TIM_handler.TIMx = Motor2_B_TIM;
		TIM_handler.TIM_channelx = Motor2_B_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = 0;
		Change_PWM_Pulse(TIM_handler);
	}
	else
	{
		TIM_handler.TIMx = Motor2_A_TIM;
		TIM_handler.TIM_channelx = Motor2_A_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = 0;
		Change_PWM_Pulse(TIM_handler);

		TIM_handler.TIMx = Motor2_B_TIM;
		TIM_handler.TIM_channelx = Motor2_B_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = (Calculated_wheel_speeds.WheelSpeed_2 * -1);
		Change_PWM_Pulse(TIM_handler);
	}
#endif
#ifdef MOTOR3
	if(ZERO_SPEED <= Calculated_wheel_speeds.WheelSpeed_3)
	{
		TIM_handler.TIMx = Motor3_A_TIM;
		TIM_handler.TIM_channelx = Motor3_A_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = (uint8_t)Calculated_wheel_speeds.WheelSpeed_3;
		Change_PWM_Pulse(TIM_handler);

		TIM_handler.TIMx = Motor3_B_TIM;
		TIM_handler.TIM_channelx = Motor3_B_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = 0;
		Change_PWM_Pulse(TIM_handler);
	}
	else
	{
		TIM_handler.TIMx = Motor3_A_TIM;
		TIM_handler.TIM_channelx = Motor3_A_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = 0;
		Change_PWM_Pulse(TIM_handler);

		TIM_handler.TIMx = Motor3_B_TIM;
		TIM_handler.TIM_channelx = Motor3_B_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = (Calculated_wheel_speeds.WheelSpeed_3 * -1);
		Change_PWM_Pulse(TIM_handler);
	}
#endif
#ifdef MOTOR4
	if(ZERO_SPEED <= Calculated_wheel_speeds.WheelSpeed_4)
	{
		TIM_handler.TIMx = Motor4_A_TIM;
		TIM_handler.TIM_channelx = Motor4_A_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = (uint8_t)Calculated_wheel_speeds.WheelSpeed_4;
		Change_PWM_Pulse(TIM_handler);

		TIM_handler.TIMx = Motor4_B_TIM;
		TIM_handler.TIM_channelx = Motor4_B_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = 0;
		Change_PWM_Pulse(TIM_handler);
	}
	else
	{
		TIM_handler.TIMx = Motor4_A_TIM;
		TIM_handler.TIM_channelx = Motor4_A_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = 0;
		Change_PWM_Pulse(TIM_handler);

		TIM_handler.TIMx = Motor4_B_TIM;
		TIM_handler.TIM_channelx = Motor4_B_TIM_CHANNEL;
		TIM_handler.Frequency = PWM_FREQUENCY;
		TIM_handler.Duty_Cicle = (uint8_t)(Calculated_wheel_speeds.WheelSpeed_4 * -1);
		Change_PWM_Pulse(TIM_handler);
	}
#endif


}
