#ifndef __MCBSTM32_LED_H__
#define __MCBSTM32_LED_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f1xx_hal.h"
   
typedef enum 
{
  LED1 = 0,
	LED2 = 1,
	LED3 = 2,
	LED4 = 3,
	LED5 = 4,
	LED6 = 5,
	LED7 = 6,
	LED8 = 7,
} Led_TypeDef;

#define LEDn                                    8

#define LED1_PIN                                GPIO_PIN_8
#define LED1_GPIO_PORT                          GPIOB
#define LED1_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_DISABLE()  

#define LED2_PIN                                GPIO_PIN_9
#define LED2_GPIO_PORT                          GPIOB
#define LED2_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_DISABLE()  

#define LED3_PIN                                GPIO_PIN_10
#define LED3_GPIO_PORT                          GPIOB
#define LED3_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_DISABLE()

#define LED4_PIN                                GPIO_PIN_11
#define LED4_GPIO_PORT                          GPIOB
#define LED4_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED4_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_DISABLE()  

#define LED5_PIN                                GPIO_PIN_12
#define LED5_GPIO_PORT                          GPIOB
#define LED5_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED5_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_DISABLE()  

#define LED6_PIN                                GPIO_PIN_13
#define LED6_GPIO_PORT                          GPIOB
#define LED6_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED6_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_DISABLE() 

#define LED7_PIN                                GPIO_PIN_14
#define LED7_GPIO_PORT                          GPIOB
#define LED7_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED7_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_DISABLE()  

#define LED8_PIN                                GPIO_PIN_15
#define LED8_GPIO_PORT                          GPIOB
#define LED8_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED8_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_DISABLE()  

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)   do { if((__INDEX__) == 0) {__HAL_RCC_GPIOB_CLK_ENABLE();} else\
                                                                    {__HAL_RCC_GPIOB_CLK_ENABLE();   }} while(0)	
#define LEDx_GPIO_CLK_DISABLE(__INDEX__)  do { if((__INDEX__) == 0) {__HAL_RCC_GPIOB_CLK_DISABLE();} else\
                                                                    {__HAL_RCC_GPIOB_CLK_DISABLE();   }} while(0)	
void BSP_LED_Init(Led_TypeDef Led);
void BSP_LED_DeInit(Led_TypeDef Led);
void BSP_LED_On(Led_TypeDef Led);
void BSP_LED_Off(Led_TypeDef Led);
void BSP_LED_Toggle(Led_TypeDef Led);

#ifdef __cplusplus
}
#endif

#endif /* __MCBSTM32_LED_H__ */

