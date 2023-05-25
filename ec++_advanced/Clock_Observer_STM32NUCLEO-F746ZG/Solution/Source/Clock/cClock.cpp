#include "cClock.hpp"

#include "../User_Exception/excRangeException.hpp"
#include "../User_Exception/extcRangeException.hpp"

#include "../Platform/Hardware_Abstraction/iBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

#include <iostream>
#include <iomanip>
#include <typeinfo>

namespace Clock
{
	cClock::cClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second) :
		mHour  { Hour, 23 },
		mMinute{ Minute, 59, mHour },
		mSecond{ Second, 59, mMinute }
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
		return(mHour.getCountValue());
	}

	uint32_t cClock::getMinute(void) const
	{
		return(mMinute.getCountValue());
	}

	uint32_t cClock::getSecond(void) const
	{
		return(mSecond.getCountValue());
	}

	void cClock::update(void)
	{
		try
		{
			mSecond.count();
		}
		catch(const User_Exception::excRangeException& refException)
		{
			showValue("\n");
			showValue(refException.what());
			reset();
		}
		catch(const User_Exception::extcRangeException<uint32_t, cLimitCounter>& refException)
		{
			showValue("\n");
			showValue(refException.what());
			showValue("\nOutOfRangeValue     = ", refException.getOutOfRangeValue() );
			showValue("\nThrowing object type: ", typeid(*(refException.getThrowingObject())).name() );
			(refException.getThrowingObject())->setCountValue(0);
		}
	}
	
	void cClock::show(void) const
	{
		std::cout << "[HH:MM:SS] ";
		std::cout << std::setfill('0') << std::setw(2) << getHour()   << ":";
		std::cout << std::setfill('0') << std::setw(2) << getMinute() << ":";
		std::cout << std::setfill('0') << std::setw(2) << getSecond();
	}
}
