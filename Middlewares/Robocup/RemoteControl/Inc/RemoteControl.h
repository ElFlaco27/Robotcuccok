/*
 * RemoteControl.h
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#ifndef REMOTECONTROL_INC_REMOTECONTROL_H_
#define REMOTECONTROL_INC_REMOTECONTROL_H_

#include "variation.h"

#ifdef HUMAN_CONTROLLED
typedef struct
{
	float Speed_X;
	float Speed_Y;
	float Angular_Speed;
}RobotSpeed_Typedef;

#define MAX_SPEED				((float)100)
#define MIN_SPEED				((float)-100)
#define SPEED_RANGE				(float)((MAX_SPEED)-(MIN_SPEED))

#define CALIBRATION_START		0u
#define CALIBRATION_CH1_MAX 	1u
#define CALIBRATION_CH1_MIN 	2u
#define CALIBRATION_CH2_MAX 	4u
#define CALIBRATION_CH2_MIN 	5u
#define CALIBRATION_CH3_MAX 	7u
#define CALIBRATION_CH3_MIN 	8u
#define CALIBRATION_DONE 		10u

#define TRUE					1u
#define FALSE					0u

void Provide_Robot_Speed(void);
void Remote_Control_init(void);
void Calibrate_Remote_Control(void);
#endif

#endif /* REMOTECONTROL_INC_REMOTECONTROL_H_ */
