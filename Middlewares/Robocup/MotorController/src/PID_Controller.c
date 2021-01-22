/*
 * PID_Controller.c
 *
 *  Created on: Jan 21, 2021
 *      Author: dimagic
 */

#include "PID_Controller.h"
#include "Common_Data.h"

float Wheel_Speed1_Integral_Error = 0;
float Wheel_Speed1_Last_Error = 0;

float Wheel_Speed2_Integral_Error = 0;
float Wheel_Speed2_Last_Error = 0;

float Wheel_Speed3_Integral_Error = 0;
float Wheel_Speed3_Last_Error = 0;

float Wheel_Speed4_Integral_Error = 0;
float Wheel_Speed4_Last_Error = 0;

void PID_Controller(void)
{
	WheelSpeed_Typedef Current_Wheel_Speed;
	WheelSpeed_Typedef Target_Wheel_Speed;
	WheelSpeed_Typedef Controlled_Wheel_Speed;
	float Wheel_Speed1_Error;
	float Wheel_Speed1_Differential_Error;
	float Wheel_Speed2_Error;
	float Wheel_Speed2_Differential_Error;
	float Wheel_Speed3_Error;
	float Wheel_Speed3_Differential_Error;
	float Wheel_Speed4_Error;
	float Wheel_Speed4_Differential_Error;

	Read_Provided_Wheel_Speeds(&Current_Wheel_Speed);
	Read_Calculated_Wheel_Speeds(&Target_Wheel_Speed);

	Wheel_Speed1_Error = Target_Wheel_Speed.WheelSpeed_1 - Current_Wheel_Speed.WheelSpeed_1;
	Wheel_Speed1_Integral_Error = Wheel_Speed1_Integral_Error + Wheel_Speed1_Error;
	Wheel_Speed1_Differential_Error = Wheel_Speed1_Error - Wheel_Speed1_Last_Error;
	Wheel_Speed1_Last_Error = Wheel_Speed1_Error;
	Controlled_Wheel_Speed.WheelSpeed_1 = 	(PROPORTIONAL * Wheel_Speed1_Error) +
											(INTEGRAL * Wheel_Speed1_Integral_Error) +
											(DIFFERENTIAL * Wheel_Speed1_Differential_Error);

	Wheel_Speed2_Error = Target_Wheel_Speed.WheelSpeed_2 - Current_Wheel_Speed.WheelSpeed_2;
	Wheel_Speed2_Integral_Error = Wheel_Speed2_Integral_Error + Wheel_Speed2_Error;
	Wheel_Speed2_Differential_Error = Wheel_Speed2_Error - Wheel_Speed2_Last_Error;
	Wheel_Speed2_Last_Error = Wheel_Speed2_Error;
	Controlled_Wheel_Speed.WheelSpeed_2 = 	(PROPORTIONAL * Wheel_Speed2_Error) +
											(INTEGRAL * Wheel_Speed2_Integral_Error) +
											(DIFFERENTIAL * Wheel_Speed2_Differential_Error);

	Wheel_Speed3_Error = Target_Wheel_Speed.WheelSpeed_3 - Current_Wheel_Speed.WheelSpeed_3;
	Wheel_Speed3_Integral_Error = Wheel_Speed3_Integral_Error + Wheel_Speed3_Error;
	Wheel_Speed3_Differential_Error = Wheel_Speed3_Error - Wheel_Speed3_Last_Error;
	Wheel_Speed3_Last_Error = Wheel_Speed3_Error;
	Controlled_Wheel_Speed.WheelSpeed_3 = 	(PROPORTIONAL * Wheel_Speed3_Error) +
											(INTEGRAL * Wheel_Speed3_Integral_Error) +
											(DIFFERENTIAL * Wheel_Speed3_Differential_Error);

	Wheel_Speed4_Error = Target_Wheel_Speed.WheelSpeed_4 - Current_Wheel_Speed.WheelSpeed_4;
	Wheel_Speed4_Integral_Error = Wheel_Speed4_Integral_Error + Wheel_Speed4_Error;
	Wheel_Speed4_Differential_Error = Wheel_Speed4_Error - Wheel_Speed4_Last_Error;
	Wheel_Speed4_Last_Error = Wheel_Speed4_Error;
	Controlled_Wheel_Speed.WheelSpeed_4 = 	(PROPORTIONAL * Wheel_Speed4_Error) +
											(INTEGRAL * Wheel_Speed4_Integral_Error) +
											(DIFFERENTIAL * Wheel_Speed4_Differential_Error);

	Write_Controlled_Wheel_Speeds(&Controlled_Wheel_Speed);

}
