#ifndef __I_LED_H
#define __I_LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
	
void I_LED_setOn(void* const ptrLED);
void I_LED_setOff(void* const ptrLED);
void I_LED_toggle(void* const ptrLED);

#ifdef __cplusplus
}
#endif


#endif // __I_LED_H
