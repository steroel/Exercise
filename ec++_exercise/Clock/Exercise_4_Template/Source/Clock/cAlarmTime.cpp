#include "cAlarmTime.hpp"

namespace Clock
{
	cAlarmTime::cAlarmTime(const uint32_t AlarmHour, const uint32_t AlarmMinute, const uint32_t AlarmSecond) :
		mAlarmHour{ AlarmHour },
		mAlarmMinute{ AlarmMinute },
		mAlarmSecond{ AlarmSecond }
	{
		// no implementation
	}

	uint32_t cAlarmTime::getAlarmHour(void) const
	{
		return mAlarmHour;
	}

	uint32_t cAlarmTime::getAlarmMinute(void) const
	{
		return mAlarmMinute;
	}

	uint32_t cAlarmTime::getAlarmSecond(void) const
	{
		return mAlarmSecond;
	}
}