/*
 * Initialize_System.c
 *
 *  Created on: Apr 21, 2020
 *      Author: dimagic
 */

#include "Initialize_System.h"

TIM_HandleTypeDef htim1;

void Init_System_Startup(void)
{
	Remote_Control_init();
	Init_Wheel_Speed_Provision();
	//Motor_Init();
	//Motor_Start();
	//Calibrate_Remote_Control();
}
