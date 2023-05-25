#ifndef __I_ADC_Config_H
#define __I_ADC_Config_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

void I_ADC_open(void* const ptrADC_Driver, const void* const ptrADC_Config);
void I_ADC_close(void* const ptrADC_Driver);

#ifdef __cplusplus
}
#endif


#endif // __I_ADC_Config_H
