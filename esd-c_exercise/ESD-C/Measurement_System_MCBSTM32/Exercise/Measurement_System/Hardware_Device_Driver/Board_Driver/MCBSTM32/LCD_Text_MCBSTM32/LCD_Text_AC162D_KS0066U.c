#include "LCD_Text_AC162D_KS0066U.h"
#include "I_LCD_Text.h"
#include "I_LCD_Text_Config.h"
#include "I_GPIO.h"

typedef enum
{
	ClearDisplay                               = 0x01,
	ReturnHome                                 = 0x02,
	EntryMode_MoveRight_NoShiftDisplay         = 0x06,
	EntryMode_MoveRight_ShiftDisplay           = 0x07,
	OnOffControl_DisplayOn_CursorOff_BlinkOff  = 0x0C,
	OnOffControl_DisplayOn_CursorOn_BlinkOff   = 0x0E,
	OnOffControl_DisplayOn_CursorOn_BlinkOn    = 0x0F,
	OnOffControl_DisplayOff_CursorOff_BlinkOff = 0x08,
	CursorDisplay_Shift_DirectionRight         = 0x00,
	CursorDisplay_NoShift_DirectionLeft        = 0x00,
	FunctionSet_DL4Bit_1Line_5x11Dots          = 0x24,
	FunctionSet_DL8Bit_1Line_5x11Dots          = 0x34,
	FunctionSet_DL4Bit_2Line_5x11Dots          = 0x2C,
	FunctionSet_DL8Bit_2Line_5x11Dots          = 0x3C,
	FunctionSet_DL4Bit_1Line_5x8Dots           = 0x20,
	FunctionSet_DL8Bit_1Line_5x8Dots           = 0x30,
	FunctionSet_DL4Bit_2Line_5x8Dots           = 0x28,
	FunctionSet_DL8Bit_2Line_5x8Dots           = 0x38
} LCD_TextControllerCommand_t;

static void LCD_Text_AC162D_KS0066U_delay(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint32_t delayCycles);
static uint8_t LCD_Text_AC162D_KS0066U_readStatus(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U);
static uint8_t LCD_Text_AC162D_KS0066U_waitWhileBusy(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AD162D_KS0066U);
static void LCD_Text_AC162D_KS0066U_write4Bit(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint8_t dataBusValue4Bits);
static void LCD_Text_AC162D_KS0066U_writeCommand(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, LCD_TextControllerCommand_t command);
static void LCD_Text_AC162D_KS0066U_writeCGRAM_Address(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint8_t addressCGRAM);
static void LCD_Text_AC162D_KS0066U_writeDDRAM_Address(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint8_t addressDDRAM);
static void LCD_Text_AC162D_KS0066U_writeData(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint8_t data);
static void LCD_Text_AC162D_KS0066U_init4BitDataBusInterface(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U);
static void LCD_Text_AC162D_KS0066U_open(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U,
                                            const LCD_Text_AC162D_KS0066U* const ptrLCD_TextController_Config_KS0066U );
static void LCD_Text_AC162D_KS0066U_close(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U);	
static void LCD_Text_AC162D_KS0066U_clear(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U);
static void LCD_Text_AC162D_KS0066U_setCursor(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint32_t posX, uint32_t posY);
static void LCD_Text_AC162D_KS0066U_writeCharacter(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, char characterValue);
static void LCD_Text_AC162D_KS0066U_writeBargpaph(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint32_t valuePercent, uint32_t maxSegmentCount);

void I_LCD_Text_open(void* const ptrLCD_Text, const void* const ptrLCD_TextConfig)
{
	if ((ptrLCD_Text != nullptr) && (ptrLCD_TextConfig != nullptr))
	{
		LCD_Text_AC162D_KS0066U_open((LCD_Text_AC162D_KS0066U*) ptrLCD_Text, (LCD_Text_AC162D_KS0066U*) ptrLCD_TextConfig);
	}
	else
	{
		// nothing to do
	}
}

void I_LCD_Text_close(void* const ptrLCD_Text)
{
	if (ptrLCD_Text != nullptr)
	{
		LCD_Text_AC162D_KS0066U_close((LCD_Text_AC162D_KS0066U*) ptrLCD_Text);
	}
	else
	{
		// nothing to do
	}
}

void I_LCD_Text_clear(void* const ptrLCD_Text)
{
	if (ptrLCD_Text != nullptr)
	{
		LCD_Text_AC162D_KS0066U_clear((LCD_Text_AC162D_KS0066U*) ptrLCD_Text);
	}
	else
	{
		// nothing to do
	}
}

void I_LCD_Text_setCursor(void* const ptrLCD_Text, uint32_t posX, uint32_t posY)
{
	if (ptrLCD_Text != nullptr)
	{
		LCD_Text_AC162D_KS0066U_setCursor((LCD_Text_AC162D_KS0066U*) ptrLCD_Text, posX, posY);
	}
	else
	{
		// nothing to do
	}
}

void I_LCD_Text_writeCharacter(void* const ptrLCD_Text, char characterValue)
{
	if (ptrLCD_Text != nullptr)
	{
		LCD_Text_AC162D_KS0066U_writeCharacter((LCD_Text_AC162D_KS0066U*) ptrLCD_Text, characterValue);
	}
	else
	{
		// nothing to do
	}
}

void I_LCD_Text_writeBargraph(void* const ptrLCD_Text, uint32_t valuePercent, uint32_t maxSegmentCount)
{
	if (ptrLCD_Text != nullptr)
	{
		LCD_Text_AC162D_KS0066U_writeBargpaph((LCD_Text_AC162D_KS0066U*) ptrLCD_Text, valuePercent, maxSegmentCount);
	}
	else
	{
		// nothing to do
	}
}


static void LCD_Text_AC162D_KS0066U_delay(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint32_t delayCycles)
{
  if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		delayCycles <<= ptrLCD_Text_AC162D_KS0066U->mBusDelay_2N;
		while (delayCycles--);
	}
	else
	{
		// nothing to do
	}
}

static uint8_t LCD_Text_AC162D_KS0066U_readStatus(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U)
{
  const uint32_t SwapData[16] = { 0x0, 0x8, 0x4, 0xC, 0x2, 0xA, 0x6, 0xE, 
                                  0x1, 0x9, 0x5, 0xD, 0x3, 0xB, 0x7, 0xF};
	uint8_t locLCD_Status = 0;
	uint32_t upper4Bits   = 0;
	uint32_t lower4Bits   = 0;				

	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		I_GPIO_setDirection(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Data, Input);
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RS, 0);
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RW, 1);
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 10);
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_E, 1);
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 10);
		
		I_GPIO_read(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Data, &upper4Bits);
		upper4Bits = (SwapData[upper4Bits]) << 4;
		
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_E, 0);
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 10);
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_E, 1);
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 10);
		
		I_GPIO_read(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Data, &lower4Bits);
		locLCD_Status = upper4Bits + (SwapData[lower4Bits]);
			
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_E, 0);
		I_GPIO_setDirection(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Data, Output);
  } 
	else
	{
		// nothing to do
	}																
  
	return (locLCD_Status);
}

static uint8_t LCD_Text_AC162D_KS0066U_waitWhileBusy(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U)
{
  uint8_t locLCD_Status = 0;

	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		do
		{
			locLCD_Status = LCD_Text_AC162D_KS0066U_readStatus(ptrLCD_Text_AC162D_KS0066U);
		}
		while (locLCD_Status & 0x80); // wait for busy flag
	} 
	else
	{
		// nothing to do
	}	

  return (locLCD_Status);
}

static void LCD_Text_AC162D_KS0066U_write4Bit(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint8_t dataBusValue4Bits)
{
  static const uint32_t SwapData[16] = { 0x0, 0x8, 0x4, 0xC, 0x2, 0xA, 0x6, 0xE, 
                                         0x1, 0x9, 0x5, 0xD, 0x3, 0xB, 0x7, 0xF};
	uint8_t locData = dataBusValue4Bits&0x0F;
																				 
  locData = SwapData[dataBusValue4Bits&0x0F] << 0;
	
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{	
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RW, 0);
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_E, 1);
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Data, locData);
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 10);
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_E, 0);
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 10);
	}
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_writeCommand(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, LCD_TextControllerCommand_t command)
{
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		LCD_Text_AC162D_KS0066U_waitWhileBusy(ptrLCD_Text_AC162D_KS0066U);

		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RS, 0);
		
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, command>>4);
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, command);
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_writeCGRAM_Address(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint8_t addressCGRAM)
{
	uint8_t locCommand = 0x40 + addressCGRAM;
	
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		LCD_Text_AC162D_KS0066U_waitWhileBusy(ptrLCD_Text_AC162D_KS0066U);

		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RS, 0);
		
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, locCommand >> 4);
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, locCommand);
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_writeDDRAM_Address(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint8_t addressDDRAM)
{
	uint8_t locCommand = 0x80 + addressDDRAM;
	
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		LCD_Text_AC162D_KS0066U_waitWhileBusy(ptrLCD_Text_AC162D_KS0066U);

		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RS, 0);
		
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, locCommand >> 4);
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, locCommand);
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_writeData(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint8_t data)
{
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		LCD_Text_AC162D_KS0066U_waitWhileBusy(ptrLCD_Text_AC162D_KS0066U);

		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RS, 1);

		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, data >> 4);
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, data);
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_init4BitDataBusInterface(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U)
{ 
  // 8 user defined characters to be loaded into CGRAM (used for bargraph)
	const char UserFont[8][8] = {
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
	{ 0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10 },
	{ 0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18 },
	{ 0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C },
	{ 0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E,0x1E },
	{ 0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F },
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 },
	{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }
	};
	
	uint32_t locLoopCounter = 0;
	char const* ptrChar = &UserFont[0][0];

	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 15000);
		
		I_GPIO_write(ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RS, 0);
		// Select 4-bit interface
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, 0x3);
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 4100);
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, 0x3);
		LCD_Text_AC162D_KS0066U_delay(ptrLCD_Text_AC162D_KS0066U, 100);
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, 0x3);
		LCD_Text_AC162D_KS0066U_write4Bit(ptrLCD_Text_AC162D_KS0066U, 0x2);

		LCD_Text_AC162D_KS0066U_writeCommand(ptrLCD_Text_AC162D_KS0066U, FunctionSet_DL4Bit_2Line_5x8Dots);
		LCD_Text_AC162D_KS0066U_writeCommand(ptrLCD_Text_AC162D_KS0066U, OnOffControl_DisplayOn_CursorOff_BlinkOff);
		LCD_Text_AC162D_KS0066U_writeCommand(ptrLCD_Text_AC162D_KS0066U, EntryMode_MoveRight_NoShiftDisplay);

		// Load user-specific characters into CGRAM
		LCD_Text_AC162D_KS0066U_writeCGRAM_Address(ptrLCD_Text_AC162D_KS0066U, 0x00);

		for (locLoopCounter = 0; locLoopCounter < sizeof(UserFont); locLoopCounter++, ptrChar++)
		{
			LCD_Text_AC162D_KS0066U_writeCharacter(ptrLCD_Text_AC162D_KS0066U, *ptrChar);
		}
			
		LCD_Text_AC162D_KS0066U_writeDDRAM_Address(ptrLCD_Text_AC162D_KS0066U, 0x00);
		LCD_Text_AC162D_KS0066U_clear(ptrLCD_Text_AC162D_KS0066U);							
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_open(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U,
                                     const LCD_Text_AC162D_KS0066U* const ptrLCD_TextControllerConfig_KS0066U )
{
	if ( (ptrLCD_Text_AC162D_KS0066U != nullptr) && (ptrLCD_TextControllerConfig_KS0066U != nullptr) )
	{
		ptrLCD_Text_AC162D_KS0066U->mBusDelay_2N  = ptrLCD_TextControllerConfig_KS0066U->mBusDelay_2N;
		ptrLCD_Text_AC162D_KS0066U->mDataBusWidth = ptrLCD_TextControllerConfig_KS0066U->mDataBusWidth;
		ptrLCD_Text_AC162D_KS0066U->mLines        = ptrLCD_TextControllerConfig_KS0066U->mLines;
		ptrLCD_Text_AC162D_KS0066U->mColumns      = ptrLCD_TextControllerConfig_KS0066U->mColumns;
		ptrLCD_Text_AC162D_KS0066U->mDots         = ptrLCD_TextControllerConfig_KS0066U->mDots;
		
		ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_E  = ptrLCD_TextControllerConfig_KS0066U->mptrGPIO_LCD_Control_E;
		ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RW = ptrLCD_TextControllerConfig_KS0066U->mptrGPIO_LCD_Control_RW;
		ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RS = ptrLCD_TextControllerConfig_KS0066U->mptrGPIO_LCD_Control_RS;
		ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Data = ptrLCD_TextControllerConfig_KS0066U->mptrGPIO_LCD_Data;
		LCD_Text_AC162D_KS0066U_init4BitDataBusInterface(ptrLCD_Text_AC162D_KS0066U);
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_close(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U)
{
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_E  = nullptr;
		ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RW = nullptr;
		ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Control_RS = nullptr;
		ptrLCD_Text_AC162D_KS0066U->mptrGPIO_LCD_Data       = nullptr;
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_clear(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U)
{
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		LCD_Text_AC162D_KS0066U_writeCommand(ptrLCD_Text_AC162D_KS0066U, ClearDisplay);
		LCD_Text_AC162D_KS0066U_setCursor(ptrLCD_Text_AC162D_KS0066U, 0, 0);
	}
	else
	{
		// nothing to do
	}
}

static void LCD_Text_AC162D_KS0066U_setCursor(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint32_t posX, uint32_t posY)
{
	uint8_t locAddress = 0;

	locAddress = (posY * 40) + posX;
	locAddress = locAddress & 0x7F;
	
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		LCD_Text_AC162D_KS0066U_writeDDRAM_Address(ptrLCD_Text_AC162D_KS0066U, locAddress);
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_writeCharacter(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, char characterValue)
{
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		LCD_Text_AC162D_KS0066U_writeData(ptrLCD_Text_AC162D_KS0066U, characterValue);
	} 
	else
	{
		// nothing to do
	}	
}

static void LCD_Text_AC162D_KS0066U_writeBargpaph(LCD_Text_AC162D_KS0066U* const ptrLCD_Text_AC162D_KS0066U, uint32_t valuePercent, uint32_t maxSegmentCount)
{
	const uint32_t locSegmentXdots = 5;
	uint32_t locLoopCountValue     = 0;
	uint32_t locSegmentXpixelValue = 0;
	
	if (ptrLCD_Text_AC162D_KS0066U != nullptr)
	{
		locSegmentXpixelValue = valuePercent * maxSegmentCount / (100 / locSegmentXdots);
		
		for (locLoopCountValue = 0; locLoopCountValue < maxSegmentCount; locLoopCountValue++)
		{
			 if (locSegmentXpixelValue > locSegmentXdots)
			{
					LCD_Text_AC162D_KS0066U_writeCharacter(ptrLCD_Text_AC162D_KS0066U, 0x05);
					locSegmentXpixelValue -= locSegmentXdots;
			 }
			 else
			{
					LCD_Text_AC162D_KS0066U_writeCharacter(ptrLCD_Text_AC162D_KS0066U, locSegmentXpixelValue);
					break;
			}
		 }	
	 } 
	else
	{
		// nothing to do
	}	
}
