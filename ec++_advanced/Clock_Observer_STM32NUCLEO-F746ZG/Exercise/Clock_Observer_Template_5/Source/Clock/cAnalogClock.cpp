#include "cAnalogClock.hpp"

#include "../Platform/Hardware_Abstraction/iBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

#include <typeinfo>

namespace Clock
{
	cAnalogClock::cAnalogClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second) :
		cClock{ Hour, Minute, Second }
	{
		// no implementation
	}

	void cAnalogClock::show(void) const
	{
		showValue("\nAnalog         Clock ");
		showValue(typeid(this).name(), "  ");
		cClock::show();
	}
}
