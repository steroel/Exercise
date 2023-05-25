#ifndef __I_NVIC_Dispatcher_H
#define __I_NVIC_Dispatcher_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "I_NVIC_Dispatcher_Types.h"	
#include "ICB_ServiceInterrupt.h"
	
void I_NVIC_Dispatcher_registerInterrupt(void* const ptrCallbackObject, 
	                          ICB_InterruptService_serviceInterrupt_fptr fptr_serviceInterrupt,
                            interruptVectorNumber_t interruptVectorNumber);
void I_NVIC_Dispatcher_unregisterInterrupt(interruptVectorNumber_t interruptVectorNumber);	

#ifdef __cplusplus
}
#endif


#endif // __I_NVIC_Dispatcher_Config
