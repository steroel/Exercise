#include "cAnalogDigitalClock.hpp"

#include "../Platform/Hardware_Abstraction/iBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

#include <typeinfo>

namespace Clock
{
	cAnalogDigitalClock::cAnalogDigitalClock(const uint32_t HourAnalog,  const uint32_t MinuteAnalog,  const uint32_t SecondAnalog,
								             const uint32_t HourDigital, const uint32_t MinuteDigital, const uint32_t SecondDigital) :
	  cAnalogClock{  HourAnalog,  MinuteAnalog,  SecondAnalog },
	  cDigitalClock{ HourDigital, MinuteDigital, SecondDigital }
	{
		// no implementation
	}			

	void cAnalogDigitalClock::update(void)
	{
		cAnalogClock::update();
		cDigitalClock::update();
	}
	
	void cAnalogDigitalClock::show(void) const
	{
		showValue("\nAnalog Digital Clock ");
		showValue(typeid(this).name(), " ");
		cAnalogClock::show();
		cDigitalClock::show();
	}
}
