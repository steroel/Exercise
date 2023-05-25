#include "UserOutput.h"
#include "I_UserOutput.h"
#include "I_UserOutput_Config.h"
#include "I_LCD_Text.h"

static void UserOutput_open(UserOutput* const ptrUserOutput, const UserOutput* const ptrUserOutputConfig);
static void UserOutput_close(UserOutput* const ptrUserOutput);
static void UserOutput_clear(UserOutput* const ptrUserOutput);
static void UserOutput_writeCharacterXY(UserOutput* const ptrUserOutput, uint32_t posX, uint32_t posY, char characterValue);
static void UserOutput_writeStringXY(UserOutput* const ptrUserOutput, uint32_t posX, uint32_t posY, char* stringValue);
static void UserOutput_writeBargraphXY(UserOutput* const ptrUserOutput, uint32_t posX, uint32_t posY, uint32_t valuePercent, uint32_t sizeMaxSegments);

void I_UserOutput_open(void* const ptrUserOutput, const void* const ptrUserOutputConfig)
{
	if ( (ptrUserOutput != nullptr) && (ptrUserOutputConfig != nullptr) )
	{
		UserOutput_open((UserOutput*)ptrUserOutput, (UserOutput*)ptrUserOutputConfig);
	}
	else
	{
		//nothing to do
	}
}

void I_UserOutput_close(void* const ptrUserOutput)
{
	if (ptrUserOutput != nullptr)
	{
		UserOutput_close((UserOutput*)ptrUserOutput);
	}
	else
	{
		//nothing to do
	}
}

void I_UserOutput_clear(void* const ptrUserOutput)
{
	if (ptrUserOutput != nullptr)
	{
		UserOutput_clear((UserOutput*)ptrUserOutput);
	}
	else
	{
		//nothing to do
	}
}

void I_UserOutput_writeCharacterXY(void* const ptrUserOutput, uint32_t posX, uint32_t posY, char characterValue)
{
	if (ptrUserOutput != nullptr)
	{
		UserOutput_writeCharacterXY((UserOutput*)ptrUserOutput, posX, posY, characterValue);
	}
	else
	{
		//nothing to do
	}
}

void I_UserOutput_writeStringXY(void* const ptrUserOutput, uint32_t posX, uint32_t posY, char* stringValue)
{
	if (ptrUserOutput != nullptr)
	{
		UserOutput_writeStringXY((UserOutput*)ptrUserOutput, posX, posY, stringValue);
	}
	else
	{
		//nothing to do
	}
}

void I_UserOutput_writeBargraphXY(void* const ptrUserOutput, uint32_t posX, uint32_t posY, uint32_t value, uint32_t size)
{
	if (ptrUserOutput != nullptr)
	{
		UserOutput_writeBargraphXY((UserOutput*)ptrUserOutput, posX, posY, value, size);
	}
	else
	{
		//nothing to do
	}
}

static void UserOutput_open(UserOutput* const ptrUserOutput, const UserOutput* const ptrUserOutputConfig)
{
	if ( (ptrUserOutput != nullptr) && (ptrUserOutputConfig != nullptr) )
	{
		ptrUserOutput->mptrUserOutputDevice = ptrUserOutputConfig->mptrUserOutputDevice;
		ptrUserOutput->mMaxX                = ptrUserOutputConfig->mMaxX;
		ptrUserOutput->mMaxY                = ptrUserOutputConfig->mMaxY;
	}
	else
	{
		// nothing to do
	}
}

static void UserOutput_close(UserOutput* const ptrUserOutput)
{
	if (ptrUserOutput != nullptr)
	{
		ptrUserOutput->mptrUserOutputDevice = nullptr;
	}
	else
	{
		//nothing to do
	}
}

static void UserOutput_clear(UserOutput* const ptrUserOutput)
{
	if (ptrUserOutput != nullptr)
	{
		I_LCD_Text_clear(ptrUserOutput->mptrUserOutputDevice);
	}
	else
	{
		//nothing to do
	}
}

static void UserOutput_writeCharacterXY(UserOutput* const ptrUserOutput, uint32_t posX, uint32_t posY, char characterValue)
{
	if (ptrUserOutput != nullptr)
	{
		I_LCD_Text_setCursor(ptrUserOutput->mptrUserOutputDevice, posX, posY);
		I_LCD_Text_writeCharacter(ptrUserOutput->mptrUserOutputDevice, characterValue);
	}
	else
	{
		//nothing to do
	}
}

static void UserOutput_writeStringXY(UserOutput* const ptrUserOutput, uint32_t posX, uint32_t posY, char* stringValue)
{
	if ( (ptrUserOutput != nullptr) && (stringValue != nullptr) )
	{
		I_LCD_Text_setCursor(ptrUserOutput->mptrUserOutputDevice, posX, posY);
		while (*stringValue)
		{
			I_LCD_Text_writeCharacter(ptrUserOutput->mptrUserOutputDevice, *stringValue++);
		}
	}
	else
	{
		//nothing to do
	}
}

static void UserOutput_writeBargraphXY(UserOutput* const ptrUserOutput, uint32_t posX, uint32_t posY, uint32_t valuePercent, uint32_t maxSegmentCount)
{
	if (ptrUserOutput != nullptr)
	{
		I_LCD_Text_setCursor(ptrUserOutput->mptrUserOutputDevice, posX, posY);
		I_LCD_Text_writeBargraph(ptrUserOutput->mptrUserOutputDevice, valuePercent, maxSegmentCount);
	}
	else
	{
		//nothing to do
	}
}
