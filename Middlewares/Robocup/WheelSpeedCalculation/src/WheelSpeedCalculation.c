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
	ConversionMatrix_Typedef conversion_matrix[4];
	RobotSpeed_Typedef Robot_speed;

	Read_Provided_Robot_Speed(&Robot_speed);
	conversion_matrix[0].param1 = (float)(-1*sin(WHEEL_ANGLE_RAD_1));
	conversion_matrix[0].param2 = (float)(cos(WHEEL_ANGLE_RAD_1));
	conversion_matrix[0].Radius = ROBOT_RADIUS;
	conversion_matrix[1].param1 = (float)(-1*sin(WHEEL_ANGLE_RAD_2));
	conversion_matrix[1].param2 = (float)(cos(WHEEL_ANGLE_RAD_2));
	conversion_matrix[1].Radius = ROBOT_RADIUS;
	conversion_matrix[2].param1 = (float)(-1*sin(WHEEL_ANGLE_RAD_3));
	conversion_matrix[2].param2 = (float)(cos(WHEEL_ANGLE_RAD_3));
	conversion_matrix[2].Radius = ROBOT_RADIUS;
	conversion_matrix[3].param1 = (float)(-1*sin(WHEEL_ANGLE_RAD_4));
	conversion_matrix[3].param2 = (float)(cos(WHEEL_ANGLE_RAD_4));
	conversion_matrix[3].Radius = ROBOT_RADIUS;

	Calculated_wheel_speeds.WheelSpeed_1 = 	((conversion_matrix[0].param1 * Robot_speed.Speed_X) +
											(conversion_matrix[0].param2 * Robot_speed.Speed_Y) +
											(conversion_matrix[0].Radius * Robot_speed.Angular_Speed))/WHEEL_RADIUS;

	Calculated_wheel_speeds.WheelSpeed_2 = 	((conversion_matrix[1].param1 * Robot_speed.Speed_X) +
											(conversion_matrix[1].param2 * Robot_speed.Speed_Y) +
											(conversion_matrix[1].Radius * Robot_speed.Angular_Speed))/WHEEL_RADIUS;

	Calculated_wheel_speeds.WheelSpeed_3 = 	((conversion_matrix[2].param1 * Robot_speed.Speed_X) +
											(conversion_matrix[2].param2 * Robot_speed.Speed_Y) +
											(conversion_matrix[2].Radius * Robot_speed.Angular_Speed))/WHEEL_RADIUS;

	Calculated_wheel_speeds.WheelSpeed_4 = 	((conversion_matrix[3].param1 * Robot_speed.Speed_X) +
											(conversion_matrix[3].param2 * Robot_speed.Speed_Y) +
											(conversion_matrix[3].Radius * Robot_speed.Angular_Speed))/WHEEL_RADIUS;

	Write_Calculated_Wheel_Speeds(&Calculated_wheel_speeds);

}
