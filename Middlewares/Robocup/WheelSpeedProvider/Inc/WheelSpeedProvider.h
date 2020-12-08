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


#define MOT_TO_WHEEL_RATIO	10u

#define ENCODER_COUNT	60u

#define RAD_PER_S_TO_RPM	(float)9.5492965964254
#define M_PI                (float)3.14159265358979323846

#define FORWARD_DIR 0
#define BACKWARD_DIR 0x10

void Init_Wheel_Speed_Provision(void);


void Provide_Wheel_Speeds(void);

#endif /* WHEELSPEEDPROVIDER_INC_WHEELSPEEDPROVIDER_H_ */
