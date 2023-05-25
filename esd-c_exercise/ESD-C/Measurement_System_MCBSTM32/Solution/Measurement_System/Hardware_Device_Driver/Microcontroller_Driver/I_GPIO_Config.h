#ifndef __I_GPIO_Config_H
#define __I_GPIO_Config_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
	
void I_GPIO_open(void* const ptrGPIO_Driver, const void* const ptrGPIO_Config);
void I_GPIO_close(void* const ptrGPIO_Driver);

#ifdef __cplusplus
}
#endif


#endif // _I_GPIO_Config_H
