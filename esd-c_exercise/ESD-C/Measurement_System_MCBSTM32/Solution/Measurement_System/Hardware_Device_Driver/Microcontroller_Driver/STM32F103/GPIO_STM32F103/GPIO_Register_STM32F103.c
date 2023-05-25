#include "GPIO_Register_STM32F103.h"

void GPIO_Register_STM32F103_readCRL(const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination)
{
	if ( (ptrGPIO_Register != nullptr) && (ptrDestination != nullptr) )
	{
		*ptrDestination = ptrGPIO_Register->CRL;
	}
	else
	{
		// do to nothing
	}
}

void GPIO_Register_STM32F103_readCRH(const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination)
{
	if ( (ptrGPIO_Register != nullptr) && (ptrDestination != nullptr) )
	{
		*ptrDestination = ptrGPIO_Register->CRH;
	}
	else
	{
		// do to nothing
	}
}
void GPIO_Register_STM32F103_readIDR(const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination)
{
	if ( (ptrGPIO_Register != nullptr) && (ptrDestination != nullptr) )
	{
		*ptrDestination = ptrGPIO_Register->IDR;
	}
	else
	{
		// do to nothing
	}
}

void GPIO_Register_STM32F103_readODR(const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination)
{
	if ( (ptrGPIO_Register != nullptr) && (ptrDestination != nullptr) )
	{
		*ptrDestination = ptrGPIO_Register->ODR;
	}
	else
	{
		// do to nothing
	}
}
void GPIO_Register_STM32F103_readLCKR(const GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t* const ptrDestination)
{
	if ( (ptrGPIO_Register != nullptr) && (ptrDestination != nullptr) )
	{
		*ptrDestination = ptrGPIO_Register->LCKR;
	}
	else
	{
		// do to nothing
	}
}

void GPIO_Register_STM32F103_writeCRL(GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value)
{
	if (ptrGPIO_Register != nullptr)
	{
		ptrGPIO_Register->CRL = value;
	}
	else
	{
		// do to nothing
	}
}

void GPIO_Register_STM32F103_writeCRH(GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value)
{
	if (ptrGPIO_Register != nullptr)
	{
		ptrGPIO_Register->CRH = value;
	}
	else
	{
		// do to nothing
	}
}

void GPIO_Register_STM32F103_writeODR(GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value)
{
	if (ptrGPIO_Register != nullptr)
	{
		ptrGPIO_Register->ODR = value;
  }
	else
	{
		// do to nothing
	}
}

void GPIO_Register_STM32F103_writeBSRR(GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value)
{
	if (ptrGPIO_Register != nullptr)
	{
		ptrGPIO_Register->BSRR = value;
	}
	else
	{
		// do to nothing
	}
}

void GPIO_Register_STM32F103_writeBRR(GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value)
{
	if (ptrGPIO_Register != nullptr)
	{
		ptrGPIO_Register->BRR = value;
	}
	else
	{
		// do to nothing
	}
}

void GPIO_Register_STM32F103_writeLCKR(GPIO_Register_STM32F103* const ptrGPIO_Register, uint32_t value)
{
	if (ptrGPIO_Register != nullptr)
	{
		ptrGPIO_Register->LCKR = value;
	}
	else
	{
		// do to nothing
	}
}
