/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f7xx_it.c
  * @brief   Interrupt Service Routines.
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
//#include "main.h"
//#include "stm32f7xx_it.h"
//#include "FreeRTOS.h"
//#include "task.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../../Application/osObjects.h"
/* USER CODE END Includes */
  
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim7;
extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN EV */
extern volatile uint32_t globADC_Value;
extern volatile uint32_t globSimulatedButtonState;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M7 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */
	BSP_LED_On(LED_RED);
  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */
	BSP_LED_On(LED_RED);
  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */
	BSP_LED_On(LED_RED);
  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */
	BSP_LED_On(LED_RED);
  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */
	BSP_LED_On(LED_RED);
  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/******************************************************************************/
/* STM32F7xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f7xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles ADC1, ADC2 and ADC3 global interrupts.
  */
//void ADC_IRQHandler(void) // IRQ handler for Task_Measurement_Signal
//{
//  /* USER CODE BEGIN ADC_IRQn 0 */	
//	globADC_Value = HAL_ADC_GetValue(&hadc1); // read ADC register value
//  /* USER CODE END ADC_IRQn 0 */
//  HAL_ADC_IRQHandler(&hadc1);
//  /* USER CODE BEGIN ADC_IRQn 1 */
//	// set event bit
//	if(osEventFlagsSet(eventGroupHandle_Measurement, BIT_0) == BIT_0)
//	{
//		// event successful set
//	}
//	else	// event set fails
//	{
//		printf("\nError ADC_IRQHandler: event bit set failed\n");
//	}
//  /* USER CODE END ADC_IRQn 1 */
//}

void ADC_IRQHandler(void) // IRQ handler for Task_Measurement_Queue
{
  /* USER CODE BEGIN ADC_IRQn 0 */
	ADC_Message_t locSendMessage = {0, 0};									// local Message Buffer
	locSendMessage.ID = 1;
	locSendMessage.ADC_Value = HAL_ADC_GetValue(&hadc1);	  // read ACD1 result
  /* USER CODE END ADC_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc1);
  /* USER CODE BEGIN ADC_IRQn 1 */
	// send message with ADC result to task
	if (osMessageQueuePut(queueHandle_ADC_Measurement, &locSendMessage, 0, 0) != osError) // with lowes message priority and without timeout	
	{
		// message successful sent
		// nothing to do
	}
	else
	{
		printf("\nError ADC_IRQHandler: ADC message send failed\n");
	}
  /* USER CODE END ADC_IRQn 1 */
}

/**
  * @brief This function handles TIM7 global interrupt.
  */
void TIM7_IRQHandler(void)
{
  /* USER CODE BEGIN TIM7_IRQn 0 */

  /* USER CODE END TIM7_IRQn 0 */
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_IRQn 1 */

  /* USER CODE END TIM7_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void USART3_IRQHandler(void)
{
	uint32_t locRxBuffer = (&huart3)->Instance->RDR;

	if ( (locRxBuffer >= 'a' && locRxBuffer <= 'z') ||
	     (locRxBuffer >= 'A' && locRxBuffer <= 'Z') ||
	     (locRxBuffer >= '0' && locRxBuffer <= '9') )
	{
		// valid 1st character received
		// handle interrupt
		switch(locRxBuffer)
		{
			case 'A':
				//BSP_LED_On(LED_RED);
				globSimulatedButtonState = 1;
			break;
			case 'B':
				//BSP_LED_Off(LED_RED);
				globSimulatedButtonState = 0;
			break;	
		}
	}
	
  HAL_UART_IRQHandler(&huart3);
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
