#ifndef __I_UserInput_H
#define __I_UserInput_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

typedef enum
{
	InactiveUserInputState  = 0,
	ActiveA_UserInputState  = 1,
	ActiveB_UserInputState  = 2,
	UndefinedUserInputState = 3 
} userInputState_t;

void I_UserInput_getState(const void* const ptrUserInput, userInputState_t* const ptrUserInputReturn);

#ifdef __cplusplus
}
#endif


#endif // __I_UserInput_H
