#include "cLimitCounter.hpp"
#include "../User_Exception/excRangeException.hpp"
#include "../User_Exception/extcRangeException.hpp"

namespace Counter
{
	cLimitCounter::cLimitCounter(const uint32_t CountValue, const uint32_t CountLimit) noexcept :
	  mCountValue{ CountValue },
	  mCountLimit{ CountLimit }
	{
		// no implementation
	}
		
	void cLimitCounter::setCountValue(const uint32_t CountValue) noexcept
	{
		mCountValue = CountValue;
	}

	uint32_t cLimitCounter::getCountValue(void) const noexcept
	{
		return mCountValue;
	}

	void cLimitCounter::resetCountValue(void) noexcept
	{
		mCountValue = 0;
	}

	void cLimitCounter::count(void) noexcept(false)
	{
		if (mCountValue > mCountLimit)
		{
			throw(User_Exception::excRangeException{ });
		}

		if (mCountValue <= mCountLimit)
		{
			mCountValue++;
		}
		
		if (mCountValue > mCountLimit)
		{
			mCountValue = 0;
		}
	}
}
