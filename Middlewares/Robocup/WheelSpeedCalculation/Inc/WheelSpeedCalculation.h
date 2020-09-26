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


typedef struct
{
	float 	param1;
	float 	param2;
	uint8_t Radius;
}ConversionMatrix_Typedef;

#define WHEEL_RADIUS	5u
#define ROBOT_RADIUS	10u
#define WHEEL_ANGLE_1	45u
#define WHEEL_ANGLE_2	135u
#define WHEEL_ANGLE_3	225u
#define WHEEL_ANGLE_4	315u
#define WHEEL_ANGLE_RAD_1	(float)WHEEL_ANGLE_1*DEG_TO_RAD_RATE
#define WHEEL_ANGLE_RAD_2	(float)WHEEL_ANGLE_2*DEG_TO_RAD_RATE
#define WHEEL_ANGLE_RAD_3	(float)WHEEL_ANGLE_3*DEG_TO_RAD_RATE
#define WHEEL_ANGLE_RAD_4	(float)WHEEL_ANGLE_4*DEG_TO_RAD_RATE

#define DEG_TO_RAD_RATE	(float)0.0174533


void Calculate_Wheel_Speeds(void);

#endif /* WHEELSPEEDCALCULATION_INC_WHEELSPEEDCALCULATION_H_ */
