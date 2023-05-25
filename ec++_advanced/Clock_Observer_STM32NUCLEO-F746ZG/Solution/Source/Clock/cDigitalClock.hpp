#ifndef __cDigitalClock_HPP__
#define __cDigitalClock_HPP__

#include "cClock.hpp"

namespace Clock
{
	class cDigitalClock : public cClock
	{
		public:
			explicit cDigitalClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second);
			~cDigitalClock() override =default;

			void show(void) const override;
	};
}

#endif // __cDigitalClock_HPP__
