#define osObjectsPublic 
#include "osObjects.h"

extern int32_t Task_Init(void);
extern void initBoard(void);
extern void initMicrocontrollerPeripherals(void);

//-----------------------------------------------------------------------------
int32_t main (void)
{
	int32_t locStatusCode = -1;
	
	initMicrocontrollerPeripherals();		// microcontroller initialization
	initBoard();												// board peripheral initialization
	
	LCD_printStringXY(0, 0, "  RTOS Seminar  ");
	LCD_printStringXY(0, 1, "  MicroConsult  ");

	printf("RTOS Seminar\n");
	printf("MicroConsult\n");
	printf("Measurement System\n");
	
//  if (... != osOK)	// initialize operating system kernel
	{																	// failed
		printf("Fatal error main: kernal initialization failed\n");
		while(1);
	}
		
//	locStatusCode = ...;			// create all operating system objects
	
	if (locStatusCode == -1)					// failed
	{
		printf("Fatal error main: os object creation failed\n");
		while(1);
	}

//  if (... != osOK) 			// start scheduling thread execution
	{																	// failed
		printf("Fatal error main: kernel start failed\n");
		while(1);
	}
	return (0);
}
