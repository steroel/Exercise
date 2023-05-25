#include "cAnalogDigitalClock.hpp"

#include "../Platform/Hardware_Abstraction/iBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;


namespace Clock
{
	cAnalogDigitalClock::cAnalogDigitalClock(const uint32_t HourAnalog,  const uint32_t MinuteAnalog,  const uint32_t SecondAnalog,
						   		             const uint32_t HourDigital, const uint32_t MinuteDigital, const uint32_t SecondDigital) :
	  cAnalogClock{ HourAnalog,  MinuteAnalog,  SecondAnalog },
	  cDigitalClock{ HourDigital, MinuteDigital, SecondDigital }
	//cAnalogDigitalClock::cAnalogDigitalClock(const uint32_t Hour,  const uint32_t Minute,  const uint32_t Second) :
	//	cClock{ Hour, Minute, Second },
	// 	cAnalogClock{ Hour, Minute, Second },
	// 	cDigitalClock{ Hour, Minute, Second }
	{
		// no implementation
	}

	void cAnalogDigitalClock::update(void)
	{
		cAnalogClock::update();
		cDigitalClock::update();
		//cClock::update();
	}

	void cAnalogDigitalClock::show(void) const
	{
		showValue("\nAnalog Digital Clock ");
		cAnalogClock::show();
		cDigitalClock::show();
	}
}
