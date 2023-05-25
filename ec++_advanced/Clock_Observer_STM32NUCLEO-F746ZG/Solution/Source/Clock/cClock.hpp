#ifndef __cClock_HPP__
#define __cClock_HPP__

#include "../Common/icObserver.hpp"
using Common::icObserver;

#include "../Counter/cLimitCounter.hpp"
#include "../Counter/cOverflowCounter.hpp"
using namespace Counter;

namespace Clock
{
	class cClock : virtual public icObserver
	{
		public:
			explicit cClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second);
			~cClock() override =default;

			void setHour(const uint32_t Hour);
			void setMinute(const uint32_t Minute);
			void setSecond(const uint32_t Second);

			void reset(void);

			uint32_t getHour(void) const;
			uint32_t getMinute(void) const;
			uint32_t getSecond(void) const;
			
			void update(void) override;
			void show(void) const override;
			
		private:
			cLimitCounter    mHour;
			cOverflowCounter mMinute;
			cOverflowCounter mSecond;
	};
}

#endif // __cClock_HPP__
