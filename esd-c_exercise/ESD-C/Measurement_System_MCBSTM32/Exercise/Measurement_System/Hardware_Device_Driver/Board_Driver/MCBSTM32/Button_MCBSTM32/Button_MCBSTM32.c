#include "Button_MCBSTM32.h"
#include "I_Button_Config.h"
#include "I_Button.h"
#include "I_GPIO.h"

static void Button_MCBSTM32_open(Button_MCBSTM32* const ptrButton_MCBSTM32, const Button_MCBSTM32* const prtButton_MCBSTM32_Config);
static void Button_MCBSTM32_close(Button_MCBSTM32* const ptrButton_MCBSTM32);
static buttonState_t Button_MCBSTM32_getState(Button_MCBSTM32* const ptrButton_MCBSTM32);
static void Button_MCBSTM32_debounce(const Button_MCBSTM32* const ptrButton_MCBSTM32);
static buttonState_t Button_MCBSTM32_getPreviousState(Button_MCBSTM32* const ptrButton_MCBSTM32);

void I_Button_open(void* const ptrButton, const void* const prtButton_Config)
{
	if ( (ptrButton != nullptr) && (prtButton_Config != nullptr) )
	{
		Button_MCBSTM32_open((Button_MCBSTM32*) ptrButton, (Button_MCBSTM32*) prtButton_Config);
	}
	else
	{
		// nothing to do
	}
}

void I_Button_close(void* const ptrButton)
{
	if (ptrButton != nullptr)
	{
		Button_MCBSTM32_close((Button_MCBSTM32*) ptrButton);
	}
	else
	{
		// nothing to do
	}
}

buttonState_t I_Button_getState(void* const ptrButton)
{
	buttonState_t locButtonState = UndefinedButtonState;
	
	if (ptrButton != nullptr)
	{
		locButtonState = Button_MCBSTM32_getState((Button_MCBSTM32*) ptrButton);
	}
	else
	{
		// nothing to do
	}
	
	return locButtonState;
}

buttonState_t I_Button_getPreviousState(void* const ptrButton)
{
	buttonState_t locButtonState = UndefinedButtonState;
	
	if (ptrButton != nullptr)
	{
		locButtonState = Button_MCBSTM32_getPreviousState((Button_MCBSTM32*) ptrButton);
	}
	else
	{
		// nothing to do
	}
	
	return locButtonState;
}

static void Button_MCBSTM32_open(Button_MCBSTM32* const ptrButton_MCBSTM32, const Button_MCBSTM32* const prtButton_MCBSTM32_Config)
{
	if (ptrButton_MCBSTM32 != nullptr)
	{
		ptrButton_MCBSTM32->mptrInPort     = prtButton_MCBSTM32_Config->mptrInPort;
		ptrButton_MCBSTM32->mActivity      = prtButton_MCBSTM32_Config->mActivity;
		ptrButton_MCBSTM32->mPreviousState = prtButton_MCBSTM32_Config->mPreviousState;
		ptrButton_MCBSTM32->mDebounceValue = prtButton_MCBSTM32_Config->mDebounceValue;
	}
	else
	{
		// nothing to do
	}
}

static void Button_MCBSTM32_close(Button_MCBSTM32* const ptrButton_MCBSTM32)
{
	if (ptrButton_MCBSTM32 != nullptr)
	{
		ptrButton_MCBSTM32->mptrInPort = nullptr;
	}
	else
	{
		// nothing to do
	}
}

static buttonState_t Button_MCBSTM32_getState(Button_MCBSTM32* const ptrButton_MCBSTM32)
{
	port_t locPortValue = 2;
	buttonState_t locButtonState = UndefinedButtonState;
	
	if (ptrButton_MCBSTM32 != nullptr)
	{
		I_GPIO_read(ptrButton_MCBSTM32->mptrInPort, &locPortValue);
		
    if ( (ptrButton_MCBSTM32->mPreviousState == UndefinedButtonState) && (
			   ( (ptrButton_MCBSTM32->mActivity == HighActiveButton) && (locPortValue == 1) ) ||
			   ( (ptrButton_MCBSTM32->mActivity == LowActiveButton)  && (locPortValue == 0) ) ) )
		{
			locButtonState = PressedButtonState;
		}
    else if ( (ptrButton_MCBSTM32->mPreviousState == UndefinedButtonState) && (
		          ( (ptrButton_MCBSTM32->mActivity == HighActiveButton) && (locPortValue == 0) ) ||
			        ( (ptrButton_MCBSTM32->mActivity == LowActiveButton)  && (locPortValue == 1) ) ) )
		{
			locButtonState = ReleasedButtonState;
		}		
		else if ( (ptrButton_MCBSTM32->mPreviousState == ReleasedButtonState) && (
			   ( (ptrButton_MCBSTM32->mActivity == HighActiveButton) && (locPortValue == 1) ) ||
			   ( (ptrButton_MCBSTM32->mActivity == LowActiveButton)  && (locPortValue == 0) ) ) )
		{
			locButtonState = PressingButtonState;
		}
		else if ( ( (ptrButton_MCBSTM32->mPreviousState == PressingButtonState) ||
        			  (ptrButton_MCBSTM32->mPreviousState == PressedButtonState) ) && (
							( (ptrButton_MCBSTM32->mActivity == HighActiveButton) && (locPortValue == 1) ) ||
			        ( (ptrButton_MCBSTM32->mActivity == LowActiveButton)  && (locPortValue == 0) ) ) )
		{
			locButtonState = PressedButtonState;
		}
		else if ( (ptrButton_MCBSTM32->mPreviousState == PressedButtonState) && (
							( (ptrButton_MCBSTM32->mActivity == HighActiveButton) && (locPortValue == 0) ) ||
			        ( (ptrButton_MCBSTM32->mActivity == LowActiveButton)  && (locPortValue == 1) ) ) )
		{
			locButtonState = ReleasingButtonState;
		}
		else if ( ( (ptrButton_MCBSTM32->mPreviousState == ReleasingButtonState) ||
        			  (ptrButton_MCBSTM32->mPreviousState == ReleasedButtonState) ) && (
							( (ptrButton_MCBSTM32->mActivity == HighActiveButton) && (locPortValue == 0) ) ||
			        ( (ptrButton_MCBSTM32->mActivity == LowActiveButton)  && (locPortValue == 1) ) ) )
		{
			locButtonState = ReleasedButtonState;
		}	
		else
		{
			// state undefined
		}
		Button_MCBSTM32_debounce(ptrButton_MCBSTM32);
	}
	else
	{
		// nothing to do
	}
	
	ptrButton_MCBSTM32->mPreviousState = locButtonState;
	return locButtonState;
}

static void Button_MCBSTM32_debounce(const Button_MCBSTM32* const ptrButton_MCBSTM32)
{
	uint32_t locLoopCounter_1 = 0;
		
	if (ptrButton_MCBSTM32 != nullptr)
	{
		for (locLoopCounter_1 = 0; locLoopCounter_1 <= ptrButton_MCBSTM32->mDebounceValue; ++locLoopCounter_1)
		{
			// debounce
		}
	}
	else
	{
		// nothing to do
	}
}

static buttonState_t Button_MCBSTM32_getPreviousState(Button_MCBSTM32* const ptrButton_MCBSTM32)
{
	buttonState_t locButtonState = UndefinedButtonState;
	
	if (ptrButton_MCBSTM32 != nullptr)
	{
		locButtonState = ptrButton_MCBSTM32->mPreviousState;
	}
	else
	{
		// nothing to do
	}
	
	return locButtonState;
}
