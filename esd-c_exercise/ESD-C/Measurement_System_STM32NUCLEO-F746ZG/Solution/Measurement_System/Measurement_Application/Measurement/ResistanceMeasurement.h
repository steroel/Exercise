#ifndef __ResistanceMeasurement_H
#define __ResistanceMeasurement_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "Measurement.h"
	
typedef	struct ResistanceMeasurement
{
	Measurement mBaseMeasurement;
	float32_t   mMeasureResistance;
} ResistanceMeasurement;

void ResistanceMeasurement_construct(ResistanceMeasurement* const ptrResistanceMeasurement,
																	   char* measuringMode, char* measuringSymbol, char* measuringUnit,
																	   float32_t measuringValue, float32_t accuracyValue, float32_t undefinedValue,
																	   void*	ptrAnalogMeasurement, float32_t measureResistance);
void ResistanceMeasurement_destruct(ResistanceMeasurement* const ptrResistanceMeasurement);
void ResistanceMeasurement_measure(ResistanceMeasurement* const ptrResistanceMeasurement);

#ifdef __cplusplus
}
#endif


#endif // __ResistanceMeasurement_H
