#include "osObjects.h"

#define BIT_0	(1 << 0)

static uint16_t globADC_Value = 0;	// global ADC value

//-----------------------------------------------------------------------------
void Task_Measurement_Signal(void *argument)
{
	EventBits_t locEventADC_Isr;														// event accessor
	
	TIM_Cmd(TIM2, ENABLE);																	// enable TIM2	
  
	while(1)
  {
	  // wait for ADC event from the ADC isr
//		locEventADC_Isr = ...;			
		if ( (locEventADC_Isr & BIT_0) != 0 )									// ADC event received
		{		
			printf("ADC  = 0x%04X\n", globADC_Value);   				// print ADC value (global static variable) to serial port
		}												
		else																									// signal receive error
		{
			printf("Error Task_Measurement_Signal: event bit receive failed\n");
		}
  }
}

//-----------------------------------------------------------------------------
void ADC1_2_IRQHandler(void) __irq												// ADC interrupt service routine
{
	BaseType_t locHigherPriorityTaskWoken = pdFALSE;
	
	ADC_ClearITPendingBit(ADC1, ADC_FLAG_EOC);							// clear ADC1 pending bit
	globADC_Value = ADC_GetConversionValue(ADC1);						// read ACD1 result 
	
	// set event bit
//	if ( ... != pdFALSE)
	{			// event set successful
		portYIELD_FROM_ISR(locHigherPriorityTaskWoken);				// context switch request
	}
//	else	// event set fails
	{
		printf("Error ADC1_2_IRQHandler: event bit set failed\n");
	}
}
