#include "osObjects.h"

//-----------------------------------------------------------------------------
void Task_Init(void *argument)	// creates all OS elements
{
	// create event group
	eventGroupHandle_Measurement = osEventFlagsNew(NULL);
	if (eventGroupHandle_Measurement == NULL)		// event group creation failed
	{
		printf("\nFatal error Task_Init: event group measurement creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nEvent_Group_Measurement created successful ...");
	}

	eventGroupHandle_PushButton = osEventFlagsNew(NULL);
	if (eventGroupHandle_PushButton == NULL)		// event group creation failed
	{
		printf("\nFatal error Task_Init: event group push button creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nEvent_Group_PushButton created successful ...");
	}
	
  // create mailbox
	
	queueHandle_ADC_Measurement = osMessageQueueNew(SIZE_QUEUE_ADC, sizeof(ADC_Message_t), NULL);
	if (queueHandle_ADC_Measurement == NULL)		// message queue creation failed
	{
		printf("\nFatal error Task_Init: ADC message queue creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nQueue_ADC_Measurement created successful ...");
	}
	
	queueHandle_Command_Measurement = osMessageQueueNew(SIZE_QUEUE_COMMAND, sizeof(Command_Message_t), NULL);
	if (queueHandle_Command_Measurement == NULL)	// ADC queue creation failed
	{
		printf("\nFatal error Task_Init: command message queue creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nQueue_Command_Measurement created successful ...");
	}
	
	// create mutex
	
	mutex_Display = osMutexNew(&Mutex_Display_attributes);
	if (mutex_Display == NULL)
	{
		printf("\nFatal error Task_Init: display mutex creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nMutex_Display created successful ...");
	}
	

// create task

	taskHandle_Heartbeat_1 = osThreadNew(Task_Heartbeat, &LED_Heartbeat_1, &Task_Heartbeat_1_attributes);
	if (taskHandle_Heartbeat_1 != NULL)
	{
		printf("\nTask_Heartbeat_1 created successful ...");
	}
	else
	{
		printf("Fatal error Task_Init: Task_Heartbeat_1 creation failed\n");
	}
	
//	taskHandle_Heartbeat_2 = osThreadNew(Task_Heartbeat, &LED_Heartbeat_2, &Task_Heartbeat_2_attributes);
//	if (taskHandle_Heartbeat_2 != NULL)
//	{
//		printf("\nTask_Heartbeat_2 created successful ...");
//	}
//	else
//	{
//		printf("Fatal error Task_Init: Task_Heartbeat_2 creation failed\n");
//	}
	
//	taskHandle_Measurement_Signal = osThreadNew(Task_Measurement_Signal, NULL, &Task_Measurement_Signal_attributes);
//	if (taskHandle_Measurement_Signal != NULL)
//	{
//		printf("\nTask_Measurement_Signal created successful ...");
//	}
//	else
//	{
//		printf("Fatal error Task_Init: Task_Measurement_Signal creation failed\n");
//	}
	
	taskHandle_Measurement_Queue = osThreadNew(Task_Measurement_Queue, NULL, &Task_Measurement_Queue_attributes);
	if (taskHandle_Measurement_Queue != NULL)
	{
		printf("\nTask_Measurement_Queue created successful ...");
	}
	else
	{
		printf("Fatal error Task_Init: Task_Measurement_Queue creation failed\n");
	}
	
	taskHandle_PushButton = osThreadNew(Task_PushButton, NULL, &Task_PushButton_attributes);
	if (taskHandle_PushButton != NULL)
	{
		printf("\nTask_PushButton created successful ...");
	}
	else
	{
		printf("Fatal error Task_Init: Task_PushButton creation failed\n");
	}
	
	printf("\nTask_Init terminating ...\n");
	// delete init task
	osThreadExit();	// delete init task
}
