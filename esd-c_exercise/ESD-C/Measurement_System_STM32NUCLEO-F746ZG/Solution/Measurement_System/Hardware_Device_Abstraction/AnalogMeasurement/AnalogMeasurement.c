#include <math.h>

#include "AnalogMeasurement.h"
#include "I_AnalogMeasurement.h"
#include "I_AnalogMeasurement_Config.h"

static void AnalogMeasurement_open(AnalogMeasurement* const ptrAnalogMeasurement, const AnalogMeasurement* const ptrAnalogMeasurementConfig);
static void AnalogMeasurement_close(AnalogMeasurement* const ptrAnalogMeasurement);
static void AnalogMeasurement_getAnalogVoltage(AnalogMeasurement* const ptrAnalogMeasurement, float32_t* const ptrAnalogVoltage);
static void AnalogMeasurement_getRawValue(AnalogMeasurement* const ptrAnalogMeasurement, uint32_t* const ptrRawValue);	

void I_AnalogMeasurement_open(void* const ptrAnalogMeasurement, const void* const ptrAnalogMeasurementConfig)
{
	if ( (ptrAnalogMeasurement != nullptr) &&  (ptrAnalogMeasurementConfig != nullptr) )
	{
		AnalogMeasurement_open((AnalogMeasurement*)ptrAnalogMeasurement, (AnalogMeasurement*)ptrAnalogMeasurementConfig);
	}
	else
	{
		// nothing to do
	}
}

void I_AnalogMeasurement_close(void* const ptrAnalogMeasurement)
{
	if (ptrAnalogMeasurement != nullptr)
	{
		AnalogMeasurement_close((AnalogMeasurement*)ptrAnalogMeasurement);
	}
	else
	{
		// nothing to do
	}
}

void I_AnalogMeasurement_getAnalogVoltage(void* const ptrAnalogMeasurement, float32_t* const ptrAnalogVoltage)
{
	if (ptrAnalogMeasurement != nullptr)
	{
		AnalogMeasurement_getAnalogVoltage((AnalogMeasurement*) ptrAnalogMeasurement, ptrAnalogVoltage);
	}
	else
	{
		// nothing to do
	}
}

void I_AnalogMeasurement_getRawValue(void* const ptrAnalogMeasurement, uint32_t* const ptrRawValue)
{
	if (ptrAnalogMeasurement != nullptr)
	{
		AnalogMeasurement_getRawValue((AnalogMeasurement*) ptrAnalogMeasurement, ptrRawValue);
	}
	else
	{
		// nothing to do
	}
}

// interrupt callback
void AnalogMeasurement_measure(AnalogMeasurement* const ptrAnalogMeasurement, uint32_t rawValue)
{
	if (ptrAnalogMeasurement != nullptr)
	{
		ptrAnalogMeasurement->mRawValue = rawValue;
		ptrAnalogMeasurement->mAnalogVoltage = ptrAnalogMeasurement->mReferenceVoltage * rawValue / ptrAnalogMeasurement->mPrecalculatedDivisor;
		
		if (ptrAnalogMeasurement->mfptr_notifyNewMeasure != nullptr)
		{
			ptrAnalogMeasurement->mfptr_notifyNewMeasure(ptrAnalogMeasurement->mptrCallbackObject);
		}
	}
	else
	{
		// nothing to do
	}
}

void AnalogMeasurement_registerNewMeasureCallback(AnalogMeasurement* const ptrAnalogMeasurement, void* const ptrCallbackObject, ICB_AnalogMeasurement_notifyNewMeasure_fptr fptrCallbackFunction)
{
	if (ptrAnalogMeasurement != nullptr)
	{
		ptrAnalogMeasurement->mptrCallbackObject = ptrCallbackObject;
		ptrAnalogMeasurement->mfptr_notifyNewMeasure = fptrCallbackFunction;
	}
	else
	{
		// nothing to do
	}
}

static void AnalogMeasurement_open(AnalogMeasurement* const ptrAnalogMeasurement, const AnalogMeasurement* const ptrAnalogMeasurementConfig)
{
	if ( (ptrAnalogMeasurement != nullptr) &&  (ptrAnalogMeasurementConfig != nullptr) )
	{
		ptrAnalogMeasurement->mAnalogVoltage    = ptrAnalogMeasurementConfig->mAnalogVoltage;
		ptrAnalogMeasurement->mRawValue         = ptrAnalogMeasurementConfig->mRawValue;
		ptrAnalogMeasurement->mReferenceVoltage = ptrAnalogMeasurementConfig->mReferenceVoltage;
		ptrAnalogMeasurement->mResolutionBits   = ptrAnalogMeasurementConfig->mResolutionBits;
		ptrAnalogMeasurement->mPrecalculatedDivisor = pow(2, ptrAnalogMeasurement->mResolutionBits) - 1;
	}
	else
	{
		// nothing to do
	}
}

static void AnalogMeasurement_close(AnalogMeasurement* const ptrAnalogMeasurement)
{
	// nothing to do
}

static void AnalogMeasurement_getAnalogVoltage(AnalogMeasurement* const ptrAnalogMeasurement, float32_t* const ptrAnalogVoltage)
{
	if (ptrAnalogMeasurement != nullptr)
	{
		*ptrAnalogVoltage = ptrAnalogMeasurement->mAnalogVoltage;
	}
	else
	{
		// nothing to do
	}
}

static void AnalogMeasurement_getRawValue(AnalogMeasurement* const ptrAnalogMeasurement, uint32_t* const ptrRawValue)
{
	if (ptrAnalogMeasurement != nullptr)
	{
		*ptrRawValue = ptrAnalogMeasurement->mRawValue;
	}
	else
	{
		// nothing to do
	}
}
