#ifndef __ApplicationManager_H
#define __ApplicationManager_H


#ifdef __cplusplus
extern "C" {
#endif

#include "VoltageMeasurement.h"
#include "CurrentMeasurement.h"
#include "ResistanceMeasurement.h"
#include "MeasurementController.h"

#include "DeviceAbstractionManager.h"

typedef	struct ApplicationManager
{
	//** ...
	MeasurementController objMeasurementController;
} ApplicationManager;

void ApplicationManager_construct(ApplicationManager* const ptrApplicationManager, DeviceAbstractionManager* const ptrDeviceAbstractionManager);		


#ifdef __cplusplus
}
#endif


#endif // __ApplicationManager_H
