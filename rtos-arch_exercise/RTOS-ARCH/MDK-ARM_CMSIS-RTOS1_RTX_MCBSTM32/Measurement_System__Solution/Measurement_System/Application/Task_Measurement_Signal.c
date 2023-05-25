#include "osObjects.h"

#define BIT_0	(1 << 0)

static uint16_t globADC_Value = 0;	// global ADC value

//-----------------------------------------------------------------------------
void Task_Measurement_Signal(void const *argument)
{
	osEvent locEventADC_Isr;															// event accessor
	
	TIM_Cmd(TIM2, ENABLE);																// enable TIM2	
	
  while(1)
  {
	  locEventADC_Isr = osSignalWait(BIT_0, 500);					// wait for ADC event from the ADC isr
		if (locEventADC_Isr.status == osEventSignal)				// ADC event received
		{		
			printf("ADC  = 0x%04X\n", globADC_Value);   			// print ADC value (global static variable) to serial port
		}												
		else																								// signal receive error
		{
			printf("Error Task_Measurement_Signal: signal receive failed\n");
		}
  }
}

//-----------------------------------------------------------------------------
//void ADC1_2_IRQHandler(void) __irq										// ADC interrupt service routine
//{
//	ADC_ClearITPendingBit(ADC1, ADC_FLAG_EOC);					// clear ADC1 pending bit
//	globADC_Value = ADC_GetConversionValue(ADC1);				// read ACD1 result 
//	osSignalSet(taskHandle_Measurement_Signal,BIT_0);		// synchronze via signal with task
//}
