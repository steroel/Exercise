#include "osObjects.h"

//-----------------------------------------------------------------------------
void Task_Init(void *argument)	// creates all OS elements
{
	// create event group
	eventGroupHandle_Measurement = xEventGroupCreate();
	if (eventGroupHandle_Measurement == NULL)		// event group creation failed
	{
		printf("\nFatal error Task_Init: event group measurement creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nEvent_Group_Measurement created successful ...");
	}
	
	eventGroupHandle_PushButton = xEventGroupCreate();
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
	queueHandle_ADC_Measurement = xQueueCreate(SIZE_QUEUE_ADC, sizeof(ADC_Message_t));
	if (queueHandle_ADC_Measurement == NULL)	// command queue creation failed
	{
		printf("\nFatal error Task_Init: ADC message queue creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nQueue_ADC_Measurement created successful ...");
	}
	
	queueHandle_Command_Measurement = xQueueCreate(SIZE_QUEUE_COMMAND, sizeof(Command_Message_t));
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
	mutex_Display = xSemaphoreCreateMutex();
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
	if (xTaskCreate(Task_Heartbeat, 
		              "Task_Heartbeat_1",
									configMINIMAL_STACK_SIZE,
									&LED_Heartbeat_1,
									PRIORITY_TASK_HEARTBEAT_1,
									&taskHandle_Heartbeat_1)
			!= pdPASS)
	{															// task creation failed
		printf("\nFatal error Task_Init: Task_Heartbeat_1 creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nTask_Heartbeat_1 created successful ...");
	}
	
//	if (xTaskCreate(Task_Heartbeat,
//		              "Task_Heartbeat_2",
//									configMINIMAL_STACK_SIZE,
//									&LED_Heartbeat_2,
//									PRIORITY_TASK_HEARTBEAT_2,
//									&taskHandle_Heartbeat_2)
//			!= pdPASS)
//	{															// task creation failed
//		printf("\nFatal error Task_Init: Task_Heartbeat_2 creation failed\n");
//		Error_Handler();
//	}
//	else
//	{
//		printf("\nTask_Heartbeat_2 created successful ...");
//	}
		
//	if (xTaskCreate(Task_Measurement_Signal,
//		              "Task_Measurement_Signal",
//									configMINIMAL_STACK_SIZE,
//									NULL,
//									PRIORITY_TASK_MEASUREMENT_SIGNAL,
//									&taskHandle_Measurement_Signal)
//			!= pdPASS)
//	{															// task creation failed
//		printf("\nFatal error Task_Init: Task_Measurement_Signal creation failed\n");
//		Error_Handler();
//	}
//	else
//	{
//		printf("\nTask_Measurement_Signal created successful ...");
//	}

	if (xTaskCreate(Task_Measurement_Queue,
		              "Task_Measurement_Queue",
									configMINIMAL_STACK_SIZE + 100,
									NULL,
	                PRIORITY_TASK_MEASUREMENT_QUEUE,
	                &taskHandle_Measurement_Queue)
    	!= pdPASS)
	{															// task creation failed
		printf("\nFatal error Task_Init: Task_Measurement_Queue creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nTask_Measurement_Queue created successful ...");
	}
	
	if (xTaskCreate(Task_PushButton,
		              "Task_PushButton",
                  configMINIMAL_STACK_SIZE,
                	NULL,
									PRIORITY_TASK_PUSH_BUTTON,
									&taskHandle_PushButton)
			!= pdPASS)
	{															// task creation failed
		printf("\nFatal error Task_Init: Task_PushButton creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nTask_PushButton created successful ...");
	}
	
	printf("\nTask_Init terminating ...\n");
	vTaskDelete(taskHandle_Init);	// delete init task
}
