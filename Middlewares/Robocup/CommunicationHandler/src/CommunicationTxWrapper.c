/*
 * CommunicationTxWrapper.c
 *
 *  Created on: Jan 19, 2021
 *      Author: dimagic
 */


#include "CommunicationTxWrapper.h"
#include "fifo.h"
#include "Common_data.h"

uint8_t Tx_Wrapper_State = INIT_STATE;
uint8_t message_size;
RobotSpeed_Typedef Received_robot_speeds;
extern UART_HandleTypeDef huart3;
uint8_t TxBuffer[255];

void CommunicationTxWrapper(void)
{
	uint8_t wifi_status;
	uint8_t connection_status;
	uint8_t transmit_enabled;
	switch(Tx_Wrapper_State)
	{
		case INIT_STATE:
			Read_Wifi_Connected(&wifi_status);
			if(CONNECTED == wifi_status)
			{
				Read_Transmit_Enabled(&transmit_enabled);
				if(transmit_enabled == TRUE)
				{
					TxBuffer[0] = MESSAGE_INIT;
					TxBuffer[1] = CONNECTION_REQ;
					TxBuffer[2] = ROBOT_ID;
					TxBuffer[3] = MESSAGE_END;
					transmit_enabled = FALSE;
					Write_Transmit_Enabled(&transmit_enabled);
					HAL_UART_Transmit_IT(&huart3, (uint8_t *)TxBuffer, CONNECTION_REQ_SIZE);
					Tx_Wrapper_State = WAIT_FOR_CONNECTION;
				}
			}
			break;
		case WAIT_FOR_CONNECTION:
			Read_Connection_Estabilished(&connection_status);
			if(CONNECTED == connection_status)
			{
				Tx_Wrapper_State = NORMAL_COMMUNICATION;
			}
			else
			{
				Read_Transmit_Enabled(&transmit_enabled);
				if(TRUE == transmit_enabled)
				{
					TxBuffer[0] = MESSAGE_INIT;
					TxBuffer[1] = CONNECTION_REQ;
					TxBuffer[2] = ROBOT_ID;
					TxBuffer[3] = MESSAGE_END;
					transmit_enabled = FALSE;
					Write_Transmit_Enabled(&transmit_enabled);
					HAL_UART_Transmit_IT(&huart3, (uint8_t *)TxBuffer, CONNECTION_REQ_SIZE);
				}
			}
			break;
		case NORMAL_COMMUNICATION:
			break;
		default:
			//should never come here
			Tx_Wrapper_State = INIT_STATE;
			break;

	}
}
