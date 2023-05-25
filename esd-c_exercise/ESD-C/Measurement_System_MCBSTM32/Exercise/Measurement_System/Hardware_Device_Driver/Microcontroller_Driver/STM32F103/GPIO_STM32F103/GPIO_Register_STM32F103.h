#ifndef __GPIO_Register_STM32F103_H
#define __GPIO_Register_STM32F103_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

typedef struct GPIO_Register_STM32F103
{
  vuint32_t CRL;
  vuint32_t CRH;
  vuint32_t IDR;
  vuint32_t ODR;
  vuint32_t BSRR;
  vuint32_t BRR;
  vuint32_t LCKR;
} GPIO_Register_STM32F103;

void GPIO_Register_STM32F103_readCRL (const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination);
void GPIO_Register_STM32F103_readCRH (const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination);
void GPIO_Register_STM32F103_readIDR (const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination);
void GPIO_Register_STM32F103_readODR (const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination);
void GPIO_Register_STM32F103_readLCKR(const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination);

void GPIO_Register_STM32F103_writeCRL (GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value);
void GPIO_Register_STM32F103_writeCRH (GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value);
void GPIO_Register_STM32F103_writeODR (GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value);
void GPIO_Register_STM32F103_writeBSRR(GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value);
void GPIO_Register_STM32F103_writeBRR (GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value);
void GPIO_Register_STM32F103_writeLCKR(GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value);


#ifdef __cplusplus
}
#endif


#endif // __GPIO_Register_STM32F103_H
