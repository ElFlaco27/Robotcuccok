/*
 * Common_Data.c
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#include "Common_Data.h"

uint32_t Timer_IC_Channel1_Raw_data;
uint32_t Timer_IC_Channel2_Raw_data;
uint32_t Timer_IC_Channel3_Raw_data;

uint8_t Button_Pressed;

uint32_t RemoteControl_CH1_Max;
uint32_t RemoteControl_CH1_Min;
uint32_t RemoteControl_CH2_Max;
uint32_t RemoteControl_CH2_Min;
uint32_t RemoteControl_CH3_Max;
uint32_t RemoteControl_CH3_Min;
RobotSpeed_Typedef RemoteControl_Provided_Robot_Speed;

WheelSpeed_Typedef WheelSpeedCalculation_Calculated_WheelSpeeds;



void Read_IC_Channel1_Raw_data(uint32_t * data)
{
	(* data) = Timer_IC_Channel1_Raw_data;
}

void Write_IC_Channel1_Raw_data(uint32_t * data)
{
	Timer_IC_Channel1_Raw_data = (* data);
}

void Read_IC_Channel2_Raw_data(uint32_t * data)
{
	(* data) = Timer_IC_Channel2_Raw_data;
}

void Write_IC_Channel2_Raw_data(uint32_t * data)
{
	Timer_IC_Channel2_Raw_data = (* data);
}

void Read_IC_Channel3_Raw_data(uint32_t * data)
{
	(* data) = Timer_IC_Channel3_Raw_data;
}

void Write_IC_Channel3_Raw_data(uint32_t * data)
{
	Timer_IC_Channel3_Raw_data = (* data);
}

void Read_Button_Pressed(uint8_t * data)
{
	(* data) = Button_Pressed;
}

void Write_Button_Pressed(uint8_t * data)
{
	Button_Pressed = (* data);
}

void Read_RC_CH1_Max(uint32_t * data)
{
	 (* data) = RemoteControl_CH1_Max;
}

void Write_RC_CH1_Max(uint32_t * data)
{
	RemoteControl_CH1_Max = (* data);
}

void Read_RC_CH1_Min(uint32_t * data)
{
	 (* data) = RemoteControl_CH1_Min;
}

void Write_RC_CH1_Min(uint32_t * data)
{
	RemoteControl_CH1_Min = (* data);
}

void Read_RC_CH2_Max(uint32_t * data)
{
	 (* data) = RemoteControl_CH2_Max;
}

void Write_RC_CH2_Max(uint32_t * data)
{
	RemoteControl_CH2_Max = (* data);
}

void Read_RC_CH2_Min(uint32_t * data)
{
	 (* data) = RemoteControl_CH2_Min;
}

void Write_RC_CH2_Min(uint32_t * data)
{
	RemoteControl_CH2_Min = (* data);
}

void Read_RC_CH3_Max(uint32_t * data)
{
	 (* data) = RemoteControl_CH3_Max;
}

void Write_RC_CH3_Max(uint32_t * data)
{
	RemoteControl_CH3_Max = (* data);
}

void Read_RC_CH3_Min(uint32_t * data)
{
	 (* data) = RemoteControl_CH3_Min;
}

void Write_RC_CH3_Min(uint32_t * data)
{
	RemoteControl_CH3_Min = (* data);
}

void Read_Provided_Robot_Speed(RobotSpeed_Typedef * data)
{
	(* data) = RemoteControl_Provided_Robot_Speed;
}

void Write_Provided_Robot_Speed(RobotSpeed_Typedef * data)
{
	RemoteControl_Provided_Robot_Speed = (* data);
}


void Read_Calculated_Wheel_Speeds(WheelSpeed_Typedef * data)
{
	(* data) = WheelSpeedCalculation_Calculated_WheelSpeeds;
}

void Write_Calculated_Wheel_Speeds(WheelSpeed_Typedef * data)
{
	WheelSpeedCalculation_Calculated_WheelSpeeds = (* data);
}

