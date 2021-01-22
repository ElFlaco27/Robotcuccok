/*
 * WheelSpeedCalculation.h
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#ifndef WHEELSPEEDCALCULATION_INC_WHEELSPEEDCALCULATION_H_
#define WHEELSPEEDCALCULATION_INC_WHEELSPEEDCALCULATION_H_

#include "stm32l4xx_hal.h"
#include "RemoteControl.h"

typedef struct
{
	float WheelSpeed_1;
	float WheelSpeed_2;
	float WheelSpeed_3;
	float WheelSpeed_4;
}WheelSpeed_Typedef;


#define WHEEL_RADIUS		(float)0.0175f
#define ROBOT_RADIUS		(float)0.075f
#define WHEEL_ANGLE_1		(uint8_t)45u
#define WHEEL_ANGLE_2		(uint8_t)135u
#define WHEEL_ANGLE_3		(uint8_t)225u
#define WHEEL_ANGLE_4		(uint8_t)315u
#define WHEEL_ANGLE_RAD_1	(float)((float)WHEEL_ANGLE_1 * DEG_TO_RAD_RATE)
#define WHEEL_ANGLE_RAD_2	(float)((float)WHEEL_ANGLE_2 * DEG_TO_RAD_RATE)
#define WHEEL_ANGLE_RAD_3	(float)((float)WHEEL_ANGLE_3 * DEG_TO_RAD_RATE)
#define WHEEL_ANGLE_RAD_4	(float)((float)WHEEL_ANGLE_4 * DEG_TO_RAD_RATE)

#define DEG_TO_RAD_RATE		(float)0.0174533

#define WHEEL_1_PARAMETER_1 (float)(-1*sin(WHEEL_ANGLE_RAD_1))
#define WHEEL_1_PARAMETER_2 (float)(cos(WHEEL_ANGLE_RAD_1))
#define WHEEL_2_PARAMETER_1 (float)(-1*sin(WHEEL_ANGLE_RAD_2))
#define WHEEL_2_PARAMETER_2 (float)(cos(WHEEL_ANGLE_RAD_2))
#define WHEEL_3_PARAMETER_1 (float)(-1*sin(WHEEL_ANGLE_RAD_3))
#define WHEEL_3_PARAMETER_2 (float)(cos(WHEEL_ANGLE_RAD_3))
#define WHEEL_4_PARAMETER_1 (float)(-1*sin(WHEEL_ANGLE_RAD_4))
#define WHEEL_4_PARAMETER_2 (float)(cos(WHEEL_ANGLE_RAD_4))


void Calculate_Wheel_Speeds(void);

#endif /* WHEELSPEEDCALCULATION_INC_WHEELSPEEDCALCULATION_H_ */
