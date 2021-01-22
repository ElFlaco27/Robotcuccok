/*
 * CommunicationRxWrapper.c
 *
 *  Created on: Jan 19, 2021
 *      Author: dimagic
 */


#include "CommunicationRxWrapper.h"
#include "fifo.h"
#include "Common_data.h"

uint8_t Rx_Wrapper_State = INIT_STATE;
uint8_t message_size;
RobotSpeed_Typedef Received_robot_speeds;
uint8_t Received_robot_speeds_X[255];
uint8_t Received_robot_speeds_Y[255];
uint8_t Received_robot_speeds_Ang[255];
uint8_t receive_counter=0;

void CommunicationRxWrapper(void)
{
	uint16_t Received_message;
	uint8_t wifi_status;
	uint8_t connection_status;
	switch(Rx_Wrapper_State)
	{
		case INIT_STATE:
			Received_message = Rx_fifo_pull();
			if(DATA_NOT_AVAILABLE != Received_message)
			{
				if(MESSAGE_INIT == Received_message)
				{
					Rx_Wrapper_State = MESSAGE_PARSER;
				}
				else
				{
					//errorhandling
				}
			}
			break;

		case MESSAGE_PARSER:
			Received_message = Rx_fifo_pull();
			if(DATA_NOT_AVAILABLE != Received_message)
			{
				if(ROBOT_SPEED_MESSAGE == Received_message)
				{
					Rx_Wrapper_State = ROBOT_SPEED_RECEIVED;
					message_size=3;

				}
				else if (WIFI_CONNECTED == Received_message)
				{
					Rx_Wrapper_State = WIFI_RECEIVED;
					message_size=0;
				}
				else if (CONNECTION_ESTABILISHED == Received_message)
				{
					Rx_Wrapper_State = CONNECTION_RECEIVED;
					message_size=0;
				}
				else
				{
					Rx_Wrapper_State = INIT_STATE;
					//errorhandling
				}
			}
			break;

		case ROBOT_SPEED_RECEIVED:
			Received_message = Rx_fifo_pull();
			if(DATA_NOT_AVAILABLE != Received_message)
			{
				if(3 == message_size)
				{
					//robot speed x calculation
					Received_robot_speeds_X[receive_counter] = (uint8_t)Received_message;
					Received_robot_speeds.Speed_X = ((float)Received_message / ROBOT_SPEED_CONVERT) - ROBOT_SPEED_OFFSET;
					message_size = message_size -1;
				}
				else if(2 == message_size)
				{
					//robot speed y calculation
					Received_robot_speeds_Y[receive_counter] = (uint8_t)Received_message;
					Received_robot_speeds.Speed_Y = ((float)Received_message / ROBOT_SPEED_CONVERT) - ROBOT_SPEED_OFFSET;
					message_size = message_size -1;
				}
				else if(1 == message_size)
				{
					//robot speed angular calculation
					Received_robot_speeds_Ang[receive_counter] = (uint8_t)Received_message;
					Received_robot_speeds.Angular_Speed = ((float)Received_message / ROBOT_SPEED_CONVERT) - ROBOT_SPEED_OFFSET;
					message_size = message_size -1;

				}
				else if(0 == message_size)
				{
					if(MESSAGE_END == Received_message)
					{
						Write_Received_Robot_Speed(&Received_robot_speeds);
						Rx_Wrapper_State = INIT_STATE;
						receive_counter = receive_counter + 1;
					}
					else
					{
						Rx_Wrapper_State = INIT_STATE;
						//error handling
					}
				}
				else
				{
					Rx_Wrapper_State = INIT_STATE;
					//error handling
				}
			}
			break;

		case WIFI_RECEIVED:
			wifi_status = CONNECTED;
			Received_message = Rx_fifo_pull();
			if(DATA_NOT_AVAILABLE != Received_message)
			{
				if(0 == message_size)
				{
					if(MESSAGE_END == Received_message)
					{
						Write_Wifi_Connected(&wifi_status);
						Rx_Wrapper_State = INIT_STATE;
					}
					else
					{
						Rx_Wrapper_State = INIT_STATE;
						//error handling
					}
				}
				else
				{
					Rx_Wrapper_State = INIT_STATE;
					//error handling
				}
			}
			break;

		case CONNECTION_RECEIVED:
			connection_status = CONNECTED;
			Received_message = Rx_fifo_pull();
			if(DATA_NOT_AVAILABLE != Received_message)
			{
				if(0 == message_size)
				{
					if(MESSAGE_END == Received_message)
					{
						Write_Connection_Estabilished(&connection_status);
						Rx_Wrapper_State = INIT_STATE;
					}
					else
					{
						Rx_Wrapper_State = INIT_STATE;
						//error handling
					}
				}
				else
				{
					Rx_Wrapper_State = INIT_STATE;
					//error handling
				}
			}
			break;

		default:
			//should never come here
			Rx_Wrapper_State = INIT_STATE;
			break;

	}

}
