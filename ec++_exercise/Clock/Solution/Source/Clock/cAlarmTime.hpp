#ifndef __cAlarmTime_HPP__
#define __cAlarmTime_HPP__

#include "TypeDefinitions.hpp"

namespace Clock
{
	class cAlarmTime
	{
		public:
			cAlarmTime(const uint32_t AlarmHour, const uint32_t AlarmMinute, const uint32_t AlarmSecond);
			virtual ~cAlarmTime() =default;

			uint32_t getAlarmHour(void) const;
			uint32_t getAlarmMinute(void) const;
			uint32_t getAlarmSecond(void) const;
				
		private:
			uint32_t mAlarmHour;
			uint32_t mAlarmMinute;
			uint32_t mAlarmSecond;
	};
}

#endif // __cAlarmTime_HPP__
