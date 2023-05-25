#ifndef __I_ADC_H
#define __I_ADC_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

void I_ADC_read(void* const ptrADC_Driver, uint32_t* const ptrDestination);
void I_ADC_start(void* const ptrADC_Driver);
void I_ADC_stop(void* const ptrADC_Driver);
	
#ifdef __cplusplus
}
#endif


#endif // __I_ADC_H
