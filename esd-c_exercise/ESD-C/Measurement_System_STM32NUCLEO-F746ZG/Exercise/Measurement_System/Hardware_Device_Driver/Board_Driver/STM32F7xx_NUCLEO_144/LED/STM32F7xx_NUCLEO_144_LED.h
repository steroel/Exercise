#ifndef __STM32F7xx_NUCLEO_144_LED_H
#define __STM32F7xx_NUCLEO_144_LED_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "stm32f7xx_hal.h"

typedef struct STM32F7xx_NUCLEO_144_LED
{
	GPIO_TypeDef* mptrOutPort;
	uint32_t mOutPortPinNumber;
} STM32F7xx_NUCLEO_144_LED;


#ifdef __cplusplus
}
#endif


#endif // __STM32F7xx_NUCLEO_144_LED_H
