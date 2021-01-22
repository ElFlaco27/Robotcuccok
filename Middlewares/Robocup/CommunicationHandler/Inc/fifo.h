/*
 * fifo.h
 *
 *  Created on: Jan 19, 2021
 *      Author: dimagic
 */

#ifndef ROBOCUP_COMMUNICATIONHANDLER_INC_FIFO_H_
#define ROBOCUP_COMMUNICATIONHANDLER_INC_FIFO_H_

#include "main.h"

#define RX_FIFO_SIZE 		(uint8_t) 0xFF
#define TX_FIFO_SIZE 		(uint8_t) 0xFF
#define DATA_NOT_AVAILABLE 	(uint16_t) 0xFFFF
#define FIFO_FULL			(uint8_t) 0x01
#define E_OK				(uint8_t) 0x00

uint8_t Rx_fifo_push(uint8_t data);
uint16_t Rx_fifo_pull(void);
uint8_t Tx_fifo_push(uint8_t data);
uint16_t Tx_fifo_pull(void);



#endif /* ROBOCUP_COMMUNICATIONHANDLER_INC_FIFO_H_ */
