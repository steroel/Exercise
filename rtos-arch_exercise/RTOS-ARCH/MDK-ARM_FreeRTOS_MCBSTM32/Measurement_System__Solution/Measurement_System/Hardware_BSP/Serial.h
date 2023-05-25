#ifndef __SERIAL_H
#define __SERIAL_H

#ifdef __cplusplus
 extern "C" {
#endif

#define USARTx   USART1     // USART1 is used
//#define USARTx   USART2   // USART2 is used

void SER_init(void);
//int ser_putchar (int c); 
//int ser_getchar (void);

#ifdef __cplusplus
}
#endif

#endif
