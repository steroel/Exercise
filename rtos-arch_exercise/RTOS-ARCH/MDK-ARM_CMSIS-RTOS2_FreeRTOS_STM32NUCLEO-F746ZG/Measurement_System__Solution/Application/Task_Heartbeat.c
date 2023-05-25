#include "osObjects.h"

//-----------------------------------------------------------------------------
void Task_Heartbeat(void *argument)
{
	osStatus_t locOS_Status = osError;
//	volatile uint32_t locLoopCounter = 0; // without volatile the for loop will be removed by the compiler 
		
	while(1)
	{	
		BSP_LED_Toggle(*((Led_TypeDef*)argument)); // toggle LED which is passed to the tasks
		
//    for (locLoopCounter = 0; locLoopCounter < 0x001FFFFF; locLoopCounter++)
//    {
//    	// active delay 
//    }
		
		locOS_Status = osDelay(500);	// passive delay
		
		if (locOS_Status != osOK)
		{
			printf("\nTask_Heartbeat delay failed\n");
		}
		else
		{
			// nothing to do
		}
  }
}
