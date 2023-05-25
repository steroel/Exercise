#ifndef __I_LED_Config_H
#define __I_LED_Config_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
	
void I_LED_open(void* const ptrLED, const void* const ptrLED_Config);
void I_LED_close(void* const ptrLED);


#ifdef __cplusplus
}
#endif


#endif // __I_LED_Config
