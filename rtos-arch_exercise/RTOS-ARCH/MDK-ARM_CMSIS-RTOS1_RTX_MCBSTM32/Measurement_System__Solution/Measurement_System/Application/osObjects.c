#include "cmsis_os.h"               // CMSIS RTOS header file

// global 'resources'  data ----------------------------------------------------


// global 'thread' handles -----------------------------------------------------
/* 
Example:
osThreadId tid_sample_name;                             // thread id
*/
osThreadId taskHandle_Heartbeat_1;
osThreadId taskHandle_Heartbeat_2;
osThreadId taskHandle_Measurement_Signal;
osThreadId taskHandle_Measurement_Queue;
osThreadId taskHandle_PushButton;


// global 'semaphores' handles --------------------------------------------------
/* 
Example:
osSemaphoreId sid_sample_name;                          // semaphore id
*/


// global 'mutexes' handles -----------------------------------------------------
/* 
Example:
osMutexId mtx_sample_name;                          		// mutex id
*/
osMutexId mutex_Display;


// global 'memory pools' handles ------------------------------------------------
/* 
Example:
osPoolId mpid_sample_name;                              // memory pool id
*/


// global 'message queues' handles ----------------------------------------------
/* 
Example:
osMessageQId mid_sample_name;                           // message queue id
*/


// global 'mail queues' handles -------------------------------------------------
/* 
Example:
osMailQId qid_sample_name;                              // mail queue id
*/
osMailQId	queueHandle_ADC_Measurement;
osMailQId	queueHandle_Command_Measurement;
