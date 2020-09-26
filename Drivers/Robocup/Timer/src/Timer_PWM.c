/*
 * Timer_PWM.c
 *
 *  Created on: Apr 19, 2020
 *      Author: dimagic
 */

#include "Timer_PWM.h"



void TIMx_PWM_Init(TIM_PWM_Typedef config)
{

	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};
	uint32_t uhPrescalerValue;
	uint32_t Period_Value;
	GPIO_InitTypeDef  GPIO_InitStruct = {0};
	TIM_HandleTypeDef TIM_handler = {0};

	uhPrescalerValue = (uint32_t)(SystemCoreClock / TIMx_PWM_CLK) - 1;
	Period_Value = (uint32_t)(TIMx_PWM_CLK / config.Frequency) - 1;

	TIM_handler.Instance				= config.TIMx;
	TIM_handler.Init.Prescaler       	= uhPrescalerValue;
	TIM_handler.Init.Period          	= Period_Value;
	TIM_handler.Init.CounterMode 		= TIM_COUNTERMODE_UP;
	TIM_handler.Init.ClockDivision 		= TIM_CLOCKDIVISION_DIV1;
	TIM_handler.Init.AutoReloadPreload 	= TIM_AUTORELOAD_PRELOAD_DISABLE;

	if (HAL_TIM_PWM_Init(&TIM_handler) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&TIM_handler, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&TIM_handler, &sConfigOC, config.TIM_channelx) != HAL_OK)
	{
		Error_Handler();
	}

	if(config.GPIOx == GPIOA)
	{

	    __HAL_RCC_GPIOA_CLK_ENABLE();
	}
	else if(config.GPIOx == GPIOB)
	{

	    __HAL_RCC_GPIOB_CLK_ENABLE();
	}
	else if(config.GPIOx == GPIOC)
	{

	    __HAL_RCC_GPIOC_CLK_ENABLE();
	}
	GPIO_InitStruct.Alternate = config.GPIO_AlternateFunctionx;
	GPIO_InitStruct.Pin = config.GPIO_Pinx;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(config.GPIOx, &GPIO_InitStruct);

}

void TIMx_PWM_Start(TIM_PWM_Typedef config)
{
	TIM_HandleTypeDef TIM_handler = {0};

	TIM_handler.Instance = config.TIMx;
	HAL_TIM_PWM_Start(&TIM_handler, config.TIM_channelx);
}

void TIMx_PWM_Stop(TIM_PWM_Typedef config)
{
	TIM_HandleTypeDef TIM_handler = {0};

	TIM_handler.Instance = config.TIMx;
	HAL_TIM_PWM_Stop(&TIM_handler, config.TIM_channelx);
}



void Change_PWM_Pulse(TIM_PWM_Typedef config)
{
	TIM_HandleTypeDef TIM_handler = {0};
	uint32_t Period_Value;
	uint32_t Pulse_Value;
	TIM_handler.Instance = config.TIMx;
	Period_Value = (uint32_t)(TIMx_PWM_CLK / config.Frequency) - 1;
	if(config.Duty_Cicle == 0)
	{
		Pulse_Value = 0;
	}
	else
	{
		Pulse_Value = (uint32_t)((Period_Value * config.Duty_Cicle) / 100 - 1);
	}
	__HAL_TIM_SET_COMPARE(&TIM_handler, config.TIM_channelx, Pulse_Value);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	if ((htim->Instance == TIM1))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM1_CLK_ENABLE();
	}
	else if ((htim->Instance == TIM2))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM2_CLK_ENABLE();
	}
	else if ((htim->Instance == TIM3))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM3_CLK_ENABLE();
	}
}
