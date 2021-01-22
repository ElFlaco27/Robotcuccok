/*
 * fifo.c
 *
 *  Created on: Jan 19, 2021
 *      Author: dimagic
 */

#include "fifo.h"

volatile uint8_t Rx_fifo[RX_FIFO_SIZE];
volatile uint8_t Tx_fifo[RX_FIFO_SIZE];

volatile uint8_t Rx_fifo_tail = 0;
volatile uint8_t Rx_fifo_head = 0;

volatile uint8_t Tx_fifo_tail = 0;
volatile uint8_t Tx_fifo_head = 0;

uint8_t Rx_fifo_push(uint8_t data)
{
	if(((Rx_fifo_head + 1) % RX_FIFO_SIZE) == Rx_fifo_tail)
	{
		return FIFO_FULL;
	}

	Rx_fifo[Rx_fifo_head] = data;
	Rx_fifo_head = (Rx_fifo_head + 1) % RX_FIFO_SIZE;

	return E_OK;

}

uint16_t Rx_fifo_pull(void)
{
	uint8_t data;
	if(Rx_fifo_tail == Rx_fifo_head)
	{
		return DATA_NOT_AVAILABLE;
	}

	data = Rx_fifo[Rx_fifo_tail];
	Rx_fifo_tail = (Rx_fifo_tail + 1) & RX_FIFO_SIZE;

	return data;

}

uint8_t Tx_fifo_push(uint8_t data)
{
	if(((Tx_fifo_head + 1) % TX_FIFO_SIZE) == Tx_fifo_tail)
	{
		return FIFO_FULL;
	}

	Tx_fifo[Tx_fifo_head] = data;
	Tx_fifo_head = (Tx_fifo_head + 1) % TX_FIFO_SIZE;

	return E_OK;

}

uint16_t Tx_fifo_pull(void)
{
	uint8_t data;
	if(Tx_fifo_tail == Tx_fifo_head)
	{
		return DATA_NOT_AVAILABLE;
	}

	data = Tx_fifo[Tx_fifo_tail];
	Tx_fifo_tail = (Tx_fifo_tail + 1) & TX_FIFO_SIZE;

	return data;

}
