#ifndef __DriverManager_H
#define __DriverManager_H

#ifdef __cplusplus
extern "C" {
#endif

#include "STM32F7xx_NUCLEO_144_Button.h"
#include "STM32F7xx_NUCLEO_144_LED.h"


#define LED_AMOUNT 2
	
typedef	struct DriverManager
{
	STM32F7xx_NUCLEO_144_Button objButtonUser;
	//**

} DriverManager;

void DriverManager_construct(DriverManager* const ptrDriverManager);	


#ifdef __cplusplus
}
#endif


#endif // __DriverManager_H
