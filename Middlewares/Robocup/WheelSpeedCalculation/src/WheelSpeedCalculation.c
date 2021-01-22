/*
 * WheelSpeedCalculation.c
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#include "WheelSpeedCalculation.h"
#include "Common_Data.h"
#include <math.h>

void Calculate_Wheel_Speeds(void)
{
	WheelSpeed_Typedef Calculated_wheel_speeds;
	RobotSpeed_Typedef Robot_speed;

	Read_Received_Robot_Speed(&Robot_speed);


	Calculated_wheel_speeds.WheelSpeed_1 = 	((WHEEL_1_PARAMETER_1 * Robot_speed.Speed_X) +
											(WHEEL_1_PARAMETER_2 * Robot_speed.Speed_Y) +
											(ROBOT_RADIUS * Robot_speed.Angular_Speed));

	Calculated_wheel_speeds.WheelSpeed_2 = 	((WHEEL_2_PARAMETER_1 * Robot_speed.Speed_X) +
											(WHEEL_2_PARAMETER_2 * Robot_speed.Speed_Y) +
											(ROBOT_RADIUS * Robot_speed.Angular_Speed));

	Calculated_wheel_speeds.WheelSpeed_3 = 	((WHEEL_3_PARAMETER_1 * Robot_speed.Speed_X) +
											(WHEEL_3_PARAMETER_2 * Robot_speed.Speed_Y) +
											(ROBOT_RADIUS * Robot_speed.Angular_Speed));

	Calculated_wheel_speeds.WheelSpeed_4 = 	((WHEEL_4_PARAMETER_1 * Robot_speed.Speed_X) +
											(WHEEL_4_PARAMETER_2 * Robot_speed.Speed_Y) +
											(ROBOT_RADIUS * Robot_speed.Angular_Speed));

	Write_Calculated_Wheel_Speeds(&Calculated_wheel_speeds);

}
