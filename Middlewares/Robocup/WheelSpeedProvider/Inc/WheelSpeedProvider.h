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


#define MOT_TO_WHEEL_RATIO	5u

#define DEG_TO_RAD_RATE	(float)0.0174533

void Init_Wheel_Speed_Provision(void);


void Provide_Wheel_Speeds(void);

#endif /* WHEELSPEEDPROVIDER_INC_WHEELSPEEDPROVIDER_H_ */
