#include "stm32f10x.h"                  // CMCIS device header

#include "I_NVIC_Dispatcher_Config.h"

#define INTERRUPT_VECTOR_AMOUNT       68

static void*                                      mptrCallbackObject[INTERRUPT_VECTOR_AMOUNT];
static ICB_InterruptService_serviceInterrupt_fptr mfptr_serviceInterrupt[INTERRUPT_VECTOR_AMOUNT];


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

void ADC1_2_IRQHandler(void) // __irq             // ADC interrupt service routine
{
	uint32_t locADC_Value = 0;
	
	ADC_ClearITPendingBit(ADC1, ADC_FLAG_EOC);	 // clear ADC1 pending bit
	locADC_Value = ADC_GetConversionValue(ADC1); // read ACD1 result
	
	if ( (mptrCallbackObject != nullptr) && (mfptr_serviceInterrupt[ADC1_2_InterruptVectorNumber] != nullptr))
	{
		// call interrupt service
		mfptr_serviceInterrupt[ADC1_2_InterruptVectorNumber](mptrCallbackObject[ADC1_2_InterruptVectorNumber], (void*)locADC_Value); 
	}
	else
	{
		// nothing to do
	}
}
