#include "osObjects.h"

//-----------------------------------------------------------------------------
void Task_Heartbeat(void const *argument)
{
	uint32_t locLED = (uint32_t)argument;		// avoides compiler warning
	uint32_t locLoopCounter = 0;
		
  while(1)
	{
		LED_toggle((Led_TypeDef)locLED);			// toggle LED which is passed to the tasks	
    for (locLoopCounter = 0; locLoopCounter < 0x001FFFFF; locLoopCounter++)
    {
    	// active delay 
    }
//		...;	// passive delay
  }
}
