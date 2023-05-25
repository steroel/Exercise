#include "STM32F7xx_NVIC_Dispatcher.h"
#include "I_NVIC_Dispatcher_Config.h"
#include "stm32f7xx.h"

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern UART_HandleTypeDef huart3;

static void*                                      mptrCallbackObject[InterruptVectorNumberAmount];
static ICB_InterruptService_serviceInterrupt_fptr mfptr_serviceInterrupt[InterruptVectorNumberAmount];

static void NVIC_Dispatcher_registerInterrupt(void* const ptrCallbackObject, 
	                          ICB_InterruptService_serviceInterrupt_fptr fptr_serviceInterrupt,
                            interruptVectorNumber_t interruptVectorNumber);
static void NVIC_Dispatcher_unregisterInterrupt(interruptVectorNumber_t interruptVectorNumber);

void I_NVIC_Dispatcher_registerInterrupt(void* const ptrCallbackObject, 
	                          ICB_InterruptService_serviceInterrupt_fptr fptr_serviceInterrupt,
                            interruptVectorNumber_t interruptVectorNumber)
{
	NVIC_Dispatcher_registerInterrupt(ptrCallbackObject, fptr_serviceInterrupt, interruptVectorNumber);
}

void I_NVIC_Dispatcher_unregisterInterrupt(interruptVectorNumber_t interruptVectorNumber)
{
	NVIC_Dispatcher_unregisterInterrupt(interruptVectorNumber);
}	

static void NVIC_Dispatcher_registerInterrupt(void* const ptrCallbackObject, 
	                          ICB_InterruptService_serviceInterrupt_fptr fptr_serviceInterrupt,
                            interruptVectorNumber_t interruptVectorNumber)
{
	if((ptrCallbackObject != nullptr) && (fptr_serviceInterrupt != nullptr))
	{
		mptrCallbackObject[interruptVectorNumber]     = ptrCallbackObject;
		mfptr_serviceInterrupt[interruptVectorNumber] = fptr_serviceInterrupt;
	}
	else
	{
		//nothing to do
	}
}

static void NVIC_Dispatcher_unregisterInterrupt(interruptVectorNumber_t interruptVectorNumber)
{
		mptrCallbackObject[interruptVectorNumber]     = nullptr; 
		mfptr_serviceInterrupt[interruptVectorNumber] = nullptr;
}

void ADC_IRQHandler(void)
{
	uint32_t locADC_Value = 0;
	
	locADC_Value = HAL_ADC_GetValue(&hadc1); // read ADC register value
	HAL_ADC_IRQHandler(&hadc1);
	
	if ( (mptrCallbackObject[ADC_InterruptVectorNumber] != nullptr) && (mfptr_serviceInterrupt[ADC_InterruptVectorNumber] != nullptr))
	{
		// call interrupt service
		mfptr_serviceInterrupt[ADC_InterruptVectorNumber](mptrCallbackObject[ADC_InterruptVectorNumber], (void*)locADC_Value); 
	}
	else
	{
		// nothing to do
	}
}

void TIM3_IRQHandler(void)
{
	if ( (mptrCallbackObject[TIM3_InterruptVectorNumber] != nullptr) && (mfptr_serviceInterrupt[TIM3_InterruptVectorNumber] != nullptr))
	{
		// call interrupt service
		mfptr_serviceInterrupt[TIM3_InterruptVectorNumber](mptrCallbackObject[TIM3_InterruptVectorNumber], (void*)nullptr); 
	}
	else
	{
		// nothing to do
	}
	
  HAL_TIM_IRQHandler(&htim3);
	HAL_TIM_OC_Stop_IT(&htim3, TIM_CHANNEL_1);
}

void TIM4_IRQHandler(void)
{
	if ( (mptrCallbackObject[TIM4_InterruptVectorNumber] != nullptr) && (mfptr_serviceInterrupt[TIM4_InterruptVectorNumber] != nullptr))
	{
		// call interrupt service
		mfptr_serviceInterrupt[TIM4_InterruptVectorNumber](mptrCallbackObject[TIM4_InterruptVectorNumber], (void*)nullptr); 
	}
	else
	{
		// nothing to do
	}
	
	HAL_TIM_IRQHandler(&htim4);
	HAL_TIM_OC_Stop_IT(&htim4, TIM_CHANNEL_1);
}

void USART3_IRQHandler(void)
{
	uint32_t locRxBuffer = (&huart3)->Instance->RDR;

	if ( (locRxBuffer >= 'a' && locRxBuffer <= 'z') ||
	     (locRxBuffer >= 'A' && locRxBuffer <= 'Z') ||
	     (locRxBuffer >= '0' && locRxBuffer <= '9') )
	{
		// valid 1st character received
		// handle interrupt
		mfptr_serviceInterrupt[USART3_InterruptVectorNumber](mptrCallbackObject[USART3_InterruptVectorNumber], (void*)locRxBuffer); 
	}
	
  HAL_UART_IRQHandler(&huart3);
}
