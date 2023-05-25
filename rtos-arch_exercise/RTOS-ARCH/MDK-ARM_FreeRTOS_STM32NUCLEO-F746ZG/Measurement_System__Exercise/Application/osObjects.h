//Application specific operaring system object definitions
#ifndef __osObjects
#define __osObjects

#include "main.h"
#include <stdio.h>

// used for FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "event_groups.h"
#include "timers.h"

#include "LCD.h"

#define SIZE_QUEUE_COMMAND 									4
#define SIZE_QUEUE_ADC 											4

#define PRIORITY_TASK_IDLE									tskIDLE_PRIORITY
#define PRIORITY_TASK_INIT 									tskIDLE_PRIORITY + 4
#define PRIORITY_TASK_HEARTBEAT		 					tskIDLE_PRIORITY + 1
#define PRIORITY_TASK_HEARTBEAT_1 					tskIDLE_PRIORITY + 1
#define PRIORITY_TASK_HEARTBEAT_2 					tskIDLE_PRIORITY + 2
#define PRIORITY_TASK_MEASUREMENT_SIGNAL 		tskIDLE_PRIORITY + 2
#define PRIORITY_TASK_MEASUREMENT_QUEUE 		tskIDLE_PRIORITY + 2
#define PRIORITY_TASK_PUSH_BUTTON 					tskIDLE_PRIORITY + 3

#define BIT_0	(1 << 0)

// global 'resources' data ----------------------------------------------------
extern Led_TypeDef LED_Heartbeat_1;
extern Led_TypeDef LED_Heartbeat_2;

// global 'task' functions ----------------------------------------------------
extern void Task_Init(void *argument);
extern TaskHandle_t taskHandle_Init;

extern void Task_Heartbeat(void *argument);
extern TaskHandle_t taskHandle_Heartbeat_1;
extern TaskHandle_t taskHandle_Heartbeat_2;

extern void Task_Measurement_Signal(void *argument);
extern TaskHandle_t taskHandle_Measurement_Signal;

extern void Task_Measurement_Queue(void *argument);
extern TaskHandle_t taskHandle_Measurement_Queue;

extern void Task_PushButton(void *argument);
extern TaskHandle_t taskHandle_PushButton;

// global 'mutexes' -----------------------------------------------------------
extern SemaphoreHandle_t mutex_Display;

// global 'event groups' ------------------------------------------------------
extern EventGroupHandle_t eventGroupHandle_Measurement;
extern EventGroupHandle_t eventGroupHandle_PushButton;

// global 'messages and queues' -----------------------------------------------
typedef struct
{
	uint32_t ID;
	uint16_t ADC_Value;
} ADC_Message_t;	// ADC message definition

extern QueueHandle_t	queueHandle_ADC_Measurement;

typedef struct
{
	uint32_t ID;
	uint32_t Command;
} Command_Message_t;	// command message definition

extern QueueHandle_t	queueHandle_Command_Measurement;


#endif  // __osObjects
