#ifndef __VoltageMeasure_H
#define __VoltageMeasure_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "Measurement.h"

typedef	struct VoltageMeasurement
{
	Measurement mBaseMeasurement;
} VoltageMeasurement;

void VoltageMeasurement_construct(VoltageMeasurement* const ptrVoltageMeasurement,
																	char* measuringMode, char* measuringSymbol, char* measuringUnit,
																	float32_t measuringValue, float32_t accuracyValue, float32_t undefinedValue,
																	void* const ptrAnalogMeasurement);
void VoltageMeasurement_destruct(VoltageMeasurement* const ptrVoltageMeasurement);
void VoltageMeasurement_measure(VoltageMeasurement* const ptrVoltageMeasurement);

#ifdef __cplusplus
}
#endif


#endif // __VolatageMeasure_H
