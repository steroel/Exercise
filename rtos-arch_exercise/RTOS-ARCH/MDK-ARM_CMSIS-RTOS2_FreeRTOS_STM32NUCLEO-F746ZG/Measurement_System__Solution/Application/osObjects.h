//Application specific operaring system object definitions
#ifndef __osObjects
#define __osObjects

#include "main.h"
#include <stdio.h>
#include "cmsis_os.h"

#include "LCD.h"

#define SIZE_QUEUE_COMMAND 									4
#define SIZE_QUEUE_ADC 											4

#define PRIORITY_TASK_IDLE									osPriorityIdle
#define PRIORITY_TASK_INIT 									osPriorityIdle + 4
#define PRIORITY_TASK_HEARTBEAT		 					osPriorityIdle + 1
#define PRIORITY_TASK_HEARTBEAT_1 					osPriorityIdle + 1
#define PRIORITY_TASK_HEARTBEAT_2 					osPriorityIdle + 2
#define PRIORITY_TASK_MEASUREMENT_SIGNAL 		osPriorityIdle + 2
#define PRIORITY_TASK_MEASUREMENT_QUEUE 		osPriorityIdle + 2
#define PRIORITY_TASK_PUSH_BUTTON 					osPriorityIdle + 3

#define BIT_0	(1 << 0)

// global 'resources' data ----------------------------------------------------
extern Led_TypeDef LED_Heartbeat_1;
extern Led_TypeDef LED_Heartbeat_2;

// global 'task' functions ----------------------------------------------------
extern osThreadId_t defaultTaskHandle;
extern const osThreadAttr_t defaultTask_attributes;

extern void Task_Init(void *argument);
extern osThreadId_t taskHandle_Init;
extern const osThreadAttr_t Task_Init_attributes;

extern void Task_Heartbeat(void *argument);
extern osThreadId_t taskHandle_Heartbeat_1;
extern const osThreadAttr_t Task_Heartbeat_1_attributes;

extern osThreadId_t taskHandle_Heartbeat_2;
extern const osThreadAttr_t Task_Heartbeat_2_attributes;

extern void Task_Measurement_Signal(void *argument);
extern osThreadId_t taskHandle_Measurement_Signal;
extern const osThreadAttr_t Task_Measurement_Signal_attributes;

extern void Task_Measurement_Queue(void *argument);
extern osThreadId_t taskHandle_Measurement_Queue;
extern const osThreadAttr_t Task_Measurement_Queue_attributes;

extern void Task_PushButton(void *argument);
extern osThreadId_t taskHandle_PushButton;
extern const osThreadAttr_t Task_PushButton_attributes;

// global 'mutexes' -----------------------------------------------------------
extern osMutexId_t mutex_Display;
extern const osMutexAttr_t Mutex_Display_attributes;

// global 'event groups' ------------------------------------------------------
extern osEventFlagsId_t eventGroupHandle_Measurement; 
extern osEventFlagsId_t eventGroupHandle_PushButton;

// global 'messages and queues' -----------------------------------------------
typedef struct
{
	uint32_t ID;
	uint16_t ADC_Value;
} ADC_Message_t;	// ADC message definition

extern osMessageQueueId_t	queueHandle_ADC_Measurement;

typedef struct
{
	uint32_t ID;
	uint32_t Command;
} Command_Message_t;	// command message definition

extern osMessageQueueId_t	queueHandle_Command_Measurement;


#endif  // __osObjects
