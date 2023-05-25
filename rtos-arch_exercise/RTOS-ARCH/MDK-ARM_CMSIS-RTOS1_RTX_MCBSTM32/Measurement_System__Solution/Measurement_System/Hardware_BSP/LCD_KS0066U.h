#ifndef __KS00660U_LCD_H
#define __KS00660U_LCD_H

void LCD_init           (void);
void LCD_clear          (void);
void LCD_setCursor      (int column, int line);
void LCD_printChar      (char c);
void LCD_printCharXY    (int pos_x, int pos_y, char c);
void LCD_printString    (char *string);
void LCD_printStringXY 	(int pos_x, int pos_y, char *string);
void LCD_printBargraph  (int value, int size);
void LCD_printBargraphXY(int pos_x, int pos_y, int value);

#endif /* __KS00660U_LCD_H */

/******************************************************************************/

