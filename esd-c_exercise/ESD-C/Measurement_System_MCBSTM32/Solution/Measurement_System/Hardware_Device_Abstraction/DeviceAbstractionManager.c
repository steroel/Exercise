#include "DeviceAbstractionManager.h"
#include "I_UserInput_Config.h"
#include "I_UserOutput_Config.h"
#include "I_UserIndication_Config.h"
#include "I_AnalogMeasurement_Config.h"
#include "I_NVIC_Dispatcher_Config.h"


void DeviceAbstractionManager_construct(DeviceAbstractionManager* const ptrDeviceAbstractionManager, DriverManager* const ptrDriverManager)
{
	if ( (ptrDeviceAbstractionManager != nullptr) && (ptrDriverManager != nullptr) )
	{
		UserInput         locUserInput_Config;
		UserOutput        locUserOutput_Config;
		UserIndication    locUserIndication_Config;
		AnalogMeasurement locAnalogMeasurement_Config;
		uint32_t          locLoopIndex = 0; 
		
		locUserInput_Config.mptrUserInputDevice = &ptrDriverManager->objButtonTAMP;
		I_UserInput_open(&(ptrDeviceAbstractionManager->objUserInput[0]), &locUserInput_Config);
		
		locUserInput_Config.mptrUserInputDevice = &ptrDriverManager->objButtonWKUP;
		I_UserInput_open(&(ptrDeviceAbstractionManager->objUserInput[1]), &locUserInput_Config);
		
		locUserOutput_Config.mptrUserOutputDevice = &ptrDriverManager->objLCD_Text;
		locUserOutput_Config.mMaxX = ptrDriverManager->objLCD_Text.mColumns;
		locUserOutput_Config.mMaxY = ptrDriverManager->objLCD_Text.mLines;
		I_UserOutput_open(&ptrDeviceAbstractionManager->objUserOutput, &locUserOutput_Config);
		
		locAnalogMeasurement_Config.mAnalogVoltage    = 0.0;
		locAnalogMeasurement_Config.mRawValue         = 0;
		locAnalogMeasurement_Config.mReferenceVoltage = 3.3;
		locAnalogMeasurement_Config.mResolutionBits   = 12;
		locAnalogMeasurement_Config.mptrCallbackObject = nullptr;
		I_AnalogMeasurement_open(&ptrDeviceAbstractionManager->objAnalogMeasurement, &locAnalogMeasurement_Config);
		
		for (locLoopIndex = 0; locLoopIndex < USER_INDICATION_AMOUNT; ++locLoopIndex)
		{
			locUserIndication_Config.mptrUserIndicationDevice = &ptrDriverManager->objLED[locLoopIndex];
			I_UserIndication_open(&(ptrDeviceAbstractionManager->objUserIndication[locLoopIndex]), &locUserIndication_Config);
		}
		
		I_NVIC_Dispatcher_registerInterrupt(&(ptrDeviceAbstractionManager->objAnalogMeasurement),
											(void(*)(void* const, void*))&AnalogMeasurement_measure, ADC1_2_InterruptVectorNumber);
	}
	else
	{
		// nothing to do
	}
}
