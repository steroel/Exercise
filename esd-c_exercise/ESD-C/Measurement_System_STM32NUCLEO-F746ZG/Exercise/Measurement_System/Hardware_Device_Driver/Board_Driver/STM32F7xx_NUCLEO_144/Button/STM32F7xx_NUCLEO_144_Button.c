#include "STM32F7xx_NUCLEO_144_Button.h"
#include "I_Button_Config.h"
#include "I_Button.h"

static void STM32F7xx_NUCLEO_144_Button_open(STM32F7xx_NUCLEO_144_Button* const ptrButton, const STM32F7xx_NUCLEO_144_Button* const prtButtonConfig);
static void STM32F7xx_NUCLEO_144_Button_close(STM32F7xx_NUCLEO_144_Button* const ptrButton);
static buttonState_t STM32F7xx_NUCLEO_144_Button_getState(STM32F7xx_NUCLEO_144_Button* const ptrButton);

void I_Button_open(void* const ptrButton, const void* const prtButton_Config)
{
	if ( (ptrButton != nullptr) && (prtButton_Config != nullptr) )
	{
		STM32F7xx_NUCLEO_144_Button_open((STM32F7xx_NUCLEO_144_Button*) ptrButton, (STM32F7xx_NUCLEO_144_Button*) prtButton_Config);
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
		STM32F7xx_NUCLEO_144_Button_close((STM32F7xx_NUCLEO_144_Button*) ptrButton);
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
		locButtonState = STM32F7xx_NUCLEO_144_Button_getState((STM32F7xx_NUCLEO_144_Button*) ptrButton);
	}
	else
	{
		// nothing to do
	}
	
	return locButtonState;
}

// interrupt callback debounce timer
void STM32F7xx_NUCLEO_144_Button_notifyDebounceTimerExpired(STM32F7xx_NUCLEO_144_Button* const ptrButton, void* par)
{
	if (ptrButton != nullptr)
	{
		ptrButton->mDebounceTimerState = TimerIsExpired;
	}
	else
	{
		// nothing to do
	}
}	
// interrupt callback short pressed time detection
void STM32F7xx_NUCLEO_144_Button_notifyShortPressedTimerExpired(STM32F7xx_NUCLEO_144_Button* const ptrButton, void* par)
{
	if (ptrButton != nullptr)
	{
		ptrButton->mShortPressedTimerState = TimerIsExpired;
	}
	else
	{
		// nothing to do
	}
}	

static void STM32F7xx_NUCLEO_144_Button_open(STM32F7xx_NUCLEO_144_Button* const ptrButton, const STM32F7xx_NUCLEO_144_Button* const ptrButtonConfig)
{
	if ( (ptrButton != nullptr) && (ptrButtonConfig != nullptr) )
	{
		ptrButton->mptrInPort              = ptrButtonConfig->mptrInPort;
		ptrButton->mInPortPinNumber        = ptrButtonConfig->mInPortPinNumber;
		ptrButton->mptrDebounceTimer       = ptrButtonConfig->mptrDebounceTimer;
		ptrButton->mDebounceTimerState     = ptrButtonConfig->mDebounceTimerState;
		ptrButton->mptrShortPressedTimer   = ptrButtonConfig->mptrShortPressedTimer;
		ptrButton->mShortPressedTimerState = ptrButtonConfig->mShortPressedTimerState;
		
		GPIO_InitTypeDef  GPIO_InitStruct;	
		uint64_t locPortBaseAdress = (uint64_t)ptrButton->mptrInPort;
		
		switch(locPortBaseAdress)
		{
			case GPIOA_BASE:
				__HAL_RCC_GPIOA_CLK_ENABLE();
			break;
			case GPIOB_BASE:
				__HAL_RCC_GPIOB_CLK_ENABLE();
			break;
			case GPIOC_BASE:
				__HAL_RCC_GPIOC_CLK_ENABLE();
			break;
			case GPIOD_BASE:
				__HAL_RCC_GPIOD_CLK_ENABLE();
			break;
			case GPIOE_BASE:
				__HAL_RCC_GPIOE_CLK_ENABLE();
			break;
			case GPIOF_BASE:
				__HAL_RCC_GPIOF_CLK_ENABLE();
			break;
			case GPIOG_BASE:
				__HAL_RCC_GPIOG_CLK_ENABLE();
			break;
			case GPIOH_BASE:
				__HAL_RCC_GPIOH_CLK_ENABLE();
			break;
			case GPIOI_BASE:
				__HAL_RCC_GPIOI_CLK_ENABLE();
			break;
			case GPIOJ_BASE:
				__HAL_RCC_GPIOJ_CLK_ENABLE();
			break;
			case GPIOK_BASE:
				__HAL_RCC_GPIOK_CLK_ENABLE();
			break;
			default:
				// nothing to do
			break;			
		}
  
     /* Configure Button pin as input */
    GPIO_InitStruct.Pin   = ptrButton->mInPortPinNumber;
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(ptrButton->mptrInPort, &GPIO_InitStruct);
	}
	else
	{
		// nothing to do
	}
}

static void STM32F7xx_NUCLEO_144_Button_close(STM32F7xx_NUCLEO_144_Button* const ptrButton)
{
	if (ptrButton != nullptr)
	{
    HAL_GPIO_DeInit(ptrButton->mptrInPort, ptrButton->mInPortPinNumber);
		
		ptrButton->mptrInPort              = nullptr;
		ptrButton->mInPortPinNumber        = 0;
		ptrButton->mptrDebounceTimer       = nullptr;
		ptrButton->mDebounceTimerState     = TimerNotExpired;
		ptrButton->mptrShortPressedTimer   = nullptr;
		ptrButton->mShortPressedTimerState = TimerNotExpired;
	}
	else
	{
		// nothing to do
	}
}

static buttonState_t STM32F7xx_NUCLEO_144_Button_getState(STM32F7xx_NUCLEO_144_Button* const ptrButton)
{
	buttonState_t locButtonState = UndefinedButtonState;
	
	if (ptrButton != nullptr)
	{
		if (HAL_GPIO_ReadPin(ptrButton->mptrInPort, ptrButton->mInPortPinNumber) == GPIO_PIN_SET)
		{
			ptrButton->mDebounceTimerState = TimerNotExpired;                 // reset debounce timeout
			HAL_TIM_OC_Start_IT(ptrButton->mptrDebounceTimer, TIM_CHANNEL_1); // after the 1st detected press, start the debounce timer
			while(ptrButton->mDebounceTimerState == TimerNotExpired)			
			{
				// wait for debounce timeout
			}
			
			ptrButton->mShortPressedTimerState = TimerNotExpired;                 // reset short press timeout
			HAL_TIM_OC_Start_IT(ptrButton->mptrShortPressedTimer, TIM_CHANNEL_1); // start timer to differ between short and long button press			
			while(HAL_GPIO_ReadPin(ptrButton->mptrInPort, ptrButton->mInPortPinNumber) == GPIO_PIN_SET)
			{
				// wait for buttom release
			}
			
			switch(ptrButton->mShortPressedTimerState) // select between short and long press
			{
				case TimerNotExpired: // short press
					HAL_TIM_OC_Stop_IT(ptrButton->mptrShortPressedTimer, TIM_CHANNEL_1);
					__HAL_TIM_SET_COUNTER(ptrButton->mptrShortPressedTimer, 0x00000000); // reset counter value
					__HAL_TIM_CLEAR_FLAG(ptrButton->mptrShortPressedTimer, 0x0000001E);  // reset counter status flags
				  locButtonState = ReleasedAfterShortPressedButtonState; 
				break;
				
				case TimerIsExpired: // long press
					locButtonState = ReleasedAfterLongPressedButtonState;
				break;
					
				default:
					locButtonState = UndefinedButtonState;
				break;
			}
		}
		else
		{
			locButtonState = ReleasedButtonState;
		}
	}
	return locButtonState;
}
