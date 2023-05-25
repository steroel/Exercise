#include "osObjects.h"

#define BIT_0	(1 << 0)

//-----------------------------------------------------------------------------
static void PushButton_indicatePressed(void)
{
	LED_setOn(LED4);																						// pressed: LED4 is set to on state 
	
	if (xSemaphoreTake(mutex_Display, portMAX_DELAY) == pdTRUE)	// request the display as resource
	{																														// successful
		LCD_printStringXY(15, 0, "_");														// access display resource
		if (xSemaphoreGive(mutex_Display) != pdTRUE)							// release display resource
		{
			printf("Error Task_PushButton: mutex unlock failed\n");
		}
		else																											// display resource release successful
		{
			// nothing to do
		}
	}
	else																												// display resouce request failed
	{
		printf("Error Task_PushButton: mutex lock failed\n");
	}
}

//-----------------------------------------------------------------------------
static void PushButton_indicateReleased(void)
{
	LED_setOff(LED4);																						// release: LED4 is set to off state 
	
	if (xSemaphoreTake(mutex_Display, portMAX_DELAY) == pdTRUE)	// request the display resource
	{																														// successful
		LCD_printStringXY(15, 0, "-");														// access display resource
		if (xSemaphoreGive(mutex_Display) != pdTRUE)							// release display resource
		{
			printf("Error Task_PushButton: mutex unlock failed\n");
		}
		else																											// display resource release successful
		{
			// nothing to do
		}
	}
	else																												// display resouce request failed  
	{
		printf("Error Task_PushButton: mutex lock failed\n");
	}
}

//-----------------------------------------------------------------------------
void Callback_timer_PushButton(TimerHandle_t parTimerHandle)
{
	if ( pvTimerGetTimerID(parTimerHandle) == 0)	// timer ID 0 for PushButton Timer	
	{
		xEventGroupSetBits(eventGroupHandle_PushButton, BIT_0);			// set signal to push button task
		//LED_toggle(LED5);	// for measurement purpose only ==> 100ms on time, 100ms off time
	}
	else
	{
		printf("Error Callback_timer_PushButton: unsupported timer ID received\n");
	}
}

//-----------------------------------------------------------------------------
void Task_PushButton(void *argument)
{
	uint32_t locPushButtonStateCurrent  = 10;									// push button state
	uint32_t locPushButtonStatePrevious = 11;									// previous push button state
	Command_Message_t locCommandMessage;											// local message buffer
	
	const TickType_t locPollTime = 100 / portTICK_PERIOD_MS;	// polling 100ms;
	
	EventBits_t locEventTimerCallback;												// event accessor
	TimerHandle_t timerHandle_PushButton;											// local timer handle
	
	// create interval timer
	timerHandle_PushButton = xTimerCreate("PushButton_Timer", locPollTime, pdTRUE, 0, Callback_timer_PushButton);		
	
	if (timerHandle_PushButton != NULL)												// interval timer creation successful
	{
		if (xTimerStart(timerHandle_PushButton, 10) == pdPASS)	// start interval timer
		{
			while(1)
			{	// wait for interrupt callback signal
				locEventTimerCallback = xEventGroupWaitBits(eventGroupHandle_PushButton, BIT_0, pdTRUE, pdFALSE, portMAX_DELAY);			
				if( (locEventTimerCallback & BIT_0) != 0)															// signal reveived
				{
					locPushButtonStateCurrent = PB_getState(BUTTON_TAMPER);							// read push button state
					
					if (locPushButtonStateCurrent == 0)																	// push button pressed
					{
						PushButton_indicatePressed();																			// indicate pressed push button to display
						
						if((locPushButtonStateCurrent != locPushButtonStatePrevious) &&
					     (locPushButtonStatePrevious != 11))														// action for pressed push button if not startup
						{
							// no push button pressed action
						}
					}
					else if(locPushButtonStateCurrent == 1)  														// push button released 
					{
						PushButton_indicateReleased();
						
						if((locPushButtonStateCurrent != locPushButtonStatePrevious) &&
					     (locPushButtonStatePrevious != 11))  													// action for released push button if not startup
						{
							locCommandMessage.ID = 1;
							locCommandMessage.Command = 22;
							// send command message to measurement task
							if (xQueueSend(queueHandle_Command_Measurement, (void*) &locCommandMessage, 10) == pdPASS)	
							{
								// nothing to do
							}
							else
							{
								printf("Error Task_PushButton: command message send failed\n");
							}
						}
						else	// action for released push button if startup
						{
							// nothing to do
						}
					}
					else	// push button not released
					{
						// nothig to do
					}
						
					locPushButtonStatePrevious = locPushButtonStateCurrent;	// remember push button state
					
				}
				else	// signal not received
				{
					printf("Error Task_PushButton: timer callback failed\n");
				}
			}
		}
		else	// interval timer start failed
		{
			printf("Error Task_PushButton: timer start failed\n");
			vTaskDelete(taskHandle_PushButton);	// delete push button task
		}
	}
	else	// interval timer creation failed
	{
		printf("Error Task_PushButton: timer create failed\n");
		vTaskDelete(taskHandle_PushButton);	// delete push button task
	}
}
