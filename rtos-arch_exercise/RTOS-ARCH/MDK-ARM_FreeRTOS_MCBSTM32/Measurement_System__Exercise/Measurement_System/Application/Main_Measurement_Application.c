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
	
//	if (...(...,								// task function name
//			            ...,							// debug name
//	                ...,	// stack size
//	                ...,											// task function parameter
//	                ...,				// priority
//	                ...)					// task handle
//    	!= pdPASS)
	{															// task creation failed
		printf("Fatal error main: Task_Init creation failed\n");
		while(1);										// application stops here
	}
//	else
//	{
//		...;			// start scheduling, will not return
//	}
	
	// will only get here if there was not enough heap space to create the idle task. 
	printf("Fatal error main: not enought heap space to create idle task\n");
	//while(1);
	
	return (0);	
}
