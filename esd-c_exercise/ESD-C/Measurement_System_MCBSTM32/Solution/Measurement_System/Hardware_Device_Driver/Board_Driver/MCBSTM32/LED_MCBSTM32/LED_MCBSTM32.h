#ifndef __LED_MCBSTM32_H
#define __LED_MCBSTM32_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

typedef enum
{
	LowActiveLED  = 0,
	HighActiveLED = 1
} LED_MCBSTM32_Config_Activity_t;
	
typedef struct LED_MCBSTM32
{
	void* mptrOutPort;
	LED_MCBSTM32_Config_Activity_t mActivity;
} LED_MCBSTM32;


#ifdef __cplusplus
}
#endif


#endif // __LED_MCBSTM32_H
