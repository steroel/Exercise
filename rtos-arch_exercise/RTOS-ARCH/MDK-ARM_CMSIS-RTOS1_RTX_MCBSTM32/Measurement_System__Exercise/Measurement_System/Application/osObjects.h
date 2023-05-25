//Application specific operaring system object definitions
#ifndef __osObjects
#define __osObjects

#if (!defined (osObjectsPublic))
#define osObjectsExternal           // define RTOS objects with extern attribute
#endif

// used for printf output
#include <stdio.h>

// used for CMSIS
#include "cmsis_os.h"               

// used for hardware access
#include "LCD_KS0066U.h"
#include "MCBSTM32.h"

#define SIZE_QUEUE_COMMAND 									4
#define SIZE_QUEUE_ADC 											4

#define PRIORITY_TASK_HEARTBEAT 						osPriorityNormal
#define PRIORITY_TASK_HEARTBEAT_1						osPriorityNormal
#define PRIORITY_TASK_HEARTBEAT_2						osPriorityAboveNormal
#define PRIORITY_TASK_MEASUREMENT_SIGNAL 		osPriorityAboveNormal
#define PRIORITY_TASK_MEASUREMENT_QUEUE 		osPriorityAboveNormal
#define PRIORITY_TASK_PUSH_BUTTON 					osPriorityHigh


// global 'resources'  data ---------------------------------------------------

// global 'thread' functions --------------------------------------------------
/* 
Example:
extern void sample_name (void const *argument);         // thread function
extern osThreadId tid_sample_name;                      // thread id
osThreadDef (sample_name, osPriorityNormal, 1, 0);      // thread object
*/
extern void Task_Heartbeat(void const *argument);
extern osThreadId taskHandle_Heartbeat_1;
extern osThreadId taskHandle_Heartbeat_2;
osThreadDef(Task_Heartbeat, PRIORITY_TASK_HEARTBEAT, 2, 100);

extern void Task_Measurement_Signal(void const *argument);
extern osThreadId taskHandle_Measurement_Signal;
osThreadDef(Task_Measurement_Signal, PRIORITY_TASK_MEASUREMENT_SIGNAL, 1, 0);

extern void Task_Measurement_Queue(void const *argument);
extern osThreadId taskHandle_Measurement_Queue;
osThreadDef(Task_Measurement_Queue, PRIORITY_TASK_MEASUREMENT_QUEUE, 1, 0);

extern void Task_PushButton(void const *argument);
extern osThreadId taskHandle_PushButton;
osThreadDef(Task_PushButton, PRIORITY_TASK_PUSH_BUTTON, 1, 0);


// global 'semaphores' --------------------------------------------------------
/* 
Example:
extern osSemaphoreId sid_sample_name;                   // semaphore id
osSemaphoreDef (sample_name);                           // semaphore object
*/


// global 'mutexes' -----------------------------------------------------------
/* 
Example:
extern osMutexId mtx_sample_name;                       // mutex id
osMutexDef (sample_name);                               // mutex object
*/
extern osMutexId mutex_Display;
osMutexDef(mutex_Display);


// global 'memory pools' ------------------------------------------------------
/* 
Example:
typedef struct sample_name type_sample_name;            // object data type
extern osPoolId mpid_sample_name;                       // memory pool id
osPoolDef (sample_name, 16, type_sample_name);          // memory pool object
*/


// global 'message queues' ----------------------------------------------------
/* 
Example:
typedef struct sample_name type_sample_name;            // object data type
osMessageQId mid_sample_name;                           // message queue id
osMessageQDef (sample_name, 16, type_sample_name);      // message queue object
*/


// global 'mail queues' -------------------------------------------------------
/* 
Example:
typedef struct sample_name type_sample_name;            // object data type
osMailQId qid_sample_name;                              // mail queue id
osMailQDef (sample_name, 16, type_sample_name);         // mail queue object
*/
typedef struct
{
	uint32_t ID;
	uint16_t ADC_Value;
} ADC_Message_t;																				// ADC message definition

extern osMailQId	queueHandle_ADC_Measurement;
osMailQDef(queueHandle_ADC_Measurement, SIZE_QUEUE_ADC, ADC_Message_t);

typedef struct
{
	uint32_t ID;
	uint32_t Command;
} Command_Message_t;																		// command message definition

extern osMailQId	queueHandle_Command_Measurement;
osMailQDef(queueHandle_Command_Measurement, SIZE_QUEUE_COMMAND, Command_Message_t);


// global 'timers and callbacks' ----------------------------------------------
extern void Callback_timer_PushButton(void const *argument);
osTimerDef(timer_PushButton, Callback_timer_PushButton);


#endif  // __osObjects
