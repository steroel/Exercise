#include "ApplicationManager.h"

void ApplicationManager_construct(ApplicationManager* const ptrApplicationManager, DeviceAbstractionManager* const ptrDeviceAbstractionManager)
{
	if ( (ptrApplicationManager!= nullptr) && (ptrDeviceAbstractionManager != nullptr) )
	{
		VoltageMeasurement_construct(//**,       "Voltage         ", "U", "V", 0.0, 0.01, 20,
									               //**);
		
		CurrentMeasurement_construct(//**,       "Current         ", "I", "mA", 0.0, 0.001, 20,
																 //**, 10000);
		
		ResistanceMeasurement_construct(//**, "Resistance      ", "R", "kOhm", 0.0, 0.01, 20,
																	  //**, 0.00033);
		
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
														
		//** analog measurement callback registration
		
	}
	else
	{
		// nothing to do
	}
}
