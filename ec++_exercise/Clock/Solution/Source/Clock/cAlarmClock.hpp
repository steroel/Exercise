#ifndef __cAlarmClock_HPP__
#define __cAlarmClock_HPP__

#include "cClock.hpp"
#include "icbcAlarmClock.hpp"
#include "cAlarmTime.hpp"

namespace Clock
{
	class cAlarmClock final : public cClock
	{
		public:
			cAlarmClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second,
									const uint32_t AlarmHour, const uint32_t AlarmMinute, const uint32_t AlarmSecond);
		
			~cAlarmClock() override =default;

			void registerCallbackAlarm(icbcAlarmClock* const ptr_icbcAlarmClock);
			void update(void) override;
				
		private:
			const cAlarmTime mAlarmTime;
			icbcAlarmClock* mptr_icbcAlarmClock;
	};
}

#endif // __cAlarmClock_HPP__
