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
	//class cClock : public icObserver
	{
		public:
			explicit cClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second);
			virtual ~cClock() =default;

			void setHour(const uint32_t Hour);
			void setMinute(const uint32_t Minute);
			void setSecond(const uint32_t Second);

			void reset(void);

			uint32_t getHour(void) const;
			uint32_t getMinute(void) const;
			uint32_t getSecond(void) const;
			
			virtual void update(void);
			virtual void show(void) const;
			
		private:
			cLimitCounter    mHour;
			cOverflowCounter mMinute;
			cOverflowCounter mSecond;

	};
}

#endif // __cClock_HPP__
