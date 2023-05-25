#include "UserInput.h"
#include "I_UserInput.h"
#include "I_UserInput_Config.h"
#include "I_Button.h"


static void UserInput_getState(UserInput* const ptrUserInput, userInputState_t* const ptrUserInputReturn);
static void UserInput_open(UserInput* const ptrUserInput, const UserInput* const ptrUserInputConfig);
static void UserInput_close(UserInput* const ptrUserInput);

void I_UserInput_getState(const void* const ptrUserInput, userInputState_t* const ptrUserInputReturn)
{
	if((ptrUserInput != nullptr) && (ptrUserInputReturn != nullptr))
	{
		UserInput_getState((UserInput*) ptrUserInput, ptrUserInputReturn);
	}
	else
	{
		// nothing to do
	}
}

void I_UserInput_open(void* const ptrUserInput, const void* const ptrUserInputConfig)
{
	if((ptrUserInput != nullptr) && (ptrUserInputConfig != nullptr))
	{
		UserInput_open((UserInput*) ptrUserInput, (UserInput*) ptrUserInputConfig);
	}
	else
	{
		// nothing to do
	}
}

void I_UserInput_close(void* const ptrUserInput)
{
	if(ptrUserInput != nullptr)
	{
		UserInput_close((UserInput*)ptrUserInput);
	}
	else
	{
		// nothing to do
	}
}

static void UserInput_getState(UserInput* const ptrUserInput, userInputState_t* const ptrUserInputReturn)
{
	buttonState_t locButtonState = UndefinedButtonState;
		
	if((ptrUserInput != nullptr) && (ptrUserInputReturn != nullptr))
	{
		locButtonState = I_Button_getState(ptrUserInput->mptrUserInputDevice);
		
		switch(locButtonState)
		{		
			case ReleasedAfterShortPressedButtonState:
				ptrUserInput->mCurrentUserInput = ActiveA_UserInputState;
			break;
			
			case ReleasedAfterLongPressedButtonState:
				ptrUserInput->mCurrentUserInput = ActiveB_UserInputState;
			break;
			
			default:
				// no implementation
			break;
		}
	}
	else
	{
		// nothing to do
	}
	
	*ptrUserInputReturn = ptrUserInput->mCurrentUserInput;
	ptrUserInput->mCurrentUserInput = InactiveUserInputState;
}

static void UserInput_open(UserInput* const ptrUserInput, const UserInput* const ptrUserInputConfig)
{
	if((ptrUserInput != nullptr) && (ptrUserInputConfig != nullptr))
	{
		ptrUserInput->mptrUserInputDevice = ptrUserInputConfig->mptrUserInputDevice;
	}
	else
	{
		// nothing to do
	}
}

static void UserInput_close(UserInput* const ptrUserInput)
{
	if(ptrUserInput != nullptr)
	{
		ptrUserInput->mptrUserInputDevice = nullptr;
	}
	else
	{
		// nothing to do
	}
}

void UserInput_notifyInput(UserInput* const ptrUserInput, const uint32_t InputValue)
{
	switch((char)InputValue)
	{
		case 'A':
			ptrUserInput->mCurrentUserInput = ActiveA_UserInputState;
		break;
		case 'B':
			ptrUserInput->mCurrentUserInput = ActiveB_UserInputState;
		break;
		default:
			ptrUserInput->mCurrentUserInput = UndefinedUserInputState;
		break;
	}
}
