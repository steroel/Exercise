#include "osObjects.h"

//-----------------------------------------------------------------------------
int32_t Task_Init(void)	// creates all OS elements
{
  // create mailbox
	queueHandle_ADC_Measurement = osMailCreate(osMailQ(queueHandle_ADC_Measurement), NULL);
	if (queueHandle_ADC_Measurement == NULL) return(-1);
	
	queueHandle_Command_Measurement = osMailCreate(osMailQ(queueHandle_Command_Measurement), NULL);
	if (queueHandle_Command_Measurement == NULL) return(-1);
	
	// create mutex
	mutex_Display = osMutexCreate(osMutex(mutex_Display));
	if (mutex_Display == NULL) return(-1);
	
	// create task
	taskHandle_Heartbeat_1 = osThreadCreate (osThread(Task_Heartbeat), (void*)LED1);
	if (taskHandle_Heartbeat_1 == NULL) return(-1);
	//osThreadSetPriority(taskHandle_Heartbeat_1, PRIORITY_TASK_HEARTBEAT_1);

	taskHandle_Heartbeat_2 = osThreadCreate (osThread(Task_Heartbeat), (void*)LED2);
	if (taskHandle_Heartbeat_2 == NULL) return(-1);
	//osThreadSetPriority(taskHandle_Heartbeat_2, PRIORITY_TASK_HEARTBEAT_2);

//  taskHandle_Measurement_Signal = osThreadCreate (osThread(Task_Measurement_Signal), NULL);
//	if (taskHandle_Measurement_Signal == NULL) return(-1);	

	taskHandle_Measurement_Queue = osThreadCreate (osThread(Task_Measurement_Queue), NULL);
	if (taskHandle_Measurement_Queue == NULL) return(-1);	
	
	taskHandle_PushButton = osThreadCreate (osThread(Task_PushButton), NULL);
	if (taskHandle_PushButton == NULL) return(-1);	
  
  return(0);
}
