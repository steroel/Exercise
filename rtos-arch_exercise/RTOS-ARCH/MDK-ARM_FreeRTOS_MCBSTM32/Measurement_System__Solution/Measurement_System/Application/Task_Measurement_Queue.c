#include "osObjects.h"

//-----------------------------------------------------------------------------
void Task_Measurement_Queue(void *argument)
{
	uint32_t locADC_Value = 0;						// received ADC value from ADC isr
	float locVoltage = 0;									// float voltage value, based on the ADC value (12 bit) and reference voltage (3,3V) 
	
	uint32_t locMode = 1;									// current mode
	const uint32_t locModeMax = 3;				// max mode count
	
	ADC_Message_t locADC_Message;					// ADC message receive buffer
	Command_Message_t locCommandMessage;	// command message receive buffer
		
	char locCharBuffer[10];								// char buffer for interger/float to string convertion
	
	TIM_Cmd(TIM2, ENABLE);								// enable TIM2	
	
  while(1)
  {
	  // wait for ADC message
		if (xQueueReceive(queueHandle_ADC_Measurement, &locADC_Message, 500) == pdTRUE)	
		{																																					// ADC message received
			locADC_Value  = locADC_Message.ADC_Value;																// read ADC value from message
							
			// read command message without waiting
			if (xQueueReceive(queueHandle_Command_Measurement, &locCommandMessage, 0) == pdTRUE)
			{ 																																			// command message received action
				//printf("message id = %i  ", locCommandMessage.ID );
				//printf("message command id = %i\n", locCommandMessage.Command);
					
				if ((locCommandMessage.ID == 1) && (locCommandMessage.Command == 22))	// check for the right messages
				{
					if(locMode < locModeMax)		// check for the final output mode
					{
						locMode = locMode + 1;		// change output mode to the next one
					}
					else
					{
						locMode = 1;							// first output mode is set
					}
				}
				else	// invalide message receided
				{
					printf("Error Task_Measurement_Queue: Command message invalid\n");
				}					
			}
			else  // no message received
			{
				// no output mode change - for this application, this is no error case
				//printf("Error Task_Measurement_Queue: command message receive failed\n");
			}
				
			switch(locMode)	// state machine for different output modes
			{
				case 1:
					locVoltage = 3.3 * locADC_Value / 0xFFF;										// calculate float valtage value, based on 12 bit ADC and 3,3V reference voltage
					snprintf (locCharBuffer, 5, "%f", locVoltage); 							// convert float voltage value to a string
				
					if (xSemaphoreTake(mutex_Display, portMAX_DELAY) == pdTRUE)	// wait for display mutex
					{																														// display access
						LCD_printStringXY(0, 0, "               ");								// delete 1st display line with the exception of the last segment (push button pressed/unpressed)
						LCD_printStringXY(13, 0, "M1");														// display mode
						LCD_printStringXY(0, 0, "U = ");
						LCD_printStringXY(4, 0, &locCharBuffer[0]);								// dispaly voltage value
						LCD_printStringXY(9, 0, "V");
						LCD_printBargraphXY(0, 1, locADC_Value / 51);        			// display ADC value as bargraph (X pixel / (16 sements * 5 pixel) = locADC_Value / 4096 )
						
						if (xSemaphoreGive(mutex_Display) != pdTRUE)							// release display mutex
						{
							printf("Error Task_Measurement_Queue: mutex unlock failed\n");
						}
						else // mutex release successful
						{
							// nothing to do
						}
					}
					else
					{
						printf("Error Task_Measurement_Queue: mutex lock failed\n");
					}
				break;
					
				case 2:
					snprintf (locCharBuffer, (size_t)7, "0x%04X", locADC_Value); 	// convert ADC value into hex value string
					
					if (xSemaphoreTake(mutex_Display, portMAX_DELAY) == pdTRUE)			// wait for display mutex
					{																																// display access
						LCD_printStringXY(0, 0, "               ");										// delete 1st display line with the exception of the last segment (push button pressed/unpressed)
						LCD_printStringXY(13, 0, "M2");																// display mode
						LCD_printStringXY(0, 0, "ADC = ");
						LCD_printStringXY(6, 0, &locCharBuffer[0]);										// display ADC value
						LCD_printBargraphXY(0, 1, locADC_Value / 51);									// display ADC value as bargraph (X pixel / (16 sements * 5 pixel) = locADC_Value / 4096 )

						if (xSemaphoreGive(mutex_Display) != pdTRUE)									// release display mutex
						{
							printf("Error Task_Measurement_Queue: mutex unlock failed\n");
						}
						else // mutex release successful
						{
							// nothing to do
						}
					}
					else
					{
						printf("Error Task_Measurement_Queue: mutex lock failed\n");
					}
				break;
					
				case 3:
					if (xSemaphoreTake(mutex_Display, portMAX_DELAY) == pdTRUE)			// wait for display mutex
					{																																// display access
						LCD_printStringXY(0, 0, "               ");										// delete 1st display line with the exception of the last segment (push button pressed/unpressed)
						LCD_printStringXY(13, 0, "M3");																// display mode
						LCD_printStringXY(0, 0, "Serial Out");
						LCD_printBargraphXY(0, 1, locADC_Value / 51);									// display ADC value as bargraph (X pixel / (16 sements * 5 pixel) = locADC_Value / 4096 )
				
						if (xSemaphoreGive(mutex_Display) != pdTRUE)									// release display mutex
						{
							printf("Error Task_Measurement_Queue: mutex unlock failed\n");
						}
						else // mutex release successful
						{
							// nothing to do
						}
					}
					else
					{
						printf("Error Task_Measurement_Queue: mutex lock failed\n");
					}
					
					locVoltage = 3.3 * locADC_Value / 0xFFF;		// calculate float valtage value, based on 12 bit ADC and 3,3V reference voltage
					printf("Mode = %d\n", locMode);							// print current mode to serial port
				  printf("U    = %.2f V\n", locVoltage);     	// print voltage value to serial port
					printf("ADC  = 0x%04X\n", locADC_Value);    // print ADC value to serial port
				break;
					
				default:
					printf("Error Task_Measurement: output mode selection failed\n");
				break;
			}		
		}
		else
		{
			printf("Error Task_Measurement_Queue: ADC message receive failed\n");
		}
  }
}

//-----------------------------------------------------------------------------
void ADC1_2_IRQHandler(void) __irq													// ADC interrupt service routine
{
	ADC_Message_t locSendMessage;															// local Message Buffer
	
	BaseType_t locHigherPriorityTaskWoken = pdFALSE;
	
	ADC_ClearITPendingBit(ADC1, ADC_FLAG_EOC);								// clear ADC1 pending bit
	// prepare message to be send
	locSendMessage.ID = 1;
	locSendMessage.ADC_Value = ADC_GetConversionValue(ADC1);	// read ACD1 result
	
	// send message with ADC result to task
	if (xQueueSendFromISR(queueHandle_ADC_Measurement, &locSendMessage, &locHigherPriorityTaskWoken) != pdFALSE)	
	{
		portYIELD_FROM_ISR(locHigherPriorityTaskWoken);					// context switch request
	}
	else
	{
		printf("Error ADC1_2_IRQHandler: ADC message send failed\n");
	}
	
	LED_toggle(LED5);	// for measurement purpose only ==> 100ms on time, 100ms off time
}
