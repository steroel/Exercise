#ifndef __LCD_Text_AC162D_KS0066U_H
#define __LCD_Text_AC162D_KS0066U_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
	
typedef enum
{
	DataBus_4Bit = 4,
	DataBus_8Bit = 8
} LCD_Text_AC162D_KS0066U_Config_DataBusWidth_t;

typedef enum
{
	Line_1 = 1,
	Line_2 = 2
} LCD_Text_AC162D_KS0066U_Config_Lines_t;

typedef enum
{
	Columns_16 = 16,
	Columns_20 = 20,
	Columns_40 = 40
} LCD_Text_AC162D_KS0066U_Config_Columns_t;

typedef enum
{
	Dots_5x8  = 0,
	Dots_5x11 = 1
} LCD_Text_AC162D_KS0066U_Config_Dots_t;

typedef struct LCD_Text_AC162D_KS0066U
{
	void* mptrGPIO_LCD_Control_E;
	void* mptrGPIO_LCD_Control_RS;
	void* mptrGPIO_LCD_Control_RW;
	void* mptrGPIO_LCD_Data;
	uint32_t                                      mBusDelay_2N;  	// if processor works on high frequency delay has to be increased, it can be increased by factor 2^N by this constant
	LCD_Text_AC162D_KS0066U_Config_DataBusWidth_t mDataBusWidth;
	LCD_Text_AC162D_KS0066U_Config_Lines_t        mLines;
	LCD_Text_AC162D_KS0066U_Config_Columns_t      mColumns;
  LCD_Text_AC162D_KS0066U_Config_Dots_t         mDots;
} LCD_Text_AC162D_KS0066U;


#ifdef __cplusplus
}
#endif


#endif // __LCD_Text_AC162D_KS0066U_H
