#include "SystemManager.h"
#include "Typedefs.h"

void SystemManager_construct(SystemManager* const ptrSystemManager)
{
	if (ptrSystemManager != nullptr)
	{
		DriverManager_construct(&ptrSystemManager->objDriverManager);
		DeviceAbstractionManager_construct(&ptrSystemManager->objDeviceAbstractionManager, &ptrSystemManager->objDriverManager);
		ApplicationManager_construct(&ptrSystemManager->objApplicationManager, &ptrSystemManager->objDeviceAbstractionManager);
	}
	else
	{
		// nothing to do
	}
}

void SystemManager_run(SystemManager* const ptrSystemManager)
{
	if (ptrSystemManager != nullptr)
	{
		MeasurementController_execute(&ptrSystemManager->objApplicationManager.objMeasurementController);
	}
	else
	{
		// nothing to do
	}
}
