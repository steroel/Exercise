#ifndef __GPIO_Driver_STM32F103_H
#define __GPIO_Driver_STM32F103_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
#include "GPIO_Register_STM32F103.h"
	
typedef enum
{
	GPIO_Input        = 0,
	GPIO_Output_10MHz = 1,
	GPIO_Output_2MHz  = 2,
	GPIO_Output_50MHz = 3 
} GPIO_Config_STM32F103_Mode_t;

typedef enum 
{
	GPO_GenaralPurpose_PushPull           = 0,
	GPO_GenaralPurpose_OpenDrain          = 1,
	GPO_AlternativeFunction_PushPull      = 2,
	GPO_AlternaticeFunction_PushOpenDrain = 3
} GPIO_Config_STM32F103_OutputMode_t;
	
typedef enum 
{
	GPI_Analog     = 0,
	GPI_Floating   = 1,
	GPI_PullUpDown = 2
} GPIO_Config_STM32F103_InputMode_t;

typedef enum
{
	GPIO_Bit_0  = 0,
	GPIO_Bit_1  = 1,
	GPIO_Bit_2  = 2,
	GPIO_Bit_3  = 3,
	GPIO_Bit_4  = 4,
	GPIO_Bit_5  = 5,
	GPIO_Bit_6  = 6,
	GPIO_Bit_7  = 7,
	GPIO_Bit_8  = 8,
	GPIO_Bit_9  = 9,
	GPIO_Bit_10 = 10,
	GPIO_Bit_11 = 11,
	GPIO_Bit_12 = 12,
	GPIO_Bit_13 = 13,
	GPIO_Bit_14 = 14,
	GPIO_Bit_15 = 15
} GPIO_Config_STM32F103_Bits_t;

typedef struct GPIO_Driver_STM32F103
{
	GPIO_Register_STM32F103*           mptrGPIO_Register_STM32F103;
	GPIO_Config_STM32F103_Mode_t       mMode;
	GPIO_Config_STM32F103_Mode_t			 mModeBackup;
	GPIO_Config_STM32F103_OutputMode_t mOutputMode;
	GPIO_Config_STM32F103_InputMode_t  mInputMode;
	GPIO_Config_STM32F103_Bits_t       mBitPositionMSB;
	GPIO_Config_STM32F103_Bits_t       mBitPositionLSB;
	uint32_t                           mBitFieldSize;
	uint32_t                           mBitFieldMask;
} GPIO_Driver_STM32F103;

#ifdef __cplusplus
}
#endif


#endif // __GPIO_Driver_STM32F103_H
