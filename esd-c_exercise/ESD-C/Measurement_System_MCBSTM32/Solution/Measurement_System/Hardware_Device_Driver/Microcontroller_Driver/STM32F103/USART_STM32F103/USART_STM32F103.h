#ifndef __USART_STM32F103_H
#define __USART_STM32F103_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
	 
typedef enum 
{
  COM1 = 0
} COM_TypeDef;   

#define COMn                             1
#define BOARD_COM1                       USART1
#define COM1_CLK                         RCC_APB2Periph_USART1
#define COM1_TX_PIN                      GPIO_Pin_9
#define COM1_TX_GPIO_PORT                GPIOA
#define COM1_TX_GPIO_CLK                 RCC_APB2Periph_GPIOA
#define COM1_RX_PIN                      GPIO_Pin_10
#define COM1_RX_GPIO_PORT                GPIOA
#define COM1_RX_GPIO_CLK                 RCC_APB2Periph_GPIOA

#define USARTx   USART1     // USART1 is used
//#define USARTx   USART2   // USART2 is used

void COM_lowLevel_init(COM_TypeDef COM);
void USART_init(void);
//int ser_putchar (int c); 
//int ser_getchar (void);

#ifdef __cplusplus
}
#endif

#endif	// __USART_STM32F103_H
