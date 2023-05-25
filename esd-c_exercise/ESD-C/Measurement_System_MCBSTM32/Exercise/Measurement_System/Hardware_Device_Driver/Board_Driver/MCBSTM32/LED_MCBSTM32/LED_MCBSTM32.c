#include "LED_MCBSTM32.h"
#include "I_LED_Config.h"
#include "I_LED.h"
#include "I_GPIO.h"

//static void LED_MCBSTM32_open(LED_MCBSTM32* ptrLED_MCBSTM32, const LED_MCBSTM32* const ptrLED_Config);
//static void LED_MCBSTM32_close(LED_MCBSTM32* const ptrLED);
//static void LED_MCBSTM32_setOn(LED_MCBSTM32* const ptrLED);
//static void LED_MCBSTM32_setOff(LED_MCBSTM32* const ptrLED);
//static void LED_MCBSTM32_toggle(LED_MCBSTM32* const ptrLED);

void I_LED_open(void* const ptrLED, const void* const ptrLED_Config)
{
	//**
}

void I_LED_close(void* const ptrLED)
{
	//**
}

void I_LED_setOn(void* const ptrLED)
{
	//**
}

void I_LED_setOff(void* const ptrLED)
{
	//**
}

void I_LED_toggle(void* const ptrLED)
{
	//**
}

static void LED_MCBSTM32_open(LED_MCBSTM32* ptrLED_MCBSTM32, const LED_MCBSTM32* const ptrLED_MCBSTM32_Config)
{
	if ( (ptrLED_MCBSTM32 != nullptr) && (ptrLED_MCBSTM32_Config != nullptr) )
	{
		//**
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
		//**
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
			//** output driver access
		}
		else if (ptrLED_MCBSTM32->mActivity == LowActiveLED)
		{
			//** output driver access
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
			//** output driver access
		}
		else if (ptrLED_MCBSTM32->mActivity == LowActiveLED)
		{
			//** output driver access
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
		//** output driver access
		if (locPortValue == 0)
		{
			//** output driver access
		}
		else if (locPortValue == 1)
		{
			//** output driver access
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
