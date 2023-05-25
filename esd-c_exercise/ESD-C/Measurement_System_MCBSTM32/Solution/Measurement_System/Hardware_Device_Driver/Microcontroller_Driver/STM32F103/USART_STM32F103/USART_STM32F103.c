#include <stm32f10x.h>                        
#include "USART_STM32F103.h"

USART_TypeDef* COM_USART[COMn] = {BOARD_COM1}; 
GPIO_TypeDef* COM_TX_PORT[COMn] = {COM1_TX_GPIO_PORT};
GPIO_TypeDef* COM_RX_PORT[COMn] = {COM1_RX_GPIO_PORT};
const uint32_t COM_USART_CLK[COMn] = {COM1_CLK};
const uint32_t COM_TX_PORT_CLK[COMn] = {COM1_TX_GPIO_CLK};
const uint32_t COM_RX_PORT_CLK[COMn] = {COM1_RX_GPIO_CLK};
const uint16_t COM_TX_PIN[COMn] = {COM1_TX_PIN};
const uint16_t COM_RX_PIN[COMn] = {COM1_RX_PIN};

void COM_lowLevel_init(COM_TypeDef COM)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // enable GPIO clock
  RCC_APB2PeriphClockCmd(COM_TX_PORT_CLK[COM] | COM_RX_PORT_CLK[COM] | RCC_APB2Periph_AFIO, ENABLE);

  if (COM == COM1)
  {
    RCC_APB2PeriphClockCmd(COM_USART_CLK[COM], ENABLE); 
  }
  else
  {
    // enable the USART2 Pins Software Remapping
    //GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);
    //RCC_APB1PeriphClockCmd(COM_USART_CLK[COM], ENABLE);
  }

  // configure USART Tx as alternate function push-pull
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Pin = COM_TX_PIN[COM];
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(COM_TX_PORT[COM], &GPIO_InitStructure);

  // configure USART Rx as input floating
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Pin = COM_RX_PIN[COM];
  GPIO_Init(COM_RX_PORT[COM], &GPIO_InitStructure);

  /* USART configuration */
  //USART_Init(COM_USART[COM], USART_InitStruct);
    
  /* Enable USART */
  //USART_Cmd(COM_USART[COM], ENABLE);
}

void USART_init(void)
{
		USART_InitTypeDef 		USART_InitStructure;
		USART_ClockInitTypeDef	USART_ClockInitStructure;

		USART_InitStructure.USART_BaudRate = 115200;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No;
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

		USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;
		USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;
		USART_ClockInitStructure.USART_CPHA = USART_CPHA_2Edge;
		USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable;
		
		USART_Init( USARTx, &USART_InitStructure );
		USART_ClockInit( USARTx, &USART_ClockInitStructure);
		USART_Cmd(USARTx, ENABLE);
}

/*----------------------------------------------------------------------------
  Write character to Serial Port
 *----------------------------------------------------------------------------*/
//int ser_putchar (int c) {
int stdout_putchar (int c) {
	
  while (!(USARTx->SR & USART_FLAG_TXE));
  if( c != '\n' )
  	USARTx->DR = (c & 0x1FF);
  else
   USARTx->DR = (0x0D & 0x1FF);

  return (c);
}

/*----------------------------------------------------------------------------
  Read character from Serial Port   (blocking read)
 *----------------------------------------------------------------------------*/
int ser_getchar (void) {

  while (!(USARTx->SR & USART_FLAG_RXNE));

  return ((int)(USARTx->DR & 0x1FF));
}
