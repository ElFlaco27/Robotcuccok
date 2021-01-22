/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Initialize_System.h"
#include "UART.h"
#include "fifo.h"
#include "Common_Data.h"
#include "CommunicationRxWrapper.h"
#include "CommunicationTxWrapper.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart3;

osThreadId MwPeriodicTaskHandle;
osThreadId LowLevelPeriodiHandle;
osThreadId AppPeriodicTaskHandle;
/* USER CODE BEGIN PV */
uint32_t sys_count=0;
uint32_t get_sys_count=0;
uint8_t UartReady = 0;
uint8_t Startup_tx_message[3]={0xAA, 0x15, 0xCC};

extern uint8_t aRxBuffer[RXBUFFERSIZE];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
void StartMwPeriodicTask(void const * argument);
void StartLowLevelPeriodicTask(void const * argument);
void StartAppPeriodicTask(void const * argument);

/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */

  /* USER CODE BEGIN 2 */
  Init_System_Startup();

  HAL_Delay(30000);
  MX_GPIO_Init();
  MX_USART3_UART_Init();

  HAL_UART_Receive_IT(&huart3, (uint8_t *)aRxBuffer, RXBUFFERSIZE);
  HAL_UART_Transmit_IT(&huart3, (uint8_t *)Startup_tx_message, 3);





  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of MwPeriodicTask */
  osThreadDef(MwPeriodicTask, StartMwPeriodicTask, osPriorityNormal, 0, 128);
  MwPeriodicTaskHandle = osThreadCreate(osThread(MwPeriodicTask), NULL);

  /* definition and creation of LowLevelPeriodi */
  osThreadDef(LowLevelPeriodi, StartLowLevelPeriodicTask, osPriorityRealtime, 0, 128);
  LowLevelPeriodiHandle = osThreadCreate(osThread(LowLevelPeriodi), NULL);

  /* definition and creation of AppPeriodicTask */
  osThreadDef(AppPeriodicTask, StartAppPeriodicTask, osPriorityAboveNormal, 0, 128);
  AppPeriodicTaskHandle = osThreadCreate(osThread(AppPeriodicTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART3;
  PeriphClkInit.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage 
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */


/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartMwPeriodicTask */
/**
  * @brief  Function implementing the MwPeriodicTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartMwPeriodicTask */
void StartMwPeriodicTask(void const * argument)
{
    
    
    
    
    

  /* USER CODE BEGIN 5 */
	//TickType_t xLastWakeTime;
	//uint32_t last_data;
	//const TickType_t xFrequency = 0.250 / portTICK_PERIOD_MS;


	// Initialise the xLastWakeTime variable with the current time.
	//xLastWakeTime = xTaskGetTickCount();
  /* Infinite loop */
  for(;;)
  {
	//vTaskDelayUntil( &xLastWakeTime, xFrequency );
	CommunicationRxWrapper();
	CommunicationTxWrapper();

  }
  /* USER CODE END 5 */ 
}

/* USER CODE BEGIN Header_StartLowLevelPeriodicTask */
/**
* @brief Function implementing the LowLevelPeriodi thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLowLevelPeriodicTask */
void StartLowLevelPeriodicTask(void const * argument)
{
  /* USER CODE BEGIN StartLowLevelPeriodicTask */
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 10;

	// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount();

  /* Infinite loop */

  for(;;)
  {
	  vTaskDelayUntil( &xLastWakeTime, xFrequency );
  }
  /* USER CODE END StartLowLevelPeriodicTask */
}

/* USER CODE BEGIN Header_StartAppPeriodicTask */
/**
* @brief Function implementing the AppPeriodicTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartAppPeriodicTask */
void StartAppPeriodicTask(void const * argument)
{
  /* USER CODE BEGIN StartAppPeriodicTask */
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 2 / portTICK_PERIOD_MS;
	WheelSpeed_Typedef Provided_wheel_speeds;
	Provided_wheel_speeds.WheelSpeed_1=100;
	Write_Calculated_Wheel_Speeds(&Provided_wheel_speeds);
	Motorx_Set_Speed();
		// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount();
  /* Infinite loop */
  for(;;)
  {
	  vTaskDelayUntil( &xLastWakeTime, xFrequency );

	  Calculate_Wheel_Speeds();
	  Provide_Wheel_Speeds();
	  PID_Controller();
	  Motorx_Set_Speed();
	  //Actuate_Motors();
  }
  /* USER CODE END StartAppPeriodicTask */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM7 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM7) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
	while(1);
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
