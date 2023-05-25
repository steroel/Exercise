#ifndef __cAnalogDigitalClock_HPP__
#define __cAnalogDigitalClock_HPP__

#include "cAnalogClock.hpp"
#include "cDigitalClock.hpp"

namespace Clock
{
	class cAnalogDigitalClock final: public cAnalogClock,
	                                 public cDigitalClock
	{
		public:
			explicit cAnalogDigitalClock(const uint32_t HourAnalog,  const uint32_t MinuteAnalog,  const uint32_t SecondAnalog,
								         const uint32_t HourDigital, const uint32_t MinuteDigital, const uint32_t SecondDigital);
			//explicit cAnalogDigitalClock(const uint32_t Hour,  const uint32_t Minute,  const uint32_t Second);
			~cAnalogDigitalClock() override final =default;

			void update(void) override; //final;
			void show(void) const override; //final;
	};
}

#endif // __cAnalogDigitalClock_HPP__
