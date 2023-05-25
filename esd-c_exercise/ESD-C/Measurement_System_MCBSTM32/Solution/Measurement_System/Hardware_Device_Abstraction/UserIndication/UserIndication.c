#include "UserIndication.h"
#include "I_UserIndication.h"
#include "I_UserIndication_Config.h"
#include "I_LED.h"

static void UserIndication_open(UserIndication* const ptrUserIndication, const UserIndication* const ptrUserIndicationConfig);
static void UserIndication_close(UserIndication* const ptrUserIndication);
static void UserIndication_set(UserIndication* const ptrUserIndication);
static void UserIndication_clear(UserIndication* const ptrUserIndication);
static void UserIndication_alternate(UserIndication* const ptrUserIndication, uint32_t frequency_Hz);

void I_UserIndication_open(void* const ptrUserIndication, const void* const ptrUserIndicationConfig)
{
	if ( (ptrUserIndication != nullptr) && (ptrUserIndicationConfig != nullptr) )
	{
		UserIndication_open((UserIndication*) ptrUserIndication, (UserIndication*) ptrUserIndicationConfig);
		}
	else
	{
		// nothing to do
	}
}
void I_UserIndication_close(void* const ptrUserIndication)
{
	if (ptrUserIndication != nullptr)
	{
		UserIndication_close((UserIndication*) ptrUserIndication);
	}
	else
	{
		// nothing to do
	}
}
void I_UserIndication_set(void* const ptrUserIndication)
{
	if (ptrUserIndication != nullptr)
	{
		UserIndication_set((UserIndication*) ptrUserIndication);
	}
	else
	{
		// nothing to do
	}
}
void I_UserIndication_clear(void* const ptrUserIndication)
{
	if (ptrUserIndication != nullptr)
	{
		UserIndication_clear((UserIndication*) ptrUserIndication);
	}
	else
	{
		// nothing to do
	}
}
void I_UserIndication_alternate(void* const ptrUserIndication, uint32_t frequency_Hz)
{
	if (ptrUserIndication != nullptr)
	{
		UserIndication_alternate((UserIndication*) ptrUserIndication, frequency_Hz);
	}
	else
	{
		// nothing to do
	}
}

static void UserIndication_open(UserIndication* const ptrUserIndication, const UserIndication* const ptrUserIndicationConfig)
{
	if ( (ptrUserIndication != nullptr) && (ptrUserIndicationConfig != nullptr) )
	{
		ptrUserIndication->mptrUserIndicationDevice = ptrUserIndicationConfig->mptrUserIndicationDevice;
	}
	else
	{
		// nothing to do
	}
}

static void UserIndication_close(UserIndication* const ptrUserIndication)
{
	if (ptrUserIndication != nullptr)
	{
		ptrUserIndication->mptrUserIndicationDevice = nullptr;
	}
	else
	{
		// nothing to do
	}
}

static void UserIndication_set(UserIndication* const ptrUserIndication)
{
	if (ptrUserIndication != nullptr)
	{
		I_LED_setOn(ptrUserIndication->mptrUserIndicationDevice);
	}
	else
	{
		// nothing to do
	}
}

static void UserIndication_clear(UserIndication* const ptrUserIndication)
{
	if (ptrUserIndication != nullptr)
	{
		I_LED_setOff(ptrUserIndication->mptrUserIndicationDevice);
	}
	else
	{
		// nothing to do
	}
}

static void UserIndication_alternate(UserIndication* const ptrUserIndication, uint32_t frequency_Hz)
{
	if (ptrUserIndication != nullptr)
	{
		if (frequency_Hz == 0)
		{
			I_LED_toggle(ptrUserIndication->mptrUserIndicationDevice);
		}
		else 
		{
			// for future use, timer required
		}
	}
	else
	{
		// nothing to do
	}
}
