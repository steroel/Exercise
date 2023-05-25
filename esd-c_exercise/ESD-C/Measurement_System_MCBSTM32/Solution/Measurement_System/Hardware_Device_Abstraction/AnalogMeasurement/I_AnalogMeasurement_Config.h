#ifndef __I_AnalogMeasurement_Config_H
#define __I_AnalogMeasurement_Config_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "ICB_AnalogMeasurement.h"	


void I_AnalogMeasurement_open(void* const ptrAnalogMeasurement, const void* const ptrAnalogMeasurementConfig);
void I_AnalogMeasurement_close(void* const ptrAnalogMeasurement);

	
#ifdef __cplusplus
}
#endif


#endif // __AnalogMeasurement_Config_H
