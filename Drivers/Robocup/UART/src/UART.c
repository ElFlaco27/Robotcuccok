/*
 * UART.c
 *
 *  Created on: Jan 19, 2021
 *      Author: dimagic
 */

#include "UART.h"
#include "fifo.h"
#include "Common_Data.h"


uint8_t aRxBuffer[RXBUFFERSIZE];
extern UART_HandleTypeDef huart3;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	Rx_fifo_push(aRxBuffer[0]);
	HAL_UART_Receive_IT(&huart3, (uint8_t *)aRxBuffer, RXBUFFERSIZE);
}


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	uint8_t transmit_enabled=TRUE;
	Write_Transmit_Enabled(&transmit_enabled);
}

