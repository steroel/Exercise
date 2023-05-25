#include "osObjects.h"

// global 'resource' data -----------------------------------------------------
Led_TypeDef LED_Heartbeat_1 = LED_GREEN;
Led_TypeDef LED_Heartbeat_2 = LED_BLUE;

// global 'task' handles ------------------------------------------------------
TaskHandle_t taskHandle_Init = NULL;
TaskHandle_t taskHandle_Heartbeat_1 = NULL;
TaskHandle_t taskHandle_Heartbeat_2 = NULL;
TaskHandle_t taskHandle_Measurement_Signal = NULL;
TaskHandle_t taskHandle_Measurement_Queue = NULL;
TaskHandle_t taskHandle_PushButton = NULL;

// global 'mutex' handles -----------------------------------------------------
SemaphoreHandle_t mutex_Display = NULL;

// global 'event group' handles -----------------------------------------------
EventGroupHandle_t eventGroupHandle_Measurement = NULL;
EventGroupHandle_t eventGroupHandle_PushButton = NULL;

// global 'message queue' handles ---------------------------------------------
QueueHandle_t	queueHandle_ADC_Measurement = NULL;
QueueHandle_t	queueHandle_Command_Measurement = NULL;
