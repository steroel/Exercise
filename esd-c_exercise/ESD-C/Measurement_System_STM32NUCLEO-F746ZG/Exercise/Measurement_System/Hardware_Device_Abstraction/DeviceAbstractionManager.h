#ifndef __DeviceAbstractionManager_H
#define __DeviceAbstractionManager_H


#ifdef __cplusplus
extern "C" {
#endif

#include "AnalogMeasurement.h"
#include "UserIndication.h"
#include "UserInput.h"
	
#include "DriverManager.h"

#define USER_INDICATION_AMOUNT 2
#define USER_INPUT_AMOUNT      1
	
typedef	struct DeviceAbstractionManager
{
	UserInput         objUserInput[USER_INPUT_AMOUNT];
	UserIndication    objUserIndication[USER_INDICATION_AMOUNT];
	AnalogMeasurement objAnalogMeasurement;
} DeviceAbstractionManager;

void DeviceAbstractionManager_construct(DeviceAbstractionManager* const ptrDeviceAbstractionManager, DriverManager* const ptrDriverManager);	


#ifdef __cplusplus
}
#endif


#endif // __DeviceAbstractionManager_H
