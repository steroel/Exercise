#include "cOverflowCounter.hpp"

namespace Counter
{
	cOverflowCounter::cOverflowCounter(const uint32_t CountValue, const uint32_t CountLimit, cLimitCounter& refNextCounter) :
	  cLimitCounter{ CountValue, CountLimit },
	  mrefNextCounter{ refNextCounter }
	{
		// no implementation
	}

	void cOverflowCounter::resetCountValue(void) noexcept
	{
		cLimitCounter::resetCountValue();
		mrefNextCounter.resetCountValue();
	}

	void cOverflowCounter::count(void) noexcept(false)
	{
		cLimitCounter::count();
		
		if (mCountValue == 0)
		{
			mrefNextCounter.count();
		}
	}
}
