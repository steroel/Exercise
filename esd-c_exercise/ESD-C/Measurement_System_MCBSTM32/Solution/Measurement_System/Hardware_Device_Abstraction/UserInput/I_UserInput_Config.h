#ifndef __I_UserInput_Config_H
#define __I_UserInput_Config_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

void I_UserInput_open(void* const ptrUserInput, const void* const ptrUserInputConfig);
void I_UserInput_close(void* const ptrUserInput);


#ifdef __cplusplus
}
#endif


#endif // __I_UserInput_Config_H
