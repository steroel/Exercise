//exersize
#include "osObjects.h"

// global 'resource' data -----------------------------------------------------
Led_TypeDef LED_Heartbeat_1 = LED_GREEN;
Led_TypeDef LED_Heartbeat_2 = LED_BLUE;

//    global 'task' handles and task attributes-----------------------------------


osThreadId_t taskHandle_Init = NULL;
const osThreadAttr_t Task_Init_attributes = {
  .name       = "Task_Init",
  .priority   = (osPriority_t) PRIORITY_TASK_INIT,
  .stack_size = 128 * 3
};

osThreadId_t taskHandle_Heartbeat_1 = NULL;
const osThreadAttr_t Task_Heartbeat_1_attributes = {
  .name       = "Task_Heartbeat_1",
  .priority   = (osPriority_t) PRIORITY_TASK_HEARTBEAT_1,
  .stack_size = 128
};

osThreadId_t taskHandle_Heartbeat_2 = NULL;
const osThreadAttr_t Task_Heartbeat_2_attributes = {
  .name       = "Task_Heartbeat_2",
  .priority   = (osPriority_t) PRIORITY_TASK_HEARTBEAT_1,
  .stack_size = 128
};

osThreadId_t taskHandle_Measurement_Signal = NULL;
const osThreadAttr_t Task_Measurement_Signal_attributes = {
  .name       = "Task_Measurement_Signal",
  .priority   = (osPriority_t) PRIORITY_TASK_MEASUREMENT_SIGNAL,
  .stack_size = 128 * 4
};

osThreadId_t taskHandle_Measurement_Queue = NULL;
const osThreadAttr_t Task_Measurement_Queue_attributes = {
  .name       = "Task_Measurement_Queue",
  .priority   = (osPriority_t) PRIORITY_TASK_MEASUREMENT_QUEUE,
  .stack_size = 128 * 4 // * 3
};

osThreadId_t taskHandle_PushButton = NULL;
const osThreadAttr_t Task_PushButton_attributes = {
  .name       = "Task_PushButton",
  .priority   = (osPriority_t) PRIORITY_TASK_PUSH_BUTTON,
  .stack_size = 128 * 4
};

// global 'mutex' handles -----------------------------------------------------
osMutexId_t mutex_Display = NULL;
const osMutexAttr_t Mutex_Display_attributes = {
  .name      = "mutex_Display",
  .attr_bits = osMutexPrioInherit,
  .cb_mem    = NULL,
	.cb_size   = 0U
};

// global 'event group' handles -----------------------------------------------
osEventFlagsId_t eventGroupHandle_Measurement = NULL;  
osEventFlagsId_t eventGroupHandle_PushButton  = NULL;

// global 'message queue' handles ---------------------------------------------
osMessageQueueId_t queueHandle_ADC_Measurement     = NULL;    
osMessageQueueId_t queueHandle_Command_Measurement = NULL;
