#ifndef __Measurement_H
#define __Measurement_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
	
typedef	struct Measurement
{
	char*     mMeasuringMode;
	char*     mMeasuringSymbol;
	char*     mMeasuringUnit;
	float32_t mMeasuringValue;
	float32_t mCalculatedValue;
	float32_t mAccuracyValue;
	float32_t mUndefinedValue;
	void*			mptrAnalogMeasurement;
} Measurement;

void Measurement_construct(Measurement* const ptrMeasurement,
													 char* measuringMode, char* measuringSymbol, char* measuringUnit,
													 float32_t measuringValue, float32_t accuracyValue, float32_t undefinedValue,
													 void* const ptrAnalogMeasurement);
void Measurement_destruct(Measurement* const ptrMeasurement);
void Measurement_measure(Measurement* const ptrMeasurement);
void Measurement_setCalculatedToUndefinedValue(Measurement* const ptrMeasurement);						
void Measurement_setMeasuringMode(Measurement* const ptrMeasurement,  char* measuringMode);
void Measurement_setMeasuringSymbol(Measurement* const ptrMeasurement,  char* measuringSymbol);
void Measurement_setMeasuringUnit(Measurement* const ptrMeasurement,  char* measuringUnit);
void Measurement_setMeasuringValue(Measurement* const ptrMeasurement, float32_t measuringValue);
void Measurement_setCalculatedValue(Measurement* const ptrMeasurement, float32_t calculatedValue);			
void Measurement_setAccuracyValue(Measurement* const ptrMeasurement, float32_t accuracyValue);	
void Measurement_setUndefinedValue(Measurement* const ptrMeasurement, float32_t undefinedValue);														 
char* Measurement_getMeasuringMode(const Measurement* const ptrMeasurement);
char* Measurement_getMeasuringSymbol(const Measurement* const ptrMeasurement);
char* Measurement_getMeasuringUnit(const Measurement* const ptrMeasurement);
float32_t Measurement_getMeasuringValue(const Measurement* const ptrMeasurement);
float32_t Measurement_getCalculatedValue(const Measurement* const ptrMeasurement);
float32_t Measurement_getAccuracyValue(const Measurement* const ptrMeasurement);
float32_t Measurement_getUndefinedValue(const Measurement* const ptrMeasurement);														 


#ifdef __cplusplus
}
#endif


#endif // __Measurement_H
