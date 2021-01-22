/*
 * CommunicationRxWrapper.h
 *
 *  Created on: Jan 19, 2021
 *      Author: dimagic
 */

#ifndef ROBOCUP_COMMUNICATIONHANDLER_INC_COMMUNICATIONRXWRAPPER_H_
#define ROBOCUP_COMMUNICATIONHANDLER_INC_COMMUNICATIONRXWRAPPER_H_

#define MESSAGE_INIT 			(uint8_t) 0xAA
#define MESSAGE_END 			(uint8_t) 0xCC
#define ROBOT_SPEED_MESSAGE 	(uint8_t) 0x3F
#define WIFI_CONNECTED			(uint8_t) 0x01
#define CONNECTION_ESTABILISHED	(uint8_t) 0x15

#define INIT_STATE				(uint8_t) 0x00
#define MESSAGE_PARSER			(uint8_t) 0x01
#define ROBOT_SPEED_RECEIVED	(uint8_t) 0x02
#define WIFI_RECEIVED			(uint8_t) 0x03
#define CONNECTION_RECEIVED		(uint8_t) 0x04

#define CONNECTED				(uint8_t) 0x01
#define NOT_CONNECTED			(uint8_t) 0x00

#define ROBOT_SPEED_OFFSET	(float) 1.5
#define ROBOT_SPEED_CONVERT	(float) 85




void CommunicationRxWrapper(void);


#endif /* ROBOCUP_COMMUNICATIONHANDLER_INC_COMMUNICATIONRXWRAPPER_H_ */
