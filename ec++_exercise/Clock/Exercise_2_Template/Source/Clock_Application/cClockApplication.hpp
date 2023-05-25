#ifndef __cClockApplication_HPP__
#define __cClockApplication_HPP__

#include "../Clock/icClock.hpp"
using Clock::icClock;

#include "../Clock/icbcAlarmClock.hpp"
using Clock::icbcAlarmClock;

#include "../Platform/Hardware_Abstraction/Device_Driver_Abstraction/icbcInterruptDispatcher.hpp"
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::icbcInterruptDispatcher;

#include "../Platform/Hardware_Abstraction/Device_Driver_Abstraction/icTimer.hpp"
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::icTimer;

#include "../Platform/Hardware_Abstraction/imBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

namespace Clock_Application
{
	class cClockApplication	//ex4 //ex5	// special case of multiple inheritance
	{
		public:
			cClockApplication(void) =default;
			~cClockApplication() =default;
			//ex4 ~cClockApplication() override =default;
				
			//ex3
			//ex5			
			void run(void);
		
			static void showClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second);

		private:
			static const uint32_t mAmountClocks = 2;
			//ex3
			//ex5
			
			//ex4
			//ex5
	};
}

#endif // __cClockApplication_HPP__
