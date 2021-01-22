/*
 * CommunicationTxWrapper.h
 *
 *  Created on: Jan 19, 2021
 *      Author: dimagic
 */

#ifndef ROBOCUP_COMMUNICATIONHANDLER_INC_COMMUNICATIONTXWRAPPER_H_
#define ROBOCUP_COMMUNICATIONHANDLER_INC_COMMUNICATIONTXWRAPPER_H_

#define MESSAGE_INIT 			(uint8_t) 0xAA
#define MESSAGE_END 			(uint8_t) 0xCC
#define ROBOT_SPEED_MESSAGE 	(uint8_t) 0x00
#define CONNECTION_SUCCESFUL 	(uint8_t) 0x01
#define CONNECTION_REQ			(uint8_t) 0x15
#define ROBOT_ID				(uint8_t) 0x01

#define CONNECTION_REQ_SIZE		(uint8_t) 0x04

#define INIT_STATE				(uint8_t) 0x00
#define WAIT_FOR_CONNECTION		(uint8_t) 0x01
#define NORMAL_COMMUNICATION	(uint8_t) 0x02

#define CONNECTED				(uint8_t) 0x01
#define NOT_CONNECTED			(uint8_t) 0x00

#define TRUE					(uint8_t) 0x01
#define FALSE					(uint8_t) 0x00

#define ROBOT_SPEED_OFFSET	(float) 1.5
#define ROBOT_SPEED_CONVERT	(float) 85




void CommunicationTxWrapper(void);

#endif /* ROBOCUP_COMMUNICATIONHANDLER_INC_COMMUNICATIONTXWRAPPER_H_ */
