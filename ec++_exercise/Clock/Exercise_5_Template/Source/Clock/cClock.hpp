#ifndef __cClock_HPP__
#define __cClock_HPP__

#include "icClock.hpp"
#include "../Counter/cLimitCounter.hpp"
#include "../Counter/cOverflowCounter.hpp"

//using namespace Counter;
using Counter::cLimitCounter;
using Counter::cOverflowCounter;

namespace Clock
{
	class cClock : public icClock
	{
		public:
			cClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second);
			~cClock() override =default;

			uint32_t getHour(void) const override;
			uint32_t getMinute(void) const override;
			uint32_t getSecond(void) const override;

			void reset(void) override;			
			void update(void) override;
		
			cClock& operator++(void); // prefix
			cClock  operator++(int); 	// postfix
		
	//	  cClock& operator=(const cClock& refClock)
	//		{
	//			*this = const_cast<cClock&>(refClock);
	//			return *this;
	//		}
				
			void setHour(const uint32_t Hour);
			void setMinute(const uint32_t Minute);
			void setSecond(const uint32_t Second);
				
		private:
			cLimitCounter mHour;
			cOverflowCounter mMinute;
			cOverflowCounter mSecond;
	};
}

#endif //__cClock_HPP__
