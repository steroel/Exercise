#ifndef __I_Button_H
#define __I_Button_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "I_Button_Types.h"

buttonState_t I_Button_getState(void* const ptrButton);
buttonState_t I_Button_getPreviousState(void* const ptrButton);

#ifdef __cplusplus
}
#endif


#endif // __I_Button_H
