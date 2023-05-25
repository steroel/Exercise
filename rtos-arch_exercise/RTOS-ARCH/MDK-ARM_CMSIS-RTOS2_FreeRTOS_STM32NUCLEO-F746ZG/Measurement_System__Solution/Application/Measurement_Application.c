#include "osObjects.h"

//-----------------------------------------------------------------------------
void executeMeasurementApplication(void)
{
	osStatus_t locOS_Status = osError; 
	
	locOS_Status = osKernelInitialize();
	
	//.. initialize kernel
	if (locOS_Status == osOK)
	{
		printf("\nOperating system kernel initialized successful ...");
	}
	else
	{
		printf("Fatal error main: Operating system kernel initialization failed\n");
		Error_Handler();
	}
	
	//.. create Task_Init
	taskHandle_Init = osThreadNew(Task_Init, NULL, &Task_Init_attributes);
	if (taskHandle_Init != NULL)
	{
		printf("\nTask_Init created successful ...");
	}
	else
	{
		printf("Fatal error main: Task_Init creation failed\n");
		Error_Handler();
	}
		
	printf("\nOperating system kernel starting ...");
	if (osKernelGetState() == osKernelReady)
	{
		//.. start kernel
		osKernelStart();
	}
	printf("Fatal error main: Operating system kernel start failed\n");
	Error_Handler();
}
