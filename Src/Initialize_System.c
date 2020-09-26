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
	htim1.Instance = TIM1;
	//Remote_Control_init();
	Motor_Init();
	Motor_Start();
	//Calibrate_Remote_Control();
}
