#include "VoltageMeasurement.h"

static void VoltageMeasurement_calculate(VoltageMeasurement* const ptrVoltageMeasurement);

void VoltageMeasurement_construct(VoltageMeasurement* ptrVoltageMeasurement,
																	char* measuringMode, char* measuringSymbol, char* measuringUnit,
																	float32_t measuringValue, float32_t accuracyValue, float32_t undefinedValue,
																	void* const ptrAnalogMeasurement)
{
	if (ptrVoltageMeasurement != nullptr)
	{
		Measurement_construct(&(ptrVoltageMeasurement->mBaseMeasurement),
													measuringMode, measuringSymbol, measuringUnit,
													measuringValue, accuracyValue, undefinedValue,
													ptrAnalogMeasurement);
	}
	else
	{
		// nothing to do
	}
}
void VoltageMeasurement_destruct(VoltageMeasurement* const ptrVoltageMeasurement)
{
	// nothing to do
}
void VoltageMeasurement_measure(VoltageMeasurement* const ptrVoltageMeasurement)
{
	if (ptrVoltageMeasurement != nullptr)
	{
		Measurement_measure(&ptrVoltageMeasurement->mBaseMeasurement);
		VoltageMeasurement_calculate(ptrVoltageMeasurement);
	}
	else
	{
		// nothing to do
	}
}

static void VoltageMeasurement_calculate(VoltageMeasurement* const ptrVoltageMeasurement)
{
	if (ptrVoltageMeasurement != nullptr)
	{
		float32_t locCalculatedValue = Measurement_getMeasuringValue(&ptrVoltageMeasurement->mBaseMeasurement);
		// nothing to calculate
		Measurement_setCalculatedValue(&ptrVoltageMeasurement->mBaseMeasurement, locCalculatedValue);
	}
	else
	{
		// nothing to do
	}
}
