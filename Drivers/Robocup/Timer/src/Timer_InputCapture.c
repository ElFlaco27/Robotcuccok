/*
 * Timer_InputCapture.c
 *
 *  Created on: Apr 20, 2020
 *      Author: dimagic
 */

#include "Timer_InputCapture.h"
#include "Common_Data.h"
#include "Port_config.h"

TIM_HandleTypeDef TIM_handler;
uint32_t TIM_IC_1_Value_1;
uint32_t TIM_IC_1_CaptureIndex;
#if (IC_IN_USE>1)
uint32_t TIM_IC_2_Value_1;
uint32_t TIM_IC_2_CaptureIndex;
#endif
#if (IC_IN_USE>2)
uint32_t TIM_IC_3_Value_1;
uint32_t TIM_IC_3_CaptureIndex;
#endif
#if (IC_IN_USE>3)
uint32_t TIM_IC_4_Value_1;
uint32_t TIM_IC_4_CaptureIndex;
#endif
#if (IC_IN_USE>4)
uint32_t TIM_IC_5_Value_1;
uint32_t TIM_IC_5_CaptureIndex;
#endif

void TIMx_IC_Init(TIM_IC_Typedef config)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_IC_InitTypeDef sConfigIC = {0};
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
	if (HAL_TIM_IC_Init(&TIM_handler) != HAL_OK)
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
	sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_BOTHEDGE;
	sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC.ICFilter = 0;
	if (HAL_TIM_IC_ConfigChannel(&TIM_handler, &sConfigIC, config.TIM_channelx) != HAL_OK)
	{
		Error_Handler();
	}

	GPIO_InitStruct.Pin = config.GPIO_Pinx;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Alternate = config.GPIO_AlternateFunctionx;
	HAL_GPIO_Init(config.GPIOx, &GPIO_InitStruct);

	HAL_NVIC_SetPriority(config.TIMx_IRQ, 0, 0);
	HAL_NVIC_EnableIRQ(config.TIMx_IRQ);
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef* htim_ic)
{

	if ((htim_ic->Instance == TIM1))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM1_CLK_ENABLE();
	}
	else if ((htim_ic->Instance == TIM2))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM2_CLK_ENABLE();
	}
	else if ((htim_ic->Instance == TIM3))
	{
		/* Peripheral clock enable */
	    __HAL_RCC_TIM3_CLK_ENABLE();
	}

}

void TIMx_IC_Start(TIM_IC_Typedef config)
{
	TIM_handler.Instance = config.TIMx;
	HAL_TIM_IC_Start_IT(&TIM_handler, config.TIM_channelx);
}

void TIMx_IC_Stop(TIM_IC_Typedef config)
{
	TIM_handler.Instance = config.TIMx;
	HAL_TIM_IC_Stop_IT(&TIM_handler, config.TIM_channelx);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	uint32_t value2;
	uint32_t Diff_value;
	if((htim->Instance == IC_1_TIM) && (htim->Channel == IC_1_TIM_ACT_CHANNEL))
	{
		if(IC_1_GPIO->IDR & IC_1_GPIO_PIN)
		{
			/* Get the 1st Input Capture value */
			TIM_IC_1_Value_1 = HAL_TIM_ReadCapturedValue(htim, IC_1_TIM_CHANNEL);
			TIM_IC_1_CaptureIndex = 1;
		}
		else if(TIM_IC_1_CaptureIndex == 1)
		{
			 /* Get the 2nd Input Capture value */
			value2 = HAL_TIM_ReadCapturedValue(htim, IC_1_TIM_CHANNEL);

			 /* Capture computation */
			 if (value2 > TIM_IC_1_Value_1)
			 {
				 Diff_value = (value2 - TIM_IC_1_Value_1);
			 }
			 else if (value2 < TIM_IC_1_Value_1)
			 {
				 /* 0xFFFF is max TIM1_CCRx value */
				 Diff_value = ((65535 - TIM_IC_1_Value_1) + value2) + 1;
			 }
			 Write_IC_Channel1_Raw_data(&Diff_value);
			 TIM_IC_1_CaptureIndex = 0;
		}
	}
#if (IC_IN_USE>1)
	else if((htim->Instance == IC_2_TIM) && (htim->Channel == IC_2_TIM_ACT_CHANNEL))
	{
		if(IC_2_GPIO->IDR & IC_2_GPIO_PIN)
		{
			/* Get the 1st Input Capture value */
			TIM_IC_2_Value_1 = HAL_TIM_ReadCapturedValue(htim, IC_2_TIM_CHANNEL);
			TIM_IC_2_CaptureIndex = 1;
		}
		else if(TIM_IC_2_CaptureIndex == 1)
		{
			 /* Get the 2nd Input Capture value */
			value2 = HAL_TIM_ReadCapturedValue(htim, IC_2_TIM_CHANNEL);

			 /* Capture computation */
			 if (value2 > TIM_IC_2_Value_1)
			 {
				 Diff_value = (value2 - TIM_IC_2_Value_1);
			 }
			 else if (value2 < TIM_IC_2_Value_1)
			 {
				 /* 0xFFFF is max TIM1_CCRx value */
				 Diff_value = ((65535 - TIM_IC_2_Value_1) + value2) + 1;
			 }
			 Write_IC_Channel2_Raw_data(&Diff_value);
			 TIM_IC_2_CaptureIndex = 0;
		}
	}
#endif
#if (IC_IN_USE>2)
	else if((htim->Instance == IC_3_TIM) && (htim->Channel == IC_3_TIM_ACT_CHANNEL))
	{
		if(IC_3_GPIO->IDR & IC_3_GPIO_PIN)
		{
			/* Get the 1st Input Capture value */
			TIM_IC_3_Value_1 = HAL_TIM_ReadCapturedValue(htim, IC_3_TIM_CHANNEL);
			TIM_IC_3_CaptureIndex = 1;
		}
		else if(TIM_IC_3_CaptureIndex == 1)
		{
			 /* Get the 2nd Input Capture value */
			value2 = HAL_TIM_ReadCapturedValue(htim, IC_3_TIM_CHANNEL);

			 /* Capture computation */
			 if (value2 > TIM_IC_3_Value_1)
			 {
				 Diff_value = (value2 - TIM_IC_3_Value_1);
			 }
			 else if (value2 < TIM_IC_3_Value_1)
			 {
				 /* 0xFFFF is max TIM1_CCRx value */
				 Diff_value = ((65535 - TIM_IC_3_Value_1) + value2) + 1;
			 }
			 Write_IC_Channel3_Raw_data(&Diff_value);
			 TIM_IC_3_CaptureIndex = 0;
		}
	}
#endif
#if (IC_IN_USE>3)
	else if((htim->Instance == IC_4_TIM) && (htim->Channel == IC_4_TIM_ACT_CHANNEL))
	{
		if(IC_4_GPIO->IDR & IC_4_GPIO_PIN)
		{
			/* Get the 1st Input Capture value */
			TIM_IC_4_Value_1 = HAL_TIM_ReadCapturedValue(htim, IC_4_TIM_CHANNEL);
			TIM_IC_4_CaptureIndex = 1;
		}
		else if(TIM_IC_4_CaptureIndex == 1)
		{
			 /* Get the 2nd Input Capture value */
			value2 = HAL_TIM_ReadCapturedValue(htim, IC_4_TIM_CHANNEL);

			 /* Capture computation */
			 if (value2 > TIM_IC_4_Value_1)
			 {
				 Diff_value = (value2 - TIM_IC_4_Value_1);
			 }
			 else if (value2 < TIM_IC_4_Value_1)
			 {
				 /* 0xFFFF is max TIM1_CCRx value */
				 Diff_value = ((65535 - TIM_IC_4_Value_1) + value2) + 1;
			 }
			 Write_IC_Channel4_Raw_data(&Diff_value);
			 TIM_IC_4_CaptureIndex = 0;
		}
	}
#endif
#if (IC_IN_USE>4)
	else if((htim->Instance == IC_5_TIM) && (htim->Channel == IC_5_TIM_ACT_CHANNEL))
	{
		if(IC_5_GPIO->IDR & IC_5_GPIO_PIN)
		{
			/* Get the 1st Input Capture value */
			TIM_IC_5_Value_1 = HAL_TIM_ReadCapturedValue(htim, IC_5_TIM_CHANNEL);
			TIM_IC_5_CaptureIndex = 1;
		}
		else if(TIM_IC_5_CaptureIndex == 1)
		{
			 /* Get the 2nd Input Capture value */
			value2 = HAL_TIM_ReadCapturedValue(htim, IC_5_TIM_CHANNEL);

			 /* Capture computation */
			 if (value2 > TIM_IC_5_Value_1)
			 {
				 Diff_value = (value2 - TIM_IC_5_Value_1);
			 }
			 else if (value2 < TIM_IC_5_Value_1)
			 {
				 /* 0xFFFF is max TIM1_CCRx value */
				 Diff_value = ((65535 - TIM_IC_5_Value_1) + value2) + 1;
			 }
			 Write_IC_Channel5_Raw_data(&Diff_value);
			 TIM_IC_5_CaptureIndex = 0;
		}
	}
#endif


}
