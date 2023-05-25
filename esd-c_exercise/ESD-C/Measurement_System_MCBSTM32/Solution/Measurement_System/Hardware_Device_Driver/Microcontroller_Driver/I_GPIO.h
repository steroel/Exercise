#ifndef __I_GPIO_H
#define __I_GPIO_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "I_GPIO_Types.h"
	
typedef enum 
{
	Input = 0,
	Output = 1
} I_GPIO_Direction_t;
	
void I_GPIO_read(void* const ptrGPIO_Driver, port_t* const ptrDestination);
void I_GPIO_write(void* const ptrGPIO_Driver, port_t portValue);
void I_GPIO_setDirection(void* const ptrGPIO_Driver, I_GPIO_Direction_t direction);

#ifdef __cplusplus
}
#endif


#endif // _I_GPIO_H
