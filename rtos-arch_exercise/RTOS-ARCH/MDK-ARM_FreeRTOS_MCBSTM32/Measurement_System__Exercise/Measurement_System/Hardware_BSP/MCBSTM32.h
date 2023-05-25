#ifndef __MCBSTM32_H
#define __MCBSTM32_H

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f10x.h"

typedef enum 
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3,
  LED5 = 4,
  LED6 = 5,
  LED7 = 6,
  LED8 = 7
} Led_TypeDef;

typedef enum 
{  
  BUTTON_WAKEUP = 0,
  BUTTON_TAMPER = 1
} Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

typedef enum 
{
  COM1 = 0
} COM_TypeDef;   


#define LEDn                             8
#define LED1_PIN                         GPIO_Pin_8
#define LED1_GPIO_PORT                   GPIOB
#define LED1_GPIO_CLK                    RCC_APB2Periph_GPIOB  
#define LED2_PIN                         GPIO_Pin_9
#define LED2_GPIO_PORT                   GPIOB
#define LED2_GPIO_CLK                    RCC_APB2Periph_GPIOB  
#define LED3_PIN                         GPIO_Pin_10  
#define LED3_GPIO_PORT                   GPIOB
#define LED3_GPIO_CLK                    RCC_APB2Periph_GPIOB  
#define LED4_PIN                         GPIO_Pin_11
#define LED4_GPIO_PORT                   GPIOB
#define LED4_GPIO_CLK                    RCC_APB2Periph_GPIOB  
#define LED5_PIN                         GPIO_Pin_12
#define LED5_GPIO_PORT                   GPIOB
#define LED5_GPIO_CLK                    RCC_APB2Periph_GPIOB  
#define LED6_PIN                         GPIO_Pin_13
#define LED6_GPIO_PORT                   GPIOB
#define LED6_GPIO_CLK                    RCC_APB2Periph_GPIOB  
#define LED7_PIN                         GPIO_Pin_14  
#define LED7_GPIO_PORT                   GPIOB
#define LED7_GPIO_CLK                    RCC_APB2Periph_GPIOB  
#define LED8_PIN                         GPIO_Pin_15
#define LED8_GPIO_PORT                   GPIOB
#define LED8_GPIO_CLK                    RCC_APB2Periph_GPIOB

#define BUTTONn                          2
#define WAKEUP_BUTTON_PIN                GPIO_Pin_0
#define WAKEUP_BUTTON_GPIO_PORT          GPIOA
#define WAKEUP_BUTTON_GPIO_CLK           RCC_APB2Periph_GPIOA
#define WAKEUP_BUTTON_EXTI_LINE          EXTI_Line0
#define WAKEUP_BUTTON_EXTI_PORT_SOURCE   GPIO_PortSourceGPIOA
#define WAKEUP_BUTTON_EXTI_PIN_SOURCE    GPIO_PinSource0
#define WAKEUP_BUTTON_EXTI_IRQn          EXTI0_IRQn 
#define TAMPER_BUTTON_PIN                GPIO_Pin_13
#define TAMPER_BUTTON_GPIO_PORT          GPIOC
#define TAMPER_BUTTON_GPIO_CLK           RCC_APB2Periph_GPIOC
#define TAMPER_BUTTON_EXTI_LINE          EXTI_Line13
#define TAMPER_BUTTON_EXTI_PORT_SOURCE   GPIO_PortSourceGPIOC
#define TAMPER_BUTTON_EXTI_PIN_SOURCE    GPIO_PinSource13
#define TAMPER_BUTTON_EXTI_IRQn          EXTI15_10_IRQn 

#define COMn                             1
#define BOARD_COM1                       USART1
#define COM1_CLK                         RCC_APB2Periph_USART1
#define COM1_TX_PIN                      GPIO_Pin_9
#define COM1_TX_GPIO_PORT                GPIOA
#define COM1_TX_GPIO_CLK                 RCC_APB2Periph_GPIOA
#define COM1_RX_PIN                      GPIO_Pin_10
#define COM1_RX_GPIO_PORT                GPIOA
#define COM1_RX_GPIO_CLK                 RCC_APB2Periph_GPIOA

#define SD_SPI                           SPI1
#define SD_SPI_CLK                       RCC_APB2Periph_SPI1
#define SD_SPI_SCK_PIN                   GPIO_Pin_5
#define SD_SPI_SCK_GPIO_PORT             GPIOA
#define SD_SPI_SCK_GPIO_CLK              RCC_APB2Periph_GPIOA
#define SD_SPI_MISO_PIN                  GPIO_Pin_6
#define SD_SPI_MISO_GPIO_PORT            GPIOA
#define SD_SPI_MISO_GPIO_CLK             RCC_APB2Periph_GPIOA
#define SD_SPI_MOSI_PIN                  GPIO_Pin_7
#define SD_SPI_MOSI_GPIO_PORT            GPIOA
#define SD_SPI_MOSI_GPIO_CLK             RCC_APB2Periph_GPIOA
#define SD_CS_PIN                        GPIO_Pin_4
#define SD_CS_GPIO_PORT                  GPIOA
#define SD_CS_GPIO_CLK                   RCC_APB2Periph_GPIOC
#define SD_DETECT_PIN                    GPIO_Pin_8
#define SD_DETECT_GPIO_PORT              GPIOA
#define SD_DETECT_GPIO_CLK               RCC_APB2Periph_GPIOC

#define LCD_DB4_PIN                      GPIO_Pin_3
#define LCD_DB4_GPIO_PORT                GPIOC
#define LCD_DB4_GPIO_CLK                 RCC_APB2Periph_GPIOC
#define LCD_DB5_PIN                      GPIO_Pin_2
#define LCD_DB5_GPIO_PORT                GPIOC
#define LCD_DB5_GPIO_CLK                 RCC_APB2Periph_GPIOC
#define LCD_DB6_PIN                      GPIO_Pin_1
#define LCD_DB6_GPIO_PORT                GPIOC
#define LCD_DB6_GPIO_CLK                 RCC_APB2Periph_GPIOC
#define LCD_DB7_PIN                      GPIO_Pin_0
#define LCD_DB7_GPIO_PORT                GPIOC
#define LCD_DB7_GPIO_CLK                 RCC_APB2Periph_GPIOC
#define LCD_DATA_PINS             		 (0x0F << 0)
#define LCD_E_PIN                        GPIO_Pin_10
#define LCD_E_GPIO_PORT                  GPIOC
#define LCD_E_GPIO_CLK                   RCC_APB2Periph_GPIOC
#define LCD_RW_PIN                       GPIO_Pin_11
#define LCD_RW_GPIO_PORT                 GPIOC
#define LCD_RW_GPIO_CLK                  RCC_APB2Periph_GPIOC
#define LCD_RS_PIN                       GPIO_Pin_12
#define LCD_RS_GPIO_PORT                 GPIOC
#define LCD_RS_GPIO_CLK                  RCC_APB2Periph_GPIOC


void LED_init(Led_TypeDef Led);
void LED_setOn(Led_TypeDef Led);
void LED_setOff(Led_TypeDef Led);
void LED_toggle(Led_TypeDef Led);

void PB_init(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t PB_getState(Button_TypeDef Button);

void COM_lowLevel_init(COM_TypeDef COM);

void SD_lowLevel_deInit(void);
void SD_lowLevel_init(void);

void LCD_lowLevel_init(void); 

   
#ifdef __cplusplus
}
#endif
  
#endif /* __MCBSTM32_H */
/*****************************************************************************/
