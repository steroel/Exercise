#ifndef __UserInput_H
#define __UserInput_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

#include "I_UserInput.h"

typedef struct UserInput
{
	volatile userInputState_t mCurrentUserInput;
	void* mptrUserInputDevice;
} UserInput;

// callback interrupt service function
void UserInput_notifyInput(UserInput* const ptrUserInput, const uint32_t ptrInputValue);

#ifdef __cplusplus
}
#endif


#endif // __UserInput_H
