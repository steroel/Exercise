#ifndef __STM32F7xx_NUCLEO_144_Button_H
#define __STM32F7xx_NUCLEO_144_Button_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "I_Button_Types.h"
#include "stm32f7xx_hal.h"

typedef enum
{
	TimerNotExpired = 0,
	TimerIsExpired  = 1
}timerExpired_t;

typedef struct STM32F7xx_NUCLEO_144_Button
{
	GPIO_TypeDef* mptrInPort;
	uint32_t mInPortPinNumber;
	TIM_HandleTypeDef* mptrDebounceTimer;
	volatile timerExpired_t mDebounceTimerState;
	TIM_HandleTypeDef* mptrShortPressedTimer;
	volatile timerExpired_t mShortPressedTimerState;
} STM32F7xx_NUCLEO_144_Button;

void STM32F7xx_NUCLEO_144_Button_notifyDebounceTimerExpired(STM32F7xx_NUCLEO_144_Button* const ptrButton, void* par);
void STM32F7xx_NUCLEO_144_Button_notifyShortPressedTimerExpired(STM32F7xx_NUCLEO_144_Button* const ptrButton, void* par);


#ifdef __cplusplus
}
#endif


#endif // STM32F7xx_NUCLEO_144_Button_H
