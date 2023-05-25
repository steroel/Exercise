#include "ResistanceMeasurement.h"

static void ResistanceMeasurement_calculate(ResistanceMeasurement* const ptrResistanceMeasurement);

void ResistanceMeasurement_construct(ResistanceMeasurement* const ptrResistanceMeasurement,
																	   char* measuringMode, char* measuringSymbol, char* measuringUnit,
																	   float32_t measuringValue, float32_t accuracyValue, float32_t undefinedValue,
																	   void*	ptrAnalogMeasurement, float32_t measureResistance)
{
	if (ptrResistanceMeasurement != nullptr)
	{
		//** add construct() call of base class
		//** init additional attribute
	}
	else
	{
		// nothing to do
	}
}
void ResistanceMeasurement_destruct(ResistanceMeasurement* const ptrResistanceMeasurement)
{
	// nothing to do
}
void ResistanceMeasurement_measure(ResistanceMeasurement* const ptrResistanceMeasurement)
{
	if (ptrResistanceMeasurement != nullptr)
	{
		//** call measure() and calculate()
	}
	else
	{
		// nothing to do
	}
}

static void ResistanceMeasurement_calculate(ResistanceMeasurement* const ptrResistanceMeasurement)
{
	if (ptrResistanceMeasurement != nullptr)
	{
		float32_t locCalculatedValue = Measurement_getMeasuringValue(&ptrResistanceMeasurement->mBaseMeasurement);
		locCalculatedValue = locCalculatedValue / ptrResistanceMeasurement->mMeasureResistance / 1000;	// kOhm
		Measurement_setCalculatedValue(&ptrResistanceMeasurement->mBaseMeasurement, locCalculatedValue);
	}
	else
	{
		// nothing to do
	}
}
