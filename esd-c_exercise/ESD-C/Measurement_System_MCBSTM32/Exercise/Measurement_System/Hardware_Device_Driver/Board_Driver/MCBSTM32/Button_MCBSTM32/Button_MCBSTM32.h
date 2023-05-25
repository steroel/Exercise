#ifndef __Button_MCBSTM32_H
#define __Button_MCBSTM32_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "I_Button_Types.h"

typedef enum
{
	LowActiveButton  = 0,
	HighActiveButton = 1
} Button_MCBSTM32_Config_Activity_t;
	
typedef struct Button_MCBSTM32
{
	void* mptrInPort;
	Button_MCBSTM32_Config_Activity_t mActivity;
	buttonState_t mPreviousState;
	uint32_t mDebounceValue;
} Button_MCBSTM32;


#ifdef __cplusplus
}
#endif


#endif // __Butto_MCBSTM32_H
