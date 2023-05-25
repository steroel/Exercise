#ifndef __CurrentMeasure_H
#define __CurrentMeasure_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "Measurement.h"
	
//** add attributes

void CurrentMeasurement_construct(CurrentMeasurement* const ptrCurrentMeasurement,
																	char* measuringMode, char* measuringSymbol, char* measuringUnit,
																	float32_t measuringValue, float32_t accuracyValue, float32_t undefinedValue,
																	void* ptrAnalogMeasurement, float32_t measureCurrent);
void CurrentMeasurement_destruct(CurrentMeasurement* const ptrCurrentMeasurement);
void CurrentMeasurement_measure(CurrentMeasurement* const ptrCurrentMeasurement);

#ifdef __cplusplus
}
#endif


#endif // __CurrentMeasure__H
