/*
 * MotorController.h
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "Timer_PWM.h"
#include "Port_config.h"

typedef struct
{
    uint8_t			MotorId;
    uint8_t			Speed;
}Motorx_Typedef;

#define PWM_FREQUENCY			(20000UL)
#define ZERO_SPEED				0u

#define MOTOR1					1u
#define Motor1_EN_GPIO 			GPIOA
#define Motor1_EN_PIN 			GPIO_PIN_10
#define Motor1_A_TIM 			PWM_1A_TIM
#define Motor1_A_TIM_CHANNEL 	PWM_1A_TIM_CHANNEL
#define Motor1_A_GPIO 			PWM_1A_GPIO
#define Motor1_A_GPIO_PIN 		PWM_1A_GPIO_PIN
#define Motor1_A_GPIO_AF 		PWM_1A_GPIO_AF
#define Motor1_B_TIM 			PWM_1B_TIM
#define Motor1_B_TIM_CHANNEL 	PWM_1B_TIM_CHANNEL
#define Motor1_B_GPIO 			PWM_1B_GPIO
#define Motor1_B_GPIO_PIN 		PWM_1B_GPIO_PIN
#define Motor1_B_GPIO_AF 		PWM_1B_GPIO_AF

#define MOTOR2					2u
#define Motor1_EN_GPIO 			GPIOC
#define Motor1_EN_PIN 			GPIO_PIN_1
#define Motor2_A_TIM 			PWM_2A_TIM
#define Motor2_A_TIM_CHANNEL 	PWM_2A_TIM_CHANNEL
#define Motor2_A_GPIO 			PWM_2A_GPIO
#define Motor2_A_GPIO_PIN 		PWM_2A_GPIO_PIN
#define Motor2_A_GPIO_AF 		PWM_2A_GPIO_AF
#define Motor2_B_TIM 			PWM_2B_TIM
#define Motor2_B_TIM_CHANNEL 	PWM_2B_TIM_CHANNEL
#define Motor2_B_GPIO 			PWM_2B_GPIO
#define Motor2_B_GPIO_PIN 		PWM_2B_GPIO_PIN
#define Motor2_B_GPIO_AF 		PWM_2B_GPIO_AF

#define MOTOR3					3u
#define Motor1_EN_GPIO 			GPIOC
#define Motor1_EN_PIN 			GPIO_PIN_7
#define Motor3_A_TIM 			PWM_3A_TIM
#define Motor3_A_TIM_CHANNEL 	PWM_3A_TIM_CHANNEL
#define Motor3_A_GPIO 			PWM_3A_GPIO
#define Motor3_A_GPIO_PIN 		PWM_3A_GPIO_PIN
#define Motor3_A_GPIO_AF 		PWM_3A_GPIO_AF
#define Motor3_B_TIM 			PWM_3B_TIM
#define Motor3_B_TIM_CHANNEL 	PWM_3B_TIM_CHANNEL
#define Motor3_B_GPIO 			PWM_3B_GPIO
#define Motor3_B_GPIO_PIN 		PWM_3B_GPIO_PIN
#define Motor3_B_GPIO_AF 		PWM_3B_GPIO_AF

#define MOTOR4					4u
#define Motor1_EN_GPIO 			GPIOC
#define Motor1_EN_PIN 			GPIO_PIN_13
#define Motor4_A_TIM 			PWM_4A_TIM
#define Motor4_A_TIM_CHANNEL 	PWM_4A_TIM_CHANNEL
#define Motor4_A_GPIO 			PWM_4A_GPIO
#define Motor4_A_GPIO_PIN 		PWM_4A_GPIO_PIN
#define Motor4_A_GPIO_AF 		PWM_4A_GPIO_AF
#define Motor4_B_TIM 			PWM_4B_TIM
#define Motor4_B_TIM_CHANNEL 	PWM_4B_TIM_CHANNEL
#define Motor4_B_GPIO 			PWM_4B_GPIO
#define Motor4_B_GPIO_PIN 		PWM_4B_GPIO_PIN
#define Motor4_B_GPIO_AF 		PWM_4B_GPIO_AF


void Motor_Init(void);

void Motor_Start(void);

void Motor_Stop(void);

void Motorx_Set_Speed(void);



#endif /* MOTORCONTROLLER_H_ */
