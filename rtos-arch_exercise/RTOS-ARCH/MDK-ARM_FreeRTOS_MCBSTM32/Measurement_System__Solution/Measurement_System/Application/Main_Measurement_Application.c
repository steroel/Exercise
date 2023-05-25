#define osObjectsPublic 
#include "osObjects.h"

extern void initBoard(void);
extern void initMicrocontrollerPeripherals(void);

//-----------------------------------------------------------------------------
int32_t main (void)
{
	initMicrocontrollerPeripherals();		// microcontroller initialization
	initBoard();												// board peripheral initialization
	
	LCD_printStringXY(0, 0, "  RTOS Seminar  ");
	LCD_printStringXY(0, 1, "  MicroConsult  ");

	printf("RTOS Seminar\n");
	printf("MicroConsult\n");
	printf("Measurement System\n");
		
	if (xTaskCreate(Task_Init,								// task function name
			            "Task_Init",							// debug name
	                configMINIMAL_STACK_SIZE,	// stack size
	                NULL,											// task function parameter
	                PRIORITY_TASK_INIT,				// priority
	                &taskHandle_Init)					// task handle
    	!= pdPASS)
	{															// task creation failed
		printf("Fatal error main: Task_Init creation failed\n");
		while(1);										// application stops here
	}
	
// Heartbeat task in main() works
//	if (xTaskCreate(Task_Heartbeat,								// task function name
//			            "Task_Heartbeat",							// debug name
//	                configMINIMAL_STACK_SIZE,	// stack size
//	                (void*)LED1,											// task function parameter
//	                PRIORITY_TASK_HEARTBEAT_1,				// priority
//	                &taskHandle_Heartbeat_1)					// task handle
//    	!= pdPASS)
//	{															// task creation failed
//		printf("Fatal error main: Task_Heartbeat creation failed\n");
//		while(1);										// application stops here
//	}
	
	else
	{
		vTaskStartScheduler();			// start scheduling, will not return
	}
	
	// will only get here if there was not enough heap space to create the idle task. 
	printf("Fatal error main: not enought heap space to create idle task\n");
	//while(1);
	
	return (0);	
}
