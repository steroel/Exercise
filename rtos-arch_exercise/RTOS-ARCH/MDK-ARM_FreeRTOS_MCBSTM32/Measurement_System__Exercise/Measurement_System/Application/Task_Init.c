#include "osObjects.h"

//-----------------------------------------------------------------------------
void Task_Init(void *argument)	// creates all OS elements
{
	// create event group
//	eventGroupHandle_Measurement = ...;
//	if (eventGroupHandle_Measurement == NULL)		// event group creation failed
//	{
//		printf("Fatal error Task_Init: event group measurement creation failed\n");
//		while(1);																	// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}
	
//	eventGroupHandle_PushButton = ...;
//	if (eventGroupHandle_PushButton == NULL)		// event group creation failed
//	{
//		printf("Fatal error Task_Init: event group push button creation failed\n");
//		while(1);																	// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}
	
  // create mailbox
//	queueHandle_ADC_Measurement = ...;
//	if (queueHandle_ADC_Measurement == NULL)	// command queue creation failed
//	{
//		printf("Fatal error Task_Init: ADC message queue creation failed\n");
//		while(1);																// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}
	
//	queueHandle_Command_Measurement = ...;
//	if (queueHandle_Command_Measurement == NULL)	// ADC queue creation failed
//	{
//		printf("Fatal error Task_Init: command message queue creation failed\n");
//		while(1);																// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}
	
	// create mutex
//	mutex_Display = ...;
//	if (mutex_Display == NULL)
//	{
//		printf("Fatal error Task_Init: display mutex creation failed\n");
//		while(1);																// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}
	
	// create task
//	if (...
//			!= pdPASS)
	{															// task creation failed
		printf("Fatal error Task_Init: Task_Heartbeat_1 creation failed\n");
		while(1);										// application stops here
	}
//	else
	{
		// nothing to do
	}
	
//	if (...
//			!= pdPASS)
	{															// task creation failed
		printf("Fatal error Task_Init: Task_Heartbeat_2 creation failed\n");
		while(1);										// application stops here
	}
//	else
	{
		// nothing to do
	}
		
//	if (...
//			!= pdPASS)
//	{															// task creation failed
//		printf("Fatal error Task_Init: Task_Measurement_Signal creation failed\n");
//		while(1);										// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}

//	if (...
//    	!= pdPASS)
//	{															// task creation failed
//		printf("Fatal error Task_Init: Task_Measurement_Queue creation failed\n");
//		while(1);										// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}
	
//	if (...
//			!= pdPASS)
//	{															// task creation failed
//		printf("Fatal error Task_Init: Task_PushButton creation failed\n");
//		while(1);										// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}
	
//	...	// delete init task
}
