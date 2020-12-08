/*
 * Timer_encoder.c
 *
 *  Created on: Sep 26, 2020
 *      Author: dimagENC
 */

#include "Timer_encoder.h"
#include "Common_Data.h"
#include "Port_config.h"

TIM_HandleTypeDef TIM_handler;
uint32_t TIM_ENC_1_Value_1;
uint32_t TIM_ENC_1_CaptureIndex;
#if (ENC_IN_USE>1)
uint32_t TIM_ENC_2_Value_1;
uint32_t TIM_ENC_2_CaptureIndex;
#endif
#if (ENC_IN_USE>2)
uint32_t TIM_ENC_3_Value_1;
uint32_t TIM_ENC_3_CaptureIndex;
#endif
#if (ENC_IN_USE>3)
uint32_t TIM_ENC_4_Value_1;
uint32_t TIM_ENC_4_CaptureIndex;
#endif


void TIMx_ENC_Init(TIM_ENC_Typedef config)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_Encoder_InitTypeDef sConfigENC = {0};
	GPIO_InitTypeDef  GPIO_InitStruct;

	/* USER CODE BEGIN TIM1_Init 1 */

	/* USER CODE END TIM1_Init 1 */
	TIM_handler.Instance = config.TIMx;
	TIM_handler.Init.Prescaler = 0;
	TIM_handler.Init.CounterMode = TIM_COUNTERMODE_UP;
	TIM_handler.Init.Period = 65535;
	TIM_handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TIM_handler.Init.RepetitionCounter = 0;
	TIM_handler.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	sConfigENC.EncoderMode = TIM_ENCODERMODE_TI12;
	sConfigENC.IC1Polarity = TIM_ICPOLARITY_RISING;
	sConfigENC.IC1Selection = TIM_ICSELECTION_DIRECTTI;
	sConfigENC.IC1Prescaler = TIM_ICPSC_DIV1;
	sConfigENC.IC1Filter = 0;
	sConfigENC.IC2Polarity = TIM_ICPOLARITY_RISING;
	sConfigENC.IC2Selection = TIM_ICSELECTION_DIRECTTI;
	sConfigENC.IC2Prescaler = TIM_ICPSC_DIV1;
	sConfigENC.IC2Filter = 0;
	if (HAL_TIM_Encoder_Init(&TIM_handler, &sConfigENC) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&TIM_handler, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}


	if(config.GPIOx_ch1 == GPIOA)
	{

		__HAL_RCC_GPIOA_CLK_ENABLE();
	}
	else if(config.GPIOx_ch1 == GPIOB)
	{

		__HAL_RCC_GPIOB_CLK_ENABLE();
	}
	else if(config.GPIOx_ch1 == GPIOC)
	{

		__HAL_RCC_GPIOC_CLK_ENABLE();
	}

	if(config.GPIOx_ch2 == GPIOA)
	{

		__HAL_RCC_GPIOA_CLK_ENABLE();
	}
	else if(config.GPIOx_ch2 == GPIOB)
	{

		__HAL_RCC_GPIOB_CLK_ENABLE();
	}
	else if(config.GPIOx_ch2 == GPIOC)
	{

		__HAL_RCC_GPIOC_CLK_ENABLE();
	}


	GPIO_InitStruct.Pin = config.GPIO_Pinx_ch1;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = config.GPIO_AlternateFunctionx;
	HAL_GPIO_Init(config.GPIOx_ch1, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = config.GPIO_Pinx_ch2;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = config.GPIO_AlternateFunctionx;
	HAL_GPIO_Init(config.GPIOx_ch2, &GPIO_InitStruct);

	//HAL_NVENC_SetPriority(config.TIMx_IRQ, 0, 0);
	//HAL_NVENC_EnableIRQ(config.TIMx_IRQ);
}

void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef* htim_ENC)
{

	if ((htim_ENC->Instance == TIM1))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM1_CLK_ENABLE();
	}
	else if ((htim_ENC->Instance == TIM2))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM2_CLK_ENABLE();
	}
	else if ((htim_ENC->Instance == TIM3))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM3_CLK_ENABLE();
	}

}

void TIMx_ENC_Start(TIM_ENC_Typedef config)
{
	TIM_handler.Instance = config.TIMx;
	HAL_TIM_Encoder_Start(&TIM_handler, TIM_CHANNEL_ALL);
}

void TIMx_ENC_Stop(TIM_ENC_Typedef config)
{
	TIM_handler.Instance = config.TIMx;
	HAL_TIM_Encoder_Stop(&TIM_handler, TIM_CHANNEL_ALL);
}


