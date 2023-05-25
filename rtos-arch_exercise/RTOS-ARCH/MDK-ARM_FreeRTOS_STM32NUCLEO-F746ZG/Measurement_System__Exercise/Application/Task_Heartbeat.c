#include "osObjects.h"

//-----------------------------------------------------------------------------
void Task_Heartbeat(void *argument)
{
	volatile uint32_t locLoopCounter = 0; // without volatile the for loop will be removed by the compiler 
		
  while(1)
	{	
		BSP_LED_Toggle(*((Led_TypeDef*)argument)); // toggle LED which is passed to the tasks
		
    for (locLoopCounter = 0; locLoopCounter < 0x001FFFFF; locLoopCounter++)
    {
    	// active delay 
    }
		
		//..	// passive delay
  }
}
