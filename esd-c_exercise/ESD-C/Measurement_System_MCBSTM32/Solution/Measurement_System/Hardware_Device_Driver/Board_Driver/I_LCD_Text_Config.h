#ifndef __I_LCD_Text_Config_H
#define __I_LCD_Text_Config_H


#ifdef __cplusplus
extern "C" {
#endif
	
#include "Typedefs.h"

void I_LCD_Text_open(void* const ptrLCD_Text, const void* const ptrLCD_TextConfig);
void I_LCD_Text_close(void* const ptrLCD_Text);

#ifdef __cplusplus
}
#endif


#endif // __I_LCD_Text_Config_H
