#include "CurrentMeasurement.h"

static void CurrentMeasurement_calculate(CurrentMeasurement* const ptrCurrentMeasurement);

void CurrentMeasurement_construct(CurrentMeasurement* const ptrCurrentMeasurement,
																	char* measuringMode, char* measuringSymbol, char* measuringUnit,
																	float32_t measuringValue, float32_t accuracyValue, float32_t undefinedValue,
																	void*	ptrAnalogMeasurement, float32_t measureCurrent)
{
	if (ptrCurrentMeasurement != nullptr)
	{
		//** add construct() call of base class
		//** iinit addtional attribute
	}
	else
	{
		// nothing to do
	}
}

void CurrentMeasurement_destruct(CurrentMeasurement* const ptrCurrentMeasurement)
{
	// nothing to do
}
void CurrentMeasurement_measure(CurrentMeasurement* const ptrCurrentMeasurement)
{
	if (ptrCurrentMeasurement != nullptr)
	{
		//** call measure() and calculate()
	}
	else
	{
		// nothing to do
	}
}

static void CurrentMeasurement_calculate(CurrentMeasurement* const ptrCurrentMeasurement)
{
	if (ptrCurrentMeasurement != nullptr)
	{
		float32_t locCalculatedValue = Measurement_getMeasuringValue(&ptrCurrentMeasurement->mBaseMeasurement);
		locCalculatedValue = locCalculatedValue / ptrCurrentMeasurement->mMeasureCurrent * 1000;		// mA
		Measurement_setCalculatedValue(&ptrCurrentMeasurement->mBaseMeasurement, locCalculatedValue);
	}
	else
	{
		// nothing to do
	}
}
