#include "osObjects.h"

extern TIM_HandleTypeDef htim1;
extern ADC_HandleTypeDef hadc1;

//-----------------------------------------------------------------------------
static void showMeasurementVoltage(const uint32_t parADC_Value)
{
	const float locADC_ReferenceVoltage = 3.3;
	const uint32_t locADC_BitResolution = 12;
	const uint32_t locADC_MaxValue      = pow(2, locADC_BitResolution)-1;
	float locVoltage                    = 0.0;	// calculated voltage value
	
	locVoltage = locADC_ReferenceVoltage * parADC_Value / locADC_MaxValue; // calculate voltage 
	printf("\nMeasurement Voltage   : U = %.2f V", locVoltage);						 // print mode and voltage
}

//-----------------------------------------------------------------------------
static void showMeasurementCurrent(const uint32_t parADC_Value)
{
	const float locADC_ReferenceVoltage = 3.3;
	const uint32_t locADC_BitResolution = 12;
	const uint32_t locADC_MaxValue      = pow(2, locADC_BitResolution)-1;

	const float locMaxResistance        = 10000;
	float locCurrent                    = 0.0;	// calculated current value
	
	locCurrent = locADC_ReferenceVoltage * parADC_Value / locADC_MaxValue / locMaxResistance * 1000; // calculate current
	printf("\nMeasurement Current   : I = %.3f mA", locCurrent);							                       // print mode and current
}

//-----------------------------------------------------------------------------
static void showMeasurementResistance(const uint32_t parADC_Value)
{
	const float locADC_ReferenceVoltage = 3.3;
	const uint32_t locADC_BitResolution = 12;
	const uint32_t locADC_MaxValue      = pow(2, locADC_BitResolution)-1;
	const float locMaxCurrent           = 0.00033;
	float locResistance                 = 0.0;	// claculated resistance value
	
	locResistance = locADC_ReferenceVoltage * parADC_Value / locADC_MaxValue / locMaxCurrent / 1000; // calculate resistance
	printf("\nMeasurement Resistance: R = %.2f kOhm", locResistance);							                   // print mode and resistance
}

//-----------------------------------------------------------------------------
static void displayADC_Value(const uint32_t parADC_Value)
{
	char locCharBuffer[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // char buffer for interger/float to string convertion
	
	sprintf(locCharBuffer, "ADC = 0x%04X", parADC_Value); 		  // preparet output string
//	BSP_LCD_printStringXY(0, 0, locCharBuffer);								// show output string

	if (osMutexAcquire(mutex_Display, osWaitForever) == osOK)	  // wait for display mutex
	{																														// display access
		BSP_LCD_printStringXY(0, 0, locCharBuffer);								// show output string
		if (osMutexRelease(mutex_Display) != osOK)							  // release display mutex
		{
			printf("\nError Task_Measurement_Queue: display mutex unlock failed\n");
		}
		else // mutex release successful
		{
			// nothing to do
		}
	}
	else
	{
		printf("\nError Task_Measurement_Queue: display mutex lock failed\n");
	}
}

//-----------------------------------------------------------------------------
void Task_Measurement_Queue(void *argument)
{
	uint32_t locADC_Value = 0; // received ADC value, triggered by ADC isr
			
	enum Modes_t
	{
		MeasurementVoltage,
		MeasurementCurrent,
		MeasurementResistance,
		MaxModeCount
	} locMode = MeasurementVoltage;
	
	ADC_Message_t locADC_Message        = {0, 0};	// ADC message receive buffer
	Command_Message_t locCommandMessage = {0, 0};	// command message receive buffer
		
	HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_1);		// enable TIMER1, CH1 to trigger ADC1
	HAL_ADC_Start_IT(&hadc1);										// enable ADC1 with interrupt
	
  while(1)
  {
	  // wait for ADC message
		if (osMessageQueueGet(queueHandle_ADC_Measurement, &locADC_Message, NULL, 500) == osOK)	
		{																																					// ADC message received
			locADC_Value = locADC_Message.ADC_Value;																// read ADC value from message
							
			// read command message without waiting
			if (osMessageQueueGet(queueHandle_Command_Measurement, &locCommandMessage, NULL, 0) == osOK)
			{ 																																			// command message received action
				//printf("message id = %i  ", locCommandMessage.ID );									// only for debug purpose
				//printf("message command id = %i\n", locCommandMessage.Command);			// only for debug purpose
					
				if ((locCommandMessage.ID == 1) && (locCommandMessage.Command == 22))	// check for the right messages
				{
					if(locMode < MaxModeCount - 1)		// check for the final output mode
					{
						locMode = locMode + 1;		      // change output mode to the next one
					}
					else
					{
						locMode = MeasurementVoltage;	  // first output mode is set
					}
				}
				else	// invalide message receided
				{
					printf("\nError Task_Measurement_Queue: Command message invalid\n");
				}					
			}
			else  // no message received
			{
				// no output mode change - for this application, this is no error case
				//printf("Error Task_Measurement_Queue: command message receive failed\n"); // only for debug purpose
			}
				
			switch(locMode)	// state machine for different output modes
			{
				case MeasurementVoltage:
					showMeasurementVoltage(locADC_Value); // print voltage measurement to standard output
				break;
					
				case MeasurementCurrent:
					showMeasurementCurrent(locADC_Value); // print current measurement to standard output
				break;
					
				case MeasurementResistance:
					showMeasurementResistance(locADC_Value); // print resistance measurement to standard output
				break;
					
				default:
					printf("\nError Task_Measurement: measurement mode selection failed\n");
				break;
			}
			
			displayADC_Value(locADC_Value); // print ADC value to display
		}
		else
		{
			printf("\nError Task_Measurement_Queue: ADC message receive failed\n");
		}
  }
}
