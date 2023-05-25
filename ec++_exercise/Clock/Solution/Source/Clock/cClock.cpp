#include "cClock.hpp"

namespace Clock
{
	cClock::cClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second) :
			 mHour{ Hour, 24 },
			 mMinute{ Minute, 60, mHour },
			 mSecond{ Second, 60, mMinute}
	{
		// no implementation
	}

	void cClock::setHour(const uint32_t Hour)
	{
		mHour.setCountValue(Hour);
	}

	void cClock::setMinute(const uint32_t Minute)
	{
		mMinute.setCountValue(Minute);
	}

	void cClock::setSecond(const uint32_t Second)
	{
		mSecond.setCountValue(Second);
	}

	void cClock::reset(void)
	{
		mSecond.resetCountValue();
	}

	uint32_t cClock::getHour(void) const
	{
		return mHour.getCountValue();
	}

	uint32_t cClock::getMinute(void) const
	{
		return(mMinute.getCountValue());
	}

	uint32_t cClock::getSecond(void) const
	{
		return mSecond.getCountValue();
	}

	void cClock::update(void)
	{
		mSecond.count();
	}

	cClock& cClock::operator++(void)	//pre-increment
	{
		uint32_t locSeconds = mSecond.getCountValue();
		++locSeconds;
		mSecond.setCountValue(locSeconds);
		
		return *this;
	}

	cClock cClock::operator++(int)	//post-increment
	{
		cClock locClock = *this;
		uint32_t locSeconds = this->getSecond();
		
		locSeconds++;
		this->setSecond(locSeconds);
		
		return locClock;
	}
}