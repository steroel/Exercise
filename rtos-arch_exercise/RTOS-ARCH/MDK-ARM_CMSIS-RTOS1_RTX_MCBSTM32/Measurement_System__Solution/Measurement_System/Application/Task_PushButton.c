#include "osObjects.h"

#define BIT_0	(1 << 0)

//-----------------------------------------------------------------------------
static void PushButton_indicatePressed(void)
{
	LED_setOn(LED4);																				// pressed: LED4 is set to on state 
	
	if (osMutexWait(mutex_Display, osWaitForever) == osOK)	// request the display as resource
	{																												// successful
		LCD_printStringXY(15, 0, "_");												// access display resource
		if (osMutexRelease(mutex_Display) != osOK)						// release display resource
		{
			printf("Error Task_PushButton: mutex unlock failed\n");
		}
		else																									// display resource release successful
		{
			// nothing to do
		}
	}
	else																										// display resouce request failed
	{
		printf("Error Task_PushButton: mutex lock failed\n");
	}
}

//-----------------------------------------------------------------------------
static void PushButton_indicateReleased(void)
{
	LED_setOff(LED4);																				// release: LED4 is set to off state 
	
	if (osMutexWait(mutex_Display, osWaitForever) == osOK)	// request the display resource
	{																												// successful
		LCD_printStringXY(15, 0, "-");												// access display resource
		if (osMutexRelease(mutex_Display) != osOK)						// release display resource
		{
			printf("Error Task_PushButton: mutex unlock failed\n");
		}
		else																									// display resource release successful
		{
			// nothing to do
		}
	}
	else																										// display resouce request failed  
	{
		printf("Error Task_PushButton: mutex lock failed\n");
	}
}

//-----------------------------------------------------------------------------
void Callback_timer_PushButton(void const *argument)
{
	osSignalSet(taskHandle_PushButton, BIT_0);								// set signal to push button task
}

//-----------------------------------------------------------------------------
void Task_PushButton(void const *argument)
{
	uint32_t locPushButtonStateCurrent  = 10;								// push button state
	uint32_t locPushButtonStatePrevious = 11;								// previous push button state
	Command_Message_t* locPtrCommandMessage = NULL;					// local message pointer
	
	osEvent locEventTimerCallback;													// event/message accessor
	osTimerId timerHandle_PushButton;												// local timer handle
	
	timerHandle_PushButton = osTimerCreate(osTimer(timer_PushButton), osTimerPeriodic, NULL);		// create interval timer
	
	if (timerHandle_PushButton != NULL)												// interval timer creation successful
	{
		if (osTimerStart(timerHandle_PushButton, 100) == osOK)	// start interval timer
		{
			while(1)
			{
				locEventTimerCallback = osSignalWait(BIT_0, osWaitForever);						// wait for interrupt callback signal
				if(locEventTimerCallback.status == osEventSignal)											// signal reveived
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
							locPtrCommandMessage = osMailCAlloc(queueHandle_Command_Measurement, 0);	// allocate memory for reeciever message
						
							if (locPtrCommandMessage!= NULL)																					// memeory allocation successful
							{
								locPtrCommandMessage -> ID = 1;
								locPtrCommandMessage -> Command = 22;
								if (osMailPut(queueHandle_Command_Measurement, locPtrCommandMessage) != osOK)	// send command message to measurement task
								{
									printf("Error Task_PushButton: command message send failed\n");
								}
							}
							else	// memory allcation failed
							{
								printf("Error Task_PushButton: command memory allocation failed\n");
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
			osThreadTerminate(osThreadGetId());
		}
	}
	else	// interval timer creation failed
	{
		printf("Error Task_PushButton: timer create failed\n");
		osThreadTerminate(osThreadGetId());
	}
}
