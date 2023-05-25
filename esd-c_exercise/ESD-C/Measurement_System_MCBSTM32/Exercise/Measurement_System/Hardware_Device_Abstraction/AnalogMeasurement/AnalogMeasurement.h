#ifndef __AnalogMeasurement_H
#define __AnalogMeasurement_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "ICB_AnalogMeasurement.h"	

typedef	struct AnalogMeasurement
{
	float32_t mAnalogVoltage;
	uint32_t	mRawValue;
	float32_t mReferenceVoltage;
	uint32_t	mResolutionBits;
	uint32_t	mPrecalculatedDivisor;
	void*     mptrCallbackObject;
	ICB_AnalogMeasurement_notifyNewMeasure_fptr mfptr_notifyNewMeasure;
} AnalogMeasurement;

// callback interrupt service function
void AnalogMeasurement_measure(AnalogMeasurement* const ptrAnalogMeasurement, uint32_t rawValue);

//** declaration of analog measurement callback registration function

	
#ifdef __cplusplus
}
#endif


#endif // __AnalogMeasurement_H
