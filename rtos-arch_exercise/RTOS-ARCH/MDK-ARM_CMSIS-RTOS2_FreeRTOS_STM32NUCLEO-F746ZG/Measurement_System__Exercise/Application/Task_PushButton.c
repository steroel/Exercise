#include "osObjects.h"

//-----------------------------------------------------------------------------
static void PushButton_indicatePressed(void)
{
	BSP_LED_On(LED_BLUE);																			// pressed: LD2 is set to on state
		
	if (osMutexAcquire(mutex_Display, osWaitForever) == osOK)	// request the display as resource
	{																													// successful
		// BSP_LCD_printStringXY(0, 0, "*");											  // access display resource
		if (osMutexRelease(mutex_Display) != osOK)							// release display resource
		{
			printf("\nError Task_PushButton: mutex unlock failed\n");
		}
		else																										// display resource release successful
		{
			// nothing to do
		}
	}
	else																											// display resouce request failed
	{
		printf("\nError Task_PushButton: mutex lock failed\n");
	}
}

//-----------------------------------------------------------------------------
static void PushButton_indicateReleased(void)
{
	BSP_LED_Off(LED_BLUE);																		// release: LD2 is set to off state
}

//-----------------------------------------------------------------------------
static void Callback_Timer_PushButton(void* parCallbackTimerID)
{
	if (*((uint32_t*)parCallbackTimerID) == 0)	// timer ID 0 for PushButton Timer	
	{
		osEventFlagsSet(eventGroupHandle_PushButton, BIT_0);
		BSP_LED_Toggle(LED_RED);	// for measurement purpose only ==> 100ms on time, 100ms off time
	}
	else
	{
		printf("\nError Callback_Timer_PushButton: unsupported timer ID received\n");
	}
}

//-----------------------------------------------------------------------------
void Task_PushButton(void *argument)
{
	uint32_t locPushButtonStateCurrent  = 10;		   // push button state
	uint32_t locPushButtonStatePrevious = 11;		   // previous push button state
	Command_Message_t locCommandMessage = {0, 0};	 // local message buffer
		
	const uint32_t locPollTime = 100;	          // polling 100ms;
	
	uint32_t locEventTimerCallback = 0;					// event accessor
	osTimerId_t timerHandle_PushButton = NULL;	// local timer handle
	
	const uint32_t locPushButton_TimerID = 0;   // timer callback argument
	
	// create interval timer
	timerHandle_PushButton = osTimerNew(Callback_Timer_PushButton, osTimerPeriodic, (void* const)&locPushButton_TimerID, NULL);		
	
	if (timerHandle_PushButton != NULL)												// interval timer creation successful
	{
		if (osTimerStart(timerHandle_PushButton, locPollTime) == osOK)	// start interval timer
		{
			while(1)
			{	// wait for timer callback event
				locEventTimerCallback = osEventFlagsWait(eventGroupHandle_PushButton, BIT_0, osFlagsWaitAny, osWaitForever);				
				if( (locEventTimerCallback & BIT_0) != 0)															// signal reveived
				{
					locPushButtonStateCurrent = BSP_PB_GetState(BUTTON_USER);				  	// read push button state
					
					if (locPushButtonStateCurrent == 1)																	// push button pressed
					{
						PushButton_indicatePressed();																			// indicate pressed push button to display
						
						if((locPushButtonStateCurrent != locPushButtonStatePrevious) &&
					     (locPushButtonStatePrevious != 11))														// action for pressed push button if not startup
						{
							// no push button pressed action
						}
					}
					else if(locPushButtonStateCurrent == 0)  														// push button released 
					{
						PushButton_indicateReleased();
						
						if((locPushButtonStateCurrent != locPushButtonStatePrevious) &&
					     (locPushButtonStatePrevious != 11))  													// action for released push button if not startup
						{
							locCommandMessage.ID = 1;
							locCommandMessage.Command = 22;
							// send command message to measurement task
							if (osMessageQueuePut(queueHandle_Command_Measurement, &locCommandMessage, 0, 10) == osOK)	
							{
								// nothing to do
							}
							else
							{
								printf("\nError Task_PushButton: command message send failed\n");
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
					printf("\nError Task_PushButton: timer callback failed\n");
				}
			}
		}
		else	// interval timer start failed
		{
			printf("\nError Task_PushButton: timer start failed\n");
			osThreadExit();	// terminate push button task
		}
	}
	else	// interval timer creation failed
	{
		printf("\nError Task_PushButton: timer create failed\n");
		osThreadExit();	// terminate push button task
	}
}
