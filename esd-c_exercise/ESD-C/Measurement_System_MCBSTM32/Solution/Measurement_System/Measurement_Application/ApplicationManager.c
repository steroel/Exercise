#include "ApplicationManager.h"

void ApplicationManager_construct(ApplicationManager* const ptrApplicationManager, DeviceAbstractionManager* const ptrDeviceAbstractionManager)
{
	if ( (ptrApplicationManager!= nullptr) && (ptrDeviceAbstractionManager != nullptr) )
	{
		VoltageMeasurement_construct(&ptrApplicationManager->objVoltageMeasurement,       "Voltage         ", "U", "V", 0.0, 0.01, 20,
									 &ptrDeviceAbstractionManager->objAnalogMeasurement);
		
		CurrentMeasurement_construct(&ptrApplicationManager->objCurrentMeasurement,       "Current         ", "I", "mA", 0.0, 0.001, 20,
																 &ptrDeviceAbstractionManager->objAnalogMeasurement, 10000);
		
		ResistanceMeasurement_construct(&ptrApplicationManager->objResistanceMeasurement, "Resistance      ", "R", "kOhm", 0.0, 0.01, 20,
																	  &ptrDeviceAbstractionManager->objAnalogMeasurement, 0.00033);
		
		MeasurementController_construct(&ptrApplicationManager->objMeasurementController);
		MeasurementController_setMeasurement(&ptrApplicationManager->objMeasurementController,
																				 &ptrApplicationManager->objVoltageMeasurement, 0);
		MeasurementController_setMeasurement(&ptrApplicationManager->objMeasurementController,
																				 &ptrApplicationManager->objCurrentMeasurement, 1);
		MeasurementController_setMeasurement(&ptrApplicationManager->objMeasurementController,
																				 &ptrApplicationManager->objResistanceMeasurement, 2);
		MeasurementController_setUserInput(&ptrApplicationManager->objMeasurementController,
																			 &ptrDeviceAbstractionManager->objUserInput[0], 0);
		MeasurementController_setUserInput(&ptrApplicationManager->objMeasurementController,
																			 &ptrDeviceAbstractionManager->objUserInput[1], 1);
		MeasurementController_setUserIndication(&ptrApplicationManager->objMeasurementController,
																						&ptrDeviceAbstractionManager->objUserIndication[0], 0);
		MeasurementController_setUserIndication(&ptrApplicationManager->objMeasurementController,
																						&ptrDeviceAbstractionManager->objUserIndication[1], 1);
		MeasurementController_setUserIndication(&ptrApplicationManager->objMeasurementController,
																						&ptrDeviceAbstractionManager->objUserIndication[2], 2);
		MeasurementController_setUserOutput(&ptrApplicationManager->objMeasurementController,
																				&ptrDeviceAbstractionManager->objUserOutput);
														
		AnalogMeasurement_registerNewMeasureCallback(&ptrDeviceAbstractionManager->objAnalogMeasurement,
													 &ptrApplicationManager->objMeasurementController,
													 (void(*)(void* const))&MeasurementController_notifyNewMeasure);
	}
	else
	{
		// nothing to do
	}
}
