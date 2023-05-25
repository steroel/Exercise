#include "cAlarmClock.hpp"

#include "../Platform/Hardware_Abstraction/imBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

namespace Clock
{
	cAlarmClock::cAlarmClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second,
													 const uint32_t AlarmHour, const uint32_t AlarmMinute, const uint32_t AlarmSecond) : 
		cClock{ Hour, Minute, Second },
		mAlarmTime{ AlarmHour, AlarmMinute, AlarmSecond },
		mptr_icbcAlarmClock{ nullptr }
	{
		// no implementation
	}

	void cAlarmClock::registerCallbackAlarm(icbcAlarmClock* const ptr_icbcAlarmClock)
	{
		mptr_icbcAlarmClock = ptr_icbcAlarmClock;
	}

	void cAlarmClock::update(void)
	{
		cClock::update();
		
		if( (mAlarmTime.getAlarmHour() == getHour() ) &&
				(mAlarmTime.getAlarmMinute() == getMinute() ) &&
				(mAlarmTime.getAlarmSecond() == getSecond()) )
		{
			if(mptr_icbcAlarmClock != nullptr)
			{
				mptr_icbcAlarmClock -> notifyAlarm();
			}
			else
			{
				showValue("\nError: Pointer inteface callback alarm clock is not initialized!");
			}
		}
		else
		{
			showValue("\nNO ALARM");
		}
	}
}
