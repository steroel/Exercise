#include "UserIndication.h"
#include "I_UserIndication.h"
#include "I_UserIndication_Config.h"
#include "I_LED.h"

static void UserIndication_open(UserIndication* const ptrUserIndication, const UserIndication* const ptrUserIndicationConfig);
static void UserIndication_close(UserIndication* const ptrUserIndication);
static void UserIndication_set(UserIndication* const ptrUserIndication);
static void UserIndication_clear(UserIndication* const ptrUserIndication);

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
