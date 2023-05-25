#ifndef __I_DriverManager_H
#define __I_DriverManager_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Button_MCBSTM32.h"
#include "LED_MCBSTM32.h"
#include "LCD_Text_AC162D_KS0066U.h"
#include "GPIO_Driver_STM32F103.h"

#define LED_AMOUNT 8
	
typedef	struct DriverManager
{
	Button_MCBSTM32         objButtonTAMP;
	Button_MCBSTM32         objButtonWKUP;
	
	GPIO_Driver_STM32F103   objGPI_ButtonTAMP;
	GPIO_Driver_STM32F103   objGPI_ButtonWKUP;
	
	LED_MCBSTM32 					  objLED[LED_AMOUNT];
	
	GPIO_Driver_STM32F103   objGPO_PB8_LED;
	GPIO_Driver_STM32F103   objGPO_PB9_LED;
	GPIO_Driver_STM32F103   objGPO_PB10_LED;
	GPIO_Driver_STM32F103   objGPO_PB11_LED;
	GPIO_Driver_STM32F103   objGPO_PB12_LED;
	GPIO_Driver_STM32F103   objGPO_PB13_LED;
	GPIO_Driver_STM32F103   objGPO_PB14_LED;
	GPIO_Driver_STM32F103   objGPO_PB15_LED;
	
	LCD_Text_AC162D_KS0066U objLCD_Text;
	
	GPIO_Driver_STM32F103   objGPIO_LCD_Control_E;
	GPIO_Driver_STM32F103   objGPIO_LCD_Control_RW;
	GPIO_Driver_STM32F103   objGPIO_LCD_Control_RS;
	GPIO_Driver_STM32F103   objGPIO_LCD_Data;
} DriverManager;

void DriverManager_construct(DriverManager* const ptrDriverManager);	


#ifdef __cplusplus
}
#endif


#endif // __DriverManager_H
