#include "osObjects.h"

// global 'resource' data -----------------------------------------------------


// global 'task' handles ------------------------------------------------------
TaskHandle_t taskHandle_Init = NULL;
TaskHandle_t taskHandle_Heartbeat_1 = NULL;
TaskHandle_t taskHandle_Heartbeat_2 = NULL;
TaskHandle_t taskHandle_Measurement_Signal = NULL;
TaskHandle_t taskHandle_Measurement_Queue = NULL;
TaskHandle_t taskHandle_PushButton = NULL;


// global 'semaphore' handles -------------------------------------------------


// global 'mutex' handles -----------------------------------------------------
SemaphoreHandle_t mutex_Display = NULL;


// global 'memory pool' handles -----------------------------------------------


// global 'event group' handles -----------------------------------------------
EventGroupHandle_t eventGroupHandle_Measurement = NULL;
EventGroupHandle_t eventGroupHandle_PushButton = NULL;

// global 'message queue' handles ---------------------------------------------
QueueHandle_t	queueHandle_ADC_Measurement = NULL;
QueueHandle_t	queueHandle_Command_Measurement = NULL;

// global 'OS calllback' functions --------------------------------------------
void vApplicationStackOverflowHook( TaskHandle_t xTask, signed char *pcTaskName )
{
	printf("Fatal error: Stack overflow from task %s\n", pcTaskName);
	TIM_Cmd(TIM2, DISABLE);	// disable TIM2 to aviod anymore ADC interrupts	
	while(1);
}
