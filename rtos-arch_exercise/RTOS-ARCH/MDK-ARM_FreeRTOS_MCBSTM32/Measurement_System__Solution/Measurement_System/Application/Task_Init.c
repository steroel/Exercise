#include "osObjects.h"

//-----------------------------------------------------------------------------
void Task_Init(void *argument)	// creates all OS elements
{
	// create event group
	eventGroupHandle_Measurement = xEventGroupCreate();
	if (eventGroupHandle_Measurement == NULL)		// event group creation failed
	{
		printf("Fatal error Task_Init: event group measurement creation failed\n");
		while(1);																	// application stops here
	}
	else
	{
		// nothing to do
	}
	
	eventGroupHandle_PushButton = xEventGroupCreate();
	if (eventGroupHandle_PushButton == NULL)		// event group creation failed
	{
		printf("Fatal error Task_Init: event group push button creation failed\n");
		while(1);																	// application stops here
	}
	else
	{
		// nothing to do
	}
	
  // create mailbox
	queueHandle_ADC_Measurement = xQueueCreate(SIZE_QUEUE_ADC, sizeof(ADC_Message_t));
	if (queueHandle_ADC_Measurement == NULL)	// command queue creation failed
	{
		printf("Fatal error Task_Init: ADC message queue creation failed\n");
		while(1);																// application stops here
	}
	else
	{
		// nothing to do
	}
	
	queueHandle_Command_Measurement = xQueueCreate(SIZE_QUEUE_COMMAND, sizeof(Command_Message_t));
	if (queueHandle_Command_Measurement == NULL)	// ADC queue creation failed
	{
		printf("Fatal error Task_Init: command message queue creation failed\n");
		while(1);																// application stops here
	}
	else
	{
		// nothing to do
	}
	
	// create mutex
	mutex_Display = xSemaphoreCreateMutex();
	if (mutex_Display == NULL)
	{
		printf("Fatal error Task_Init: display mutex creation failed\n");
		while(1);																// application stops here
	}
	else
	{
		// nothing to do
	}
	
	// create task
	if (xTaskCreate(Task_Heartbeat, 
		              "Task_Heartbeat_1",
									configMINIMAL_STACK_SIZE,
									(void*) LED1,
									PRIORITY_TASK_HEARTBEAT_1,
									&taskHandle_Heartbeat_1)
			!= pdPASS)
	{															// task creation failed
		printf("Fatal error Task_Init: Task_Heartbeat_1 creation failed\n");
		while(1);										// application stops here
	}
	else
	{
		// nothing to do
	}
	
	if (xTaskCreate(Task_Heartbeat,
		              "Task_Heartbeat_2",
									configMINIMAL_STACK_SIZE,
									(void*) LED2,
									PRIORITY_TASK_HEARTBEAT_2,
									&taskHandle_Heartbeat_2)
			!= pdPASS)
	{															// task creation failed
		printf("Fatal error Task_Init: Task_Heartbeat_2 creation failed\n");
		while(1);										// application stops here
	}
	else
	{
		// nothing to do
	}
		
//	if (xTaskCreate(Task_Measurement_Signal,
//		              "Task_Measurement_Signal",
//									configMINIMAL_STACK_SIZE,
//									NULL,
//									PRIORITY_TASK_MEASUREMENT_SIGNAL,
//									&taskHandle_Measurement_Signal)
//			!= pdPASS)
//	{															// task creation failed
//		printf("Fatal error Task_Init: Task_Measurement_Signal creation failed\n");
//		while(1);										// application stops here
//	}
//	else
//	{
//		// nothing to do
//	}

	if (xTaskCreate(Task_Measurement_Queue,
		              "Task_Measurement_Queue",
									configMINIMAL_STACK_SIZE + 100,
									NULL,
	                PRIORITY_TASK_MEASUREMENT_QUEUE,
	                &taskHandle_Measurement_Queue)
    	!= pdPASS)
	{															// task creation failed
		printf("Fatal error Task_Init: Task_Measurement_Queue creation failed\n");
		while(1);										// application stops here
	}
	else
	{
		// nothing to do
	}
	
	if (xTaskCreate(Task_PushButton,
		              "Task_PushButton",
                  configMINIMAL_STACK_SIZE,
                	NULL,
									PRIORITY_TASK_PUSH_BUTTON,
									&taskHandle_PushButton)
			!= pdPASS)
	{															// task creation failed
		printf("Fatal error Task_Init: Task_PushButton creation failed\n");
		while(1);										// application stops here
	}
	else
	{
		// nothing to do
	}
	
	vTaskDelete(taskHandle_Init);	// delete init task
}
