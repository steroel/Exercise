#include "cLimitCounter.hpp"

namespace Counter
{
	cLimitCounter::cLimitCounter(const uint32_t CountValue, const uint32_t CountLimit):
		mCountValue(CountValue),
		mCountLimit(CountLimit)
	{
		// no implementation
	}
			
	void cLimitCounter::setCountValue(const uint32_t CountValue)
	{
		mCountValue = CountValue;
	}

	uint32_t cLimitCounter::getCountValue(void) const
	{
		return mCountValue;
	}
	
	uint32_t cLimitCounter::getCountLimit(void) const
	{
		return mCountLimit;
	}

	void cLimitCounter::resetCountValue(void)
	{
		mCountValue = 0;
	}

	void cLimitCounter::count(void)
	{
		if(mCountValue <= mCountLimit)
		{
			mCountValue = mCountValue + 1;
		}

		if(mCountValue == mCountLimit)
		{
			mCountValue = 0;
		}
	}
}
