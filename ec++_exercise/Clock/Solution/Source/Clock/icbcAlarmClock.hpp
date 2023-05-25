#ifndef __icbcAlarmClock_HPP__
#define __icbcAlarmClock_HPP__

namespace Clock
{
	class icbcAlarmClock
	{
		public:
			virtual ~icbcAlarmClock() =default;
		
			virtual void notifyAlarm(void) =0;
	};
}

#endif // __icbcAlarmClock_HPP__
