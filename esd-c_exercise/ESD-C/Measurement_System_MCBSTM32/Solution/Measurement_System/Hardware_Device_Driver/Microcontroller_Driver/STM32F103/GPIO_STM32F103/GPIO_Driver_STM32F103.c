#include "GPIO_Driver_STM32F103.h"
#include "I_GPIO.h"
#include "I_GPIO_Config.h"

static void GPIO_STM32F103_open(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103,
                                const GPIO_Driver_STM32F103* const ptrGPIO_Config_STM32F103 );                     
static void GPIO_STM32F103_close(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103);

static void GPIO_STM32F103_read(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103, uint32_t* const ptrDestination);
static void GPIO_STM32F103_write(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103, uint32_t portValue);
static void GPIO_STM32F103_setDirection(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103, I_GPIO_Direction_t direction);

void I_GPIO_open(void* const ptrGPIO_Driver, const void* const ptrGPIO_Config)
{
	if ( (ptrGPIO_Driver != nullptr) && (ptrGPIO_Config != nullptr) )
	{
	GPIO_STM32F103_open((GPIO_Driver_STM32F103*)ptrGPIO_Driver,  
                      (GPIO_Driver_STM32F103*)ptrGPIO_Config );
	}
	else
	{
		// nothing to do
	}
}

void I_GPIO_close(void* const ptrGPIO_Driver)
{
	if (ptrGPIO_Driver != nullptr)
	{
		GPIO_STM32F103_close((GPIO_Driver_STM32F103*)ptrGPIO_Driver);
	}
	else
	{
		// nothing to do
	}
}

void I_GPIO_read(void* const ptrGPIO_Driver, port_t* const ptrDestination)
{
	if ( (ptrGPIO_Driver != nullptr) && (ptrDestination != nullptr) )
	{
		GPIO_STM32F103_read((GPIO_Driver_STM32F103*) ptrGPIO_Driver, ptrDestination);
	}
	else
	{
		// nothing to do
	}
}

void I_GPIO_write(void* const ptrGPIO_Driver, port_t bitFieldValue)
{
	if (ptrGPIO_Driver != nullptr)
	{
		GPIO_STM32F103_write((GPIO_Driver_STM32F103*) ptrGPIO_Driver, bitFieldValue);
	}
	else
	{
		// nothing to do
	}
}

void I_GPIO_setDirection(void* const ptrGPIO_Driver, I_GPIO_Direction_t direction)
{
	if (ptrGPIO_Driver != nullptr)
	{
		GPIO_STM32F103_setDirection((GPIO_Driver_STM32F103*) ptrGPIO_Driver, direction);
	}
	else
	{
		// nothing to do
	}
}

static void GPIO_STM32F103_open(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103,
                                const GPIO_Driver_STM32F103* const ptrGPIO_Config_STM32F103 )
{
	const uint32_t locConfiguration_CNF_MODE_BitFieldMask  = 0xF;
	uint32_t       locConfiguration_CNF_MODE_BitFieldValue = 0;
	
	uint32_t locRegisterMaskLow   = 0x00000000;
	uint32_t locRegisterMaskHigh  = 0x00000000;
	uint32_t locRegisterValueLow  = 0x00000000;
	uint32_t locRegisterValueHigh = 0x00000000;
	uint32_t locRegisterValue     = 0x00000000;
	uint32_t locLoopCounter = 0;
		
	if ( (ptrGPIO_Driver_STM32F103 != nullptr) && (ptrGPIO_Config_STM32F103 != nullptr) )
	{
		ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103 = ptrGPIO_Config_STM32F103->mptrGPIO_Register_STM32F103;
		ptrGPIO_Driver_STM32F103->mMode                       = ptrGPIO_Config_STM32F103->mMode;
		ptrGPIO_Driver_STM32F103->mModeBackup                 = ptrGPIO_Config_STM32F103->mModeBackup;
		ptrGPIO_Driver_STM32F103->mOutputMode                 = ptrGPIO_Config_STM32F103->mOutputMode;
		ptrGPIO_Driver_STM32F103->mInputMode                  = ptrGPIO_Config_STM32F103->mInputMode;
		ptrGPIO_Driver_STM32F103->mBitPositionMSB             = ptrGPIO_Config_STM32F103->mBitPositionMSB;
		ptrGPIO_Driver_STM32F103->mBitPositionLSB             = ptrGPIO_Config_STM32F103->mBitPositionLSB;
		
		ptrGPIO_Driver_STM32F103->mBitFieldSize = ptrGPIO_Config_STM32F103->mBitPositionMSB - ptrGPIO_Config_STM32F103->mBitPositionLSB + 1;
		
		ptrGPIO_Driver_STM32F103->mBitFieldMask = 1;
		for(locLoopCounter = 0; locLoopCounter < ptrGPIO_Driver_STM32F103->mBitFieldSize-1; locLoopCounter++)
		{
			ptrGPIO_Driver_STM32F103->mBitFieldMask = ptrGPIO_Driver_STM32F103->mBitFieldMask << 1;
			ptrGPIO_Driver_STM32F103->mBitFieldMask = ptrGPIO_Driver_STM32F103->mBitFieldMask + 1;
		}
		ptrGPIO_Driver_STM32F103->mBitFieldMask = ptrGPIO_Driver_STM32F103->mBitFieldMask << ptrGPIO_Config_STM32F103->mBitPositionLSB;
		
		
		if (ptrGPIO_Driver_STM32F103->mMode == GPIO_Input)
		{
			locConfiguration_CNF_MODE_BitFieldValue = (ptrGPIO_Driver_STM32F103->mInputMode << 2) + ptrGPIO_Driver_STM32F103->mMode;
		}
		else if (ptrGPIO_Driver_STM32F103->mMode == (GPIO_Output_10MHz | GPIO_Output_2MHz | GPIO_Output_50MHz))
		{
			locConfiguration_CNF_MODE_BitFieldValue = (ptrGPIO_Driver_STM32F103->mOutputMode << 2) + ptrGPIO_Driver_STM32F103->mMode;
		}
		else
		{
				// nothing to do
		}
		
		if ( (ptrGPIO_Driver_STM32F103->mBitPositionMSB <= 15) && (ptrGPIO_Driver_STM32F103->mBitPositionLSB >= 8) )
		{
			for (locLoopCounter = ptrGPIO_Driver_STM32F103->mBitPositionLSB;
					 locLoopCounter <= ptrGPIO_Driver_STM32F103->mBitPositionMSB;
					 locLoopCounter++)
			{
				locRegisterMaskHigh  = locRegisterMaskHigh  + (locConfiguration_CNF_MODE_BitFieldMask  << ((4 * locLoopCounter) - 32));	// configure mask
				locRegisterValueHigh = locRegisterValueHigh + (locConfiguration_CNF_MODE_BitFieldValue << ((4 * locLoopCounter) - 32));	// configure value
			}
			GPIO_Register_STM32F103_readCRH(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, &locRegisterValue);	// read bits
			locRegisterValue = locRegisterValue & ~locRegisterMaskHigh;																									// reset masked bits
			locRegisterValue = locRegisterValue | locRegisterValueHigh;																									// set masked bits
			GPIO_Register_STM32F103_writeCRH(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, locRegisterValue);	// write bits
		}
		else if (ptrGPIO_Driver_STM32F103->mBitPositionMSB <= 7)
		{
			for (locLoopCounter = ptrGPIO_Driver_STM32F103->mBitPositionLSB;
					 locLoopCounter <= ptrGPIO_Driver_STM32F103->mBitPositionMSB;
					 locLoopCounter++)
			{
				locRegisterMaskLow  = locRegisterMaskLow  + (locConfiguration_CNF_MODE_BitFieldMask  << (4 * locLoopCounter));  // configure mask
				locRegisterValueLow = locRegisterValueLow + (locConfiguration_CNF_MODE_BitFieldValue << (4 * locLoopCounter));	// configure value
			}
			GPIO_Register_STM32F103_readCRL(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, &locRegisterValue);	// read bits
			locRegisterValue = locRegisterValue & ~locRegisterMaskLow;																									// reset masked bits
			locRegisterValue = locRegisterValue | locRegisterValueLow;																									// set masked bits
			GPIO_Register_STM32F103_writeCRL(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, locRegisterValue);	// write bits
		}
		else
		{
			// nothing to do
		}
	}
	else
	{
		// nothing to do
	}
}

static void GPIO_STM32F103_close(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103)
{
	if (ptrGPIO_Driver_STM32F103 != nullptr)
	{
		ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103 = nullptr;
	}
	else
	{
		// nothing to do
	}
}

static void GPIO_STM32F103_read(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103, uint32_t* ptrDestination)
{
	uint32_t locRegisterValue = 0;

	if ( (ptrGPIO_Driver_STM32F103 != nullptr) && (ptrDestination != nullptr) )
	{
		GPIO_Register_STM32F103_readIDR(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, &locRegisterValue); 	// read complete register bits
		locRegisterValue = locRegisterValue & ptrGPIO_Driver_STM32F103->mBitFieldMask;															// mask the relevant bits
		locRegisterValue = locRegisterValue >> ptrGPIO_Driver_STM32F103->mBitPositionLSB;														// shift the relevant bits to the right
		
		*ptrDestination = locRegisterValue;		// write to destination
	}
	else
	{
		// nothing to do
	}
}

static void GPIO_STM32F103_write(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103, uint32_t bitFieldValue)
{
	uint32_t locRegisterValue = 0;
	
	if (ptrGPIO_Driver_STM32F103 != nullptr)
	{
		// read
		GPIO_Register_STM32F103_readODR(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, &locRegisterValue);
		// modify
		locRegisterValue = locRegisterValue & ~ptrGPIO_Driver_STM32F103->mBitFieldMask;											// reset masked bits
		locRegisterValue = locRegisterValue | (bitFieldValue << ptrGPIO_Driver_STM32F103->mBitPositionLSB);	// set masked bits
		// write
		GPIO_Register_STM32F103_writeODR(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, locRegisterValue);
	}
	else
	{
		// nothing to do
	}
}

static void GPIO_STM32F103_setDirection(GPIO_Driver_STM32F103* const ptrGPIO_Driver_STM32F103, I_GPIO_Direction_t direction)
{
	const uint32_t loc_CNF_MODE_BitFieldMask = 0xF;
	uint32_t loc_MODE_BitFieldValue = 0;
	uint32_t loc_CNF_BitFieldValue  = 0;
	uint32_t loc_CNF_MODE_BitFieldValue = 0;
	uint32_t locRegisterMaskLow   = 0x00000000;
	uint32_t locRegisterMaskHigh  = 0x00000000;
	uint32_t locRegisterValueLow  = 0x00000000;
	uint32_t locRegisterValueHigh = 0x00000000;
	uint32_t locRegisterValue     = 0x00000000;
	uint32_t locLoopCounter = 0;
	
  if (ptrGPIO_Driver_STM32F103 != nullptr)
	{
		switch(direction)
		{
			case Input:
				loc_MODE_BitFieldValue = ptrGPIO_Driver_STM32F103->mMode = GPIO_Input;		//read input mode
				loc_CNF_BitFieldValue = ptrGPIO_Driver_STM32F103->mInputMode; 	//read input configuration
				loc_CNF_MODE_BitFieldValue = (loc_CNF_BitFieldValue << 2) + loc_MODE_BitFieldValue;
			break;
			
			case Output:
				loc_MODE_BitFieldValue = ptrGPIO_Driver_STM32F103->mMode = ptrGPIO_Driver_STM32F103->mModeBackup; //read output mode
				loc_CNF_BitFieldValue = ptrGPIO_Driver_STM32F103->mOutputMode;                        	//read output configuration
				loc_CNF_MODE_BitFieldValue = (loc_CNF_BitFieldValue << 2) + loc_MODE_BitFieldValue;
			break;
			
			default:
			break;
		}
		
		if ( (ptrGPIO_Driver_STM32F103->mBitPositionMSB <= 15) && (ptrGPIO_Driver_STM32F103->mBitPositionLSB >= 8) )
		{
			for (locLoopCounter = ptrGPIO_Driver_STM32F103->mBitPositionLSB;
					 locLoopCounter <= ptrGPIO_Driver_STM32F103->mBitPositionMSB;
					 locLoopCounter++)
			{
				locRegisterMaskHigh  = locRegisterMaskHigh  + (loc_CNF_MODE_BitFieldMask  << ((4 * locLoopCounter) - 32));	// configure mask
				locRegisterValueHigh = locRegisterValueHigh + (loc_CNF_MODE_BitFieldValue << ((4 * locLoopCounter) - 32));	// configure value
			}
			GPIO_Register_STM32F103_readCRH(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, &locRegisterValue);	// read bits
			locRegisterValue = locRegisterValue & ~locRegisterMaskHigh;																									// reset masked bits
			locRegisterValue = locRegisterValue | locRegisterValueHigh;																									// set masked bits
			GPIO_Register_STM32F103_writeCRH(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, locRegisterValue);	// write bits
		}
		else if (ptrGPIO_Driver_STM32F103->mBitPositionMSB <= 7)
		{
			for (locLoopCounter = ptrGPIO_Driver_STM32F103->mBitPositionLSB;
					 locLoopCounter <= ptrGPIO_Driver_STM32F103->mBitPositionMSB;
					 locLoopCounter++)
			{
				locRegisterMaskLow  = locRegisterMaskLow  + (loc_CNF_MODE_BitFieldMask  << (4 * locLoopCounter));  // configure mask
				locRegisterValueLow = locRegisterValueLow + (loc_CNF_MODE_BitFieldValue << (4 * locLoopCounter));	// configure value
			}
			GPIO_Register_STM32F103_readCRL(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, &locRegisterValue);	// read bits
			locRegisterValue = locRegisterValue & ~locRegisterMaskLow;																									// reset masked bits
			locRegisterValue = locRegisterValue | locRegisterValueLow;																									// set masked bits
			GPIO_Register_STM32F103_writeCRL(ptrGPIO_Driver_STM32F103->mptrGPIO_Register_STM32F103, locRegisterValue);	// write bits
		}
		else
		{
			// nothing to do
		}
	}
	else
	{
		// nothing to do
	}
}
