#include "cDigitalClock.hpp"

#include "../Platform/Hardware_Abstraction/iBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

#include <typeinfo>


namespace Clock
{
	cDigitalClock::cDigitalClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second):
		cClock{ Hour, Minute, Second }
	{
		// no implementation
	}
		
	void cDigitalClock::show(void) const
	{
		showValue("\nDigital        Clock ");
		showValue(typeid(this).name(), " ");
		cClock::show();
	}
}
