#include "osObjects.h"

volatile uint32_t globADC_Value = 0;	// global ADC value

extern TIM_HandleTypeDef htim1;
extern ADC_HandleTypeDef hadc1;

//-----------------------------------------------------------------------------
void Task_Measurement_Signal(void *argument)
{
	uint32_t locEventADC_Isr = 0;							// event accessor
	
	HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_1);	// enable TIMER1, CH1 to trigger ADC1
	HAL_ADC_Start_IT(&hadc1);									// enable ADC1 with interrupt
  
	while(1)
  {
	  // wait for ADC event from ADC isr
		locEventADC_Isr = osEventFlagsWait(eventGroupHandle_Measurement, BIT_0, osFlagsWaitAny, 500);			
		if ( (locEventADC_Isr & BIT_0) != 0 )									       // ADC event received
		{		
			printf("\nADC Value (12 Bit) = 0x%04X", globADC_Value);    // print ADC value (global variable) to serial port
		}												
		else																									       // signal receive error
		{
			printf("\nError Task_Measurement_Signal: event bit receive failed\n");
		}
  }
}
