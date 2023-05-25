#ifndef __cAnalogClock_HPP__
#define __cAnalogClock_HPP__

#include "cClock.hpp"

namespace Clock
{
	class cAnalogClock : public cClock
	//class cAnalogClock : virtual public cClock
	{
		public:
			explicit cAnalogClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second);
			~cAnalogClock() override =default;

			void show(void) const override;
	};
}

#endif // __cAnalogClock_HPP__
