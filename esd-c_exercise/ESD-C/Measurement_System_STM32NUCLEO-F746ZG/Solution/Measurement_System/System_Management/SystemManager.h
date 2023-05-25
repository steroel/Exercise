#ifndef __SystemManager_H
#define __SystemManager_H


#ifdef __cplusplus
extern "C" {
#endif

#include "ApplicationManager.h"
#include "DeviceAbstractionManager.h"
#include "DriverManager.h"

typedef	struct SystemManager
{
	DriverManager            objDriverManager;
	DeviceAbstractionManager objDeviceAbstractionManager;
	ApplicationManager       objApplicationManager;
} SystemManager;

void SystemManager_construct(SystemManager* const ptrSystemManager);	
void SystemManager_run(SystemManager* const ptrSystemManager);	


#ifdef __cplusplus
}
#endif


#endif // __SystemManager_H
