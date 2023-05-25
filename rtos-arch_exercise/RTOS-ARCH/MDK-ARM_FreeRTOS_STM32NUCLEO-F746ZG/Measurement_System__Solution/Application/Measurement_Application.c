#include "osObjects.h"

//-----------------------------------------------------------------------------
void executeMeasurementApplication(void)
{
	if (xTaskCreate(Task_Init,								// task function name
			            "Task_Init",							// debug name
	                configMINIMAL_STACK_SIZE,	// stack size
	                NULL,											// task function parameter
	                PRIORITY_TASK_INIT,				// priority
	                &taskHandle_Init)					// task handle
    	!= pdPASS)
	{															// task creation failed
		printf("Fatal error main: Task_Init creation failed\n");
		Error_Handler();
	}
	else
	{
		printf("\nTask_Init created successful ...");
		printf("\nOperating system scheduler starting ...");
		vTaskStartScheduler();			// start scheduling, will not return
	}
	
	// will only get here if there was not enough heap space to create the idle task. 
	printf("\nFatal error: not enought heap space to create idle task\n");
	Error_Handler();
}
