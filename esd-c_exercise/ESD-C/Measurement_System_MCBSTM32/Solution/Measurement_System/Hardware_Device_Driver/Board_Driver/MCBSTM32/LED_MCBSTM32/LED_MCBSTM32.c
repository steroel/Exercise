#include "LED_MCBSTM32.h"
#include "I_LED_Config.h"
#include "I_LED.h"
#include "I_GPIO.h"

static void LED_MCBSTM32_open(LED_MCBSTM32* ptrLED_MCBSTM32, const LED_MCBSTM32* const ptrLED_Config);
static void LED_MCBSTM32_close(LED_MCBSTM32* const ptrLED);
static void LED_MCBSTM32_setOn(LED_MCBSTM32* const ptrLED);
static void LED_MCBSTM32_setOff(LED_MCBSTM32* const ptrLED);
static void LED_MCBSTM32_toggle(LED_MCBSTM32* const ptrLED);

void I_LED_open(void* const ptrLED, const void* const ptrLED_Config)
{
	if ( (ptrLED != nullptr) && (ptrLED_Config != nullptr) )
	{
		LED_MCBSTM32_open((LED_MCBSTM32*) ptrLED, (LED_MCBSTM32*) ptrLED_Config);
	}
	else
	{
		// nothing to do
	}
}

void I_LED_close(void* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		LED_MCBSTM32_close((LED_MCBSTM32*) ptrLED);
	}
	else
	{
		// nothing to do
	}
}

void I_LED_setOn(void* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		LED_MCBSTM32_setOn((LED_MCBSTM32*) ptrLED);
	}
	else
	{
		// nothing to do
	}
}

void I_LED_setOff(void* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		LED_MCBSTM32_setOff((LED_MCBSTM32*) ptrLED);
	}
	else
	{
		// nothing to do
	}
}

void I_LED_toggle(void* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		LED_MCBSTM32_toggle((LED_MCBSTM32*) ptrLED);
	}
	else
	{
		// nothing to do
	}
}

static void LED_MCBSTM32_open(LED_MCBSTM32* ptrLED_MCBSTM32, const LED_MCBSTM32* const ptrLED_MCBSTM32_Config)
{
	if ( (ptrLED_MCBSTM32 != nullptr) && (ptrLED_MCBSTM32_Config != nullptr) )
	{
		ptrLED_MCBSTM32->mptrOutPort = ptrLED_MCBSTM32_Config->mptrOutPort;
		ptrLED_MCBSTM32->mActivity   = ptrLED_MCBSTM32_Config->mActivity;
		
		LED_MCBSTM32_setOff(ptrLED_MCBSTM32);
	}
	else
	{
		// nothing to do
	}
}

static void LED_MCBSTM32_close(LED_MCBSTM32* const ptrLED_MCBSTM32)
{
	if (ptrLED_MCBSTM32 != nullptr)
	{
		ptrLED_MCBSTM32->mptrOutPort =  nullptr;
	}
	else
	{
		// nothing to do
	}
}

static void LED_MCBSTM32_setOn(LED_MCBSTM32* const ptrLED_MCBSTM32)
{
	if (ptrLED_MCBSTM32 != nullptr)
	{
		if (ptrLED_MCBSTM32->mActivity == HighActiveLED)
		{
			I_GPIO_write(ptrLED_MCBSTM32->mptrOutPort, 1);
		}
		else if (ptrLED_MCBSTM32->mActivity == LowActiveLED)
		{
			I_GPIO_write(ptrLED_MCBSTM32->mptrOutPort, 0);
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

static void LED_MCBSTM32_setOff(LED_MCBSTM32* const ptrLED_MCBSTM32)
{
	if (ptrLED_MCBSTM32 != nullptr)
	{
		if (ptrLED_MCBSTM32->mActivity == HighActiveLED)
		{
			I_GPIO_write(ptrLED_MCBSTM32->mptrOutPort, 0);
		}
		else if (ptrLED_MCBSTM32->mActivity == LowActiveLED)
		{
			I_GPIO_write(ptrLED_MCBSTM32->mptrOutPort, 1);
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

static void LED_MCBSTM32_toggle(LED_MCBSTM32* const ptrLED_MCBSTM32)
{
	uint32_t locPortValue = 0;
	
	if (ptrLED_MCBSTM32 != nullptr)
	{
		I_GPIO_read(ptrLED_MCBSTM32->mptrOutPort, &locPortValue);
		if (locPortValue == 0)
		{
			I_GPIO_write(ptrLED_MCBSTM32->mptrOutPort, 1);
		}
		else if (locPortValue == 1)
		{
			I_GPIO_write(ptrLED_MCBSTM32->mptrOutPort, 0);
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
