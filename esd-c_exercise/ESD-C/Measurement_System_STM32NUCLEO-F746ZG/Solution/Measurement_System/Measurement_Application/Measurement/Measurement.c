#include "Measurement.h"
#include "Typedefs.h"
#include "I_AnalogMeasurement.h"


void Measurement_construct(Measurement* const ptrMeasurement,
													 char* measuringMode, char* measuringSymbol, char* measuringUnit,
													 float32_t measuringValue, float32_t accuracyValue, float32_t undefinedValue,
													 void* const ptrAnalogMeasurement)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mMeasuringMode   = measuringMode;
		ptrMeasurement->mMeasuringSymbol = measuringSymbol;
		ptrMeasurement->mMeasuringUnit   = measuringUnit;
		ptrMeasurement->mMeasuringValue  = measuringValue;
		ptrMeasurement->mCalculatedValue = 0;
		ptrMeasurement->mAccuracyValue   = accuracyValue;
		ptrMeasurement->mUndefinedValue  = undefinedValue;
		ptrMeasurement->mptrAnalogMeasurement = ptrAnalogMeasurement;
	}
	else
	{
		// nothing to do
	}
}

void Measurement_destruct(Measurement* const ptrMeasurement)
{
	// nothing to do
}

void Measurement_measure(Measurement* const ptrMeasurement)
{
	if (ptrMeasurement != nullptr)
	{
		I_AnalogMeasurement_getAnalogVoltage(ptrMeasurement->mptrAnalogMeasurement,
	                                       &ptrMeasurement->mMeasuringValue);
	}
	else
	{
		// nothing to do
	}
}

void Measurement_setCalculatedToUndefinedValue(Measurement* const ptrMeasurement)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mCalculatedValue = ptrMeasurement->mUndefinedValue;
	}
	else
	{
		// nothing to do
	}
}

void Measurement_setMeasuringMode(Measurement* const ptrMeasurement,  char* measuringMode)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mMeasuringMode = measuringMode;
	}
	else
	{
		// nothing to do
	}
}

void Measurement_setMeasuringSymbol(Measurement* const ptrMeasurement,  char* measuringSymbol)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mMeasuringSymbol = measuringSymbol;
	}
	else
	{
		// nothing to do
	}
}

void Measurement_setMeasuringUnit(Measurement* const ptrMeasurement,  char* measuringUnit)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mMeasuringUnit = measuringUnit;
	}
	else
	{
		// nothing to do
	}
}

void Measurement_setMeasuringValue(Measurement* const ptrMeasurement, float32_t measuringValue)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mMeasuringValue = measuringValue;
	}
	else
	{
		// nothing to do
	}
}

void Measurement_setCalculatedValue(Measurement* const ptrMeasurement, float32_t calculatedValue)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mCalculatedValue = calculatedValue;
	}
	else
	{
		// nothing to do
	}
}

void Measurement_setAccuracyValue(Measurement* const ptrMeasurement, float32_t accuracyValue)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mAccuracyValue = accuracyValue;
	}
	else
	{
		// nothing to do
	}
}

void Measurement_setUndefinedValue(Measurement* const ptrMeasurement, float32_t undefinedValue)
{
	if (ptrMeasurement != nullptr)
	{
		ptrMeasurement->mUndefinedValue = undefinedValue;
	}
	else
	{
		// nothing to do
	}	
}

char* Measurement_getMeasuringMode(const Measurement* const ptrMeasurement)
{
	return ptrMeasurement->mMeasuringMode;
}

char* Measurement_getMeasuringSymbol(const Measurement* const ptrMeasurement)
{
	return ptrMeasurement->mMeasuringSymbol;
}

char* Measurement_getMeasuringUnit(const Measurement* const ptrMeasurement)
{
	return ptrMeasurement->mMeasuringUnit;
}

float32_t Measurement_getMeasuringValue(const Measurement* const ptrMeasurement)
{
	return ptrMeasurement->mMeasuringValue;
}

float32_t Measurement_getCalculatedValue(const Measurement* const ptrMeasurement)
{
	return ptrMeasurement->mCalculatedValue;
}

float32_t Measurement_getAccuracyValue(const Measurement* const ptrMeasurement)
{
	return ptrMeasurement->mAccuracyValue;
}

float32_t Measurement_getUndefinedValue(const Measurement* const ptrMeasurement)
{
	return ptrMeasurement->mUndefinedValue;
}
