#include "stm32f7xx_setup.h"
#include "DriverManager.h"
#include "I_Button_Config.h"
#include "I_LED_Config.h"
#include "I_NVIC_Dispatcher_Config.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

void DriverManager_construct(DriverManager* const ptrDriverManager)
{
	STM32F7xx_NUCLEO_144_LED    locSTM32F7xx_NUCLEO_144_LED_Config;
	STM32F7xx_NUCLEO_144_Button locSTM32F7xx_NUCLEO_144_Button_Config;
	
	setupSTM32F7xx(); // basic HW initialization
		
	if (ptrDriverManager != nullptr)
	{
		// push button
		locSTM32F7xx_NUCLEO_144_Button_Config.mptrInPort              = GPIOC;
		locSTM32F7xx_NUCLEO_144_Button_Config.mInPortPinNumber        = GPIO_PIN_13;
		locSTM32F7xx_NUCLEO_144_Button_Config.mptrDebounceTimer       = &htim3;
		locSTM32F7xx_NUCLEO_144_Button_Config.mDebounceTimerState     = TimerNotExpired;
		locSTM32F7xx_NUCLEO_144_Button_Config.mptrShortPressedTimer   = &htim4;
		locSTM32F7xx_NUCLEO_144_Button_Config.mShortPressedTimerState = TimerNotExpired;
		
		I_Button_open(&ptrDriverManager->objButtonUser, &locSTM32F7xx_NUCLEO_144_Button_Config);
		
		I_NVIC_Dispatcher_registerInterrupt(&(ptrDriverManager->objButtonUser),
		                                    (void(*)(void* const, void*))&STM32F7xx_NUCLEO_144_Button_notifyDebounceTimerExpired, TIM3_InterruptVectorNumber);
		
		I_NVIC_Dispatcher_registerInterrupt(&(ptrDriverManager->objButtonUser),
		                                    (void(*)(void* const, void*))&STM32F7xx_NUCLEO_144_Button_notifyShortPressedTimerExpired, TIM4_InterruptVectorNumber);

		// LED
		locSTM32F7xx_NUCLEO_144_LED_Config.mptrOutPort = GPIOB;
		locSTM32F7xx_NUCLEO_144_LED_Config.mOutPortPinNumber = GPIO_PIN_0;
		I_LED_open(&ptrDriverManager->objLED[0], &locSTM32F7xx_NUCLEO_144_LED_Config);

		locSTM32F7xx_NUCLEO_144_LED_Config.mptrOutPort = GPIOB;
		locSTM32F7xx_NUCLEO_144_LED_Config.mOutPortPinNumber = GPIO_PIN_7;
		I_LED_open(&ptrDriverManager->objLED[1], &locSTM32F7xx_NUCLEO_144_LED_Config);
	}
	else
	{
		// nothing to do
	}
}
