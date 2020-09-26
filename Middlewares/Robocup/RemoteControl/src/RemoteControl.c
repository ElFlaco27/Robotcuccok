/*
 * RemoteControl.c
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */


#include "RemoteControl.h"
#include "Common_Data.h"
#include "MotorController.h"
#include "Timer_InputCapture.h"
#include "Port_config.h"

TIM_IC_Typedef config;

void Provide_Robot_Speed(void)
{
	uint32_t Channel1_raw_data;
	uint32_t Channel1_MAX;
	uint32_t Channel1_MIN;
	uint32_t Channel1_Range;
	uint32_t Channel2_raw_data;
	uint32_t Channel2_MAX;
	uint32_t Channel2_MIN;
	uint32_t Channel2_Range;
	uint32_t Channel3_raw_data;
	uint32_t Channel3_MAX;
	uint32_t Channel3_MIN;
	uint32_t Channel3_Range;
	RobotSpeed_Typedef Requested_Robot_Speed;

	Read_RC_CH1_Max(&Channel1_MAX);
	Read_RC_CH1_Min(&Channel1_MIN);
	Read_IC_Channel1_Raw_data(&Channel1_raw_data);
	Read_RC_CH2_Max(&Channel2_MAX);
	Read_RC_CH2_Min(&Channel2_MIN);
	Read_IC_Channel2_Raw_data(&Channel2_raw_data);
	Read_RC_CH3_Max(&Channel3_MAX);
	Read_RC_CH3_Min(&Channel3_MIN);
	Read_IC_Channel3_Raw_data(&Channel3_raw_data);

	Channel1_Range = (Channel1_MAX - Channel1_MIN);
	Channel2_Range = (Channel2_MAX - Channel2_MIN);
	Channel3_Range = (Channel3_MAX - Channel3_MIN);

	if(Channel1_MAX < Channel1_raw_data)
	{
		Channel1_raw_data = Channel1_MAX;
	}
	else if(Channel1_MIN > Channel1_raw_data)
	{
		Channel1_raw_data = Channel1_MIN;
	}

	if(Channel2_MAX < Channel2_raw_data)
	{
		Channel2_raw_data = Channel2_MAX;
	}
	else if(Channel2_MIN > Channel2_raw_data)
	{
		Channel2_raw_data = Channel2_MIN;
	}

	if(Channel2_MAX < Channel2_raw_data)
	{
		Channel2_raw_data = Channel2_MAX;
	}
	else if(Channel2_MIN > Channel2_raw_data)
	{
		Channel2_raw_data = Channel2_MIN;
	}
	Requested_Robot_Speed.Speed_X = (((Channel1_raw_data - Channel1_MIN) * SPEED_RANGE) / Channel1_Range) + MIN_SPEED;
	Requested_Robot_Speed.Speed_Y = (((Channel2_raw_data - Channel2_MIN) * SPEED_RANGE) / Channel2_Range) + MIN_SPEED;
	Requested_Robot_Speed.Angular_Speed = (float)((float)((float)(Channel3_raw_data - Channel3_MIN) * SPEED_RANGE) / Channel3_Range) + MIN_SPEED;

	Write_Provided_Robot_Speed(&Requested_Robot_Speed);

}

void Remote_Control_init(void)
{
	config.TIMx = IC_1_TIM;
	config.TIM_channelx = IC_1_TIM_CHANNEL;
	config.TIMx_IRQ = IC_1_IRQn;
	config.GPIOx = IC_1_GPIO;
	config.GPIO_Pinx= IC_1_GPIO_PIN;
	config.GPIO_AlternateFunctionx = IC_1_GPIO_AF;
	TIMx_IC_Init(config);
	TIMx_IC_Start(config);
#if (IC_IN_USE>1)
	config.TIMx = IC_2_TIM;
	config.TIM_channelx = IC_2_TIM_CHANNEL;
	config.TIMx_IRQ = IC_2_IRQn;
	config.GPIOx = IC_2_GPIO;
	config.GPIO_Pinx= IC_2_GPIO_PIN;
	config.GPIO_AlternateFunctionx = IC_2_GPIO_AF;
	TIMx_IC_Init(config);
	TIMx_IC_Start(config);
#endif
#if (IC_IN_USE>2)
	config.TIMx = IC_3_TIM;
	config.TIM_channelx = IC_3_TIM_CHANNEL;
	config.TIMx_IRQ = IC_3_IRQn;
	config.GPIOx = IC_3_GPIO;
	config.GPIO_Pinx= IC_3_GPIO_PIN;
	config.GPIO_AlternateFunctionx = IC_3_GPIO_AF;
	TIMx_IC_Init(config);
	TIMx_IC_Start(config);
#endif
#if (IC_IN_USE>3)
	config.TIMx = IC_4_TIM;
	config.TIM_channelx = IC_4_TIM_CHANNEL;
	config.TIMx_IRQ = IC_4_IRQn;
	config.GPIOx = IC_4_GPIO;
	config.GPIO_Pinx= IC_4_GPIO_PIN;
	config.GPIO_AlternateFunctionx = IC_4_GPIO_AF;
	TIMx_IC_Init(config);
	TIMx_IC_Start(config);
#endif
#if (IC_IN_USE>4)
	config.TIMx = IC_5_TIM;
	config.TIM_channelx = IC_5_TIM_CHANNEL;
	config.TIMx_IRQ = IC_5_IRQn;
	config.GPIOx = IC_5_GPIO;
	config.GPIO_Pinx= IC_5_GPIO_PIN;
	config.GPIO_AlternateFunctionx = IC_5_GPIO_AF;
	TIMx_IC_Init(config);
	TIMx_IC_Start(config);
#endif
}

void Calibrate_Remote_Control(void)
{
	uint8_t btn_pressed;
	uint8_t calibration_State = CALIBRATION_START;
	uint32_t Channel1_raw_data;
	uint32_t Channel2_raw_data;
	uint32_t Channel3_raw_data;
	while(calibration_State != CALIBRATION_DONE)
	{
		Read_Button_Pressed(&btn_pressed);
		Read_IC_Channel1_Raw_data(&Channel1_raw_data);
		Read_IC_Channel2_Raw_data(&Channel2_raw_data);
		Read_IC_Channel3_Raw_data(&Channel3_raw_data);
		switch(calibration_State)
		{
			case CALIBRATION_START:
				calibration_State = CALIBRATION_CH1_MAX;
				break;
			case CALIBRATION_CH1_MAX:
				if(btn_pressed == TRUE)
				{
					calibration_State = CALIBRATION_CH1_MIN;
					Write_RC_CH1_Max(&Channel1_raw_data);
					btn_pressed = FALSE;
					Write_Button_Pressed(&btn_pressed);
				}
			case CALIBRATION_CH1_MIN:
				if(btn_pressed == TRUE)
				{
					calibration_State = CALIBRATION_CH2_MAX;
					Write_RC_CH1_Min(&Channel1_raw_data);
					btn_pressed = FALSE;
					Write_Button_Pressed(&btn_pressed);
				}
			case CALIBRATION_CH2_MAX:
				if(btn_pressed == TRUE)
				{
					calibration_State = CALIBRATION_CH2_MIN;
					Write_RC_CH2_Max(&Channel2_raw_data);
					btn_pressed = FALSE;
					Write_Button_Pressed(&btn_pressed);
				}
			case CALIBRATION_CH2_MIN:
				if(btn_pressed == TRUE)
				{
					calibration_State = CALIBRATION_CH3_MAX;
					Write_RC_CH2_Min(&Channel2_raw_data);
					btn_pressed = FALSE;
					Write_Button_Pressed(&btn_pressed);
				}
			case CALIBRATION_CH3_MAX:
				if(btn_pressed == TRUE)
				{
					calibration_State = CALIBRATION_CH3_MIN;
					Write_RC_CH3_Max(&Channel3_raw_data);
					btn_pressed = FALSE;
					Write_Button_Pressed(&btn_pressed);
				}
			case CALIBRATION_CH3_MIN:
				if(btn_pressed == TRUE)
				{
					calibration_State = CALIBRATION_DONE;
					Write_RC_CH3_Min(&Channel3_raw_data);
					btn_pressed = FALSE;
					Write_Button_Pressed(&btn_pressed);
				}
		}
	}

}
