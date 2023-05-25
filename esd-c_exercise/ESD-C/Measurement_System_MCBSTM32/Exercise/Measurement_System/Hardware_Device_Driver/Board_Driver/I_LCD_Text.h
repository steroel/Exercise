#ifndef __I_LCD_Text_H
#define __I_LCD_Text_H


#ifdef __cplusplus
extern "C" {
#endif
	
#include "Typedefs.h"

void I_LCD_Text_clear(void* const ptrLCD_Text);
void I_LCD_Text_setCursor(void* const ptrLCD_Text, uint32_t posX, uint32_t posY);
void I_LCD_Text_writeCharacter(void* const ptrLCD_Text, char characterValue);
void I_LCD_Text_writeBargraph(void* const ptrLCD_Text, uint32_t valuePercent, uint32_t maxSegmentCount);	

#ifdef __cplusplus
}
#endif


#endif // __I_LCD_Text_H
