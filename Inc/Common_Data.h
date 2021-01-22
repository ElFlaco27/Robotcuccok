/*
 * Common_Data.h
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#ifndef COMMON_DATA_H_
#define COMMON_DATA_H_

#include "stm32l4xx_hal.h"
#include "variation.h"
#include "RemoteControl.h"
#include "WheelSpeedCalculation.h"

#ifdef HUMAN_CONTROLLED

void Read_IC_Channel1_Raw_data(uint32_t * data);
void Write_IC_Channel1_Raw_data(uint32_t * data);
void Read_IC_Channel2_Raw_data(uint32_t * data);
void Write_IC_Channel2_Raw_data(uint32_t * data);
void Read_IC_Channel3_Raw_data(uint32_t * data);
void Write_IC_Channel3_Raw_data(uint32_t * data);

void Read_Button_Pressed(uint8_t * data);
void Write_Button_Pressed(uint8_t * data);

void Write_RC_CH1_Max(uint32_t * data);
void Read_RC_CH1_Max(uint32_t * data);
void Write_RC_CH1_Min(uint32_t * data);
void Read_RC_CH1_Min(uint32_t * data);
void Write_RC_CH2_Max(uint32_t * data);
void Read_RC_CH2_Max(uint32_t * data);
void Write_RC_CH2_Min(uint32_t * data);
void Read_RC_CH2_Min(uint32_t * data);
void Write_RC_CH3_Max(uint32_t * data);
void Read_RC_CH3_Max(uint32_t * data);
void Write_RC_CH3_Min(uint32_t * data);
void Read_RC_CH3_Min(uint32_t * data);
void Write_Provided_Robot_Speed(RobotSpeed_Typedef * data);
void Read_Provided_Robot_Speed(RobotSpeed_Typedef * data);
void Write_Received_Robot_Speed(RobotSpeed_Typedef * data);
void Read_Received_Robot_Speed(RobotSpeed_Typedef * data);
void Write_Transmit_Enabled(uint8_t * data);
void Read_Transmit_Enabled(uint8_t * data);
void Write_Wifi_Connected(uint8_t * data);
void Read_Wifi_Connected(uint8_t * data);
void Write_Connection_Estabilished(uint8_t * data);
void Read_Connection_Estabilished(uint8_t * data);

void Read_Calculated_Wheel_Speeds(WheelSpeed_Typedef * data);
void Write_Calculated_Wheel_Speeds(WheelSpeed_Typedef * data);

void Read_Provided_Wheel_Speeds(WheelSpeed_Typedef * data);
void Write_Provided_Wheel_Speeds(WheelSpeed_Typedef * data);

void Read_Controlled_Wheel_Speeds(WheelSpeed_Typedef * data);
void Write_Controlled_Wheel_Speeds(WheelSpeed_Typedef * data);

#endif


#endif /* COMMON_DATA_H_ */
