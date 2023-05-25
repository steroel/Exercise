#ifndef __cClockApplicationBuilder_HPP__
#define __cClockApplicationBuilder_HPP__

#include "../../Platform/Hardware_Abstraction/Device_Driver_Abstraction/STM32F1xx/TIMER/cSTM32F1xxTIMER_Driver.hpp"
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::STM32F1xx::TIMER::cSTM32F1xxTIMER_Driver;

#include "stm32f103xb.h"	// Register base address definitions
	
#include "../../Clock_Application/cClockApplication.hpp"
using Clock_Application::cClockApplication;

#include "../../Clock/cClock.hpp"
using Clock::cClock;

#include "../../Clock/cAlarmClock.hpp"
using Clock::cAlarmClock;

namespace Clock_Application_Builder_Main
{
	class cClockApplicationBuilder
	{
		public:
			explicit cClockApplicationBuilder(void);
			virtual ~cClockApplicationBuilder() =default;

			void execute(void);
				
		private:
			cSTM32F1xxTIMER_Driver mTIM2{ TIM2_BASE };
			cClock mClock_1{ 23, 59, 50 };
			cClock mClock_2{ 13, 0, 0 };
			//ex4
			cClockApplication mClockApplication{ };		
	};
}
#endif // __cClockApplicationBuilder_HPP__
