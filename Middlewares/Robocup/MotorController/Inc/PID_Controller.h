/*
 * PID_Controller.h
 *
 *  Created on: Jan 21, 2021
 *      Author: dimagic
 */

#ifndef ROBOCUP_MOTORCONTROLLER_INC_PID_CONTROLLER_H_
#define ROBOCUP_MOTORCONTROLLER_INC_PID_CONTROLLER_H_

#define HOLT_IDO		(float)0.004
#define FELFUTASI_IDO	(float)0.044

#define PROPORTIONAL 	(float)((float)(FELFUTASI_IDO / HOLT_IDO) * 0.8)
#define INTEGRAL		(float)(HOLT_IDO * 3)
#define DIFFERENTIAL 	(float)(HOLT_IDO * 0.5)

void PID_Controller(void);

#endif /* ROBOCUP_MOTORCONTROLLER_INC_PID_CONTROLLER_H_ */
