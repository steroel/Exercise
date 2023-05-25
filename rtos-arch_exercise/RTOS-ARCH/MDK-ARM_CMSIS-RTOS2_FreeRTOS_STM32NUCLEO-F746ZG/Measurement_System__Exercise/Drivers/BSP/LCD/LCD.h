#ifndef __LCD_H
#define __LCD_H

#ifdef __cplusplus
 extern "C" {
#endif

typedef enum 
{
  LINE1 = 0,
  LINE2 = 1,
  MaxLines
}Lines_t;

typedef enum 
{  
  ROW1  = 0,
  ROW2  = 1,
  ROW3  = 2,
  ROW4  = 3,
  ROW5  = 4,
  ROW6  = 5,
  ROW7  = 6,
  ROW8  = 7,
  ROW9  = 8,
  ROW10 = 9,
  ROW11 = 10,
  ROW12 = 11,
  ROW13 = 12,
  ROW14 = 13,
  ROW15 = 14,
  ROW16 = 15,
  MaxRows
}Rows_t;

void BSP_LCD_printStringXY(Rows_t parRow, Lines_t parLine, char* parString);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F7XX_NUCLEO_144_H */
