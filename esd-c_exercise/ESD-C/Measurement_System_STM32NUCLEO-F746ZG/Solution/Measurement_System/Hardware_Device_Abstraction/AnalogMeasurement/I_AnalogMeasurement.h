#ifndef __I_AnalogMeasurement_H
#define __I_AnalogMeasurement_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

void I_AnalogMeasurement_getAnalogVoltage(void* const ptrAnalogMeasurement, float32_t* const ptrAnalogVoltage);
void I_AnalogMeasurement_getRawValue(void* const ptrAnalogMeasurement, uint32_t* const ptrRawValue);	

#ifdef __cplusplus
}
#endif


#endif // __I_AnalogMeasurement_H
