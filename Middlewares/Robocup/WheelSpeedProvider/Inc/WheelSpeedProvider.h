/*
 * WheelSpeedProvider.h
 *
 *  Created on: Sep 26, 2020
 *      Author: dimagic
 */

#ifndef WHEELSPEEDPROVIDER_INC_WHEELSPEEDPROVIDER_H_
#define WHEELSPEEDPROVIDER_INC_WHEELSPEEDPROVIDER_H_

#include "stm32l4xx_hal.h"
#include "Timer_encoder.h"
#include "MotorController.h"
#include "Port_config.h"
#include "WheelSpeedCalculation.h"

typedef struct
{
	float Speed;
	uint8_t debug;
}debug_struct;


#define MOT_TO_WHEEL_RATIO	(float)14.37
#define WHEEL_RADIUS		(float)0.0175

#define ENCODER_COUNT				(uint8_t)60u
#define ENCODER_PERIOD 				(float)0.002
#define ENCODER_COUNT_PER_MINUTE 	(float)(1 / ENCODER_PERIOD)
#define ENCODER_COUNT_TO_RPM		(float)((ENCODER_COUNT_PER_MINUTE / 2) / MOT_TO_WHEEL_RATIO)
#define RPM_TO_ANG_SPD				(float)(RPM_TO_RAD_PER_S * ENCODER_COUNT_TO_RPM)
#define ANG_SPD_TO_METER_PER_SEC 	(float)(RPM_TO_ANG_SPD * WHEEL_RADIUS)

#define RAD_PER_S_TO_RPM			(float)(SECOND_IN_MINUTE / (2*M_PI))
#define RPM_TO_RAD_PER_S			(float)(1 / RAD_PER_S_TO_RPM)
#define M_PI                		(float)3.14159265358979323846
#define SECOND_IN_MINUTE			(uint8_t)60

#define FORWARD_DIR 				(uint8_t)0
#define BACKWARD_DIR 				(uint8_t)0x10

#define POSITIVE 					(uint8_t)1
#define NEGATIVE 					(int)-1

#define MIN_LIMIT					(uint8_t)0
#define MAX_LIMIT					(uint8_t)+40


void Init_Wheel_Speed_Provision(void);



void Provide_Wheel_Speeds(void);

#endif /* WHEELSPEEDPROVIDER_INC_WHEELSPEEDPROVIDER_H_ */
