#include "cClockApplicationBuilder.hpp"

#include "../../Platform/Hardware_Abstraction/Device_Driver_Abstraction/STM32F7xx/NVIC_Dispatcher/cSTM32F7xxNVIC_Driver.hpp"
#include "../../Platform/Hardware_abstraction/Device_Driver_Abstraction/STM32F7xx/NVIC_Dispatcher/cSTM32F7xxNVIC_Dispatcher.hpp"
using namespace Platform::Hardware_Abstraction::Device_Driver_Abstraction::STM32F7xx::NVIC_Dispatcher;

#include "../../Platform/Hardware_Abstraction/imBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

namespace Clock_Application_Builder_Main
{
	cClockApplicationBuilder::cClockApplicationBuilder(void)
	{
		//mClockApplication.setPtr_icClock(&mClock_1, 0);
		//mClockApplication.setPtr_icClock(&mClock_2, 1);
		
		mClockApplication.setPtr_icClock(&mClock, 0);
		mClockApplication.setPtr_icClock(&mAlarmClock, 1);
		
		mAlarmClock.registerCallbackAlarm(&mClockApplication);
		
		//ex5 mClockApplication.setPtr_icTimer(&mTIM7);
	}

	void cClockApplicationBuilder::execute(void)
	{
		cSTM32F7xxNVIC_Dispatcher::init();
		//ex5 cSTM32F7xxNVIC_Dispatcher::registerInterruptCallback(..., TIM7_InterruptVectorNumber);
		cSTM32F7xxNVIC_Dispatcher::registerInterruptAcknowledge(&mTIM7, TIM7_InterruptVectorNumber);
		
		cSTM32F7xxNVIC_Driver::setPriority(TIM7_InterruptVectorNumber, InterruptPriorityLowest);
		cSTM32F7xxNVIC_Driver::enableIRQ(TIM7_InterruptVectorNumber);
		
		//just for testing ++ pre- and postfix operrator overloading in cClock
	//	showValue("\nmClock      ");
	//	showValue(" HH:MM:SS");
	//	showValue(" ", mClock.getHour());
	//	showValue(":", mClock.getMinute());
	//	showValue(":", mClock.getSecond());
	//	
	//	cClock& locRefClock = ++mClock;	// prefix
	//	showValue("\nlocRefClock ");
	//	showValue(" HH:MM:SS");
	//	showValue(" ", locRefClock.getHour());
	//	showValue(":", locRefClock.getMinute());
	//	showValue(":", locRefClock.getSecond());
	//	
	//	showValue("\nmClock      ");
	//	showValue(" HH:MM:SS");
	//	showValue(" ", mClock.getHour());
	//	showValue(":", mClock.getMinute());
	//	showValue(":", mClock.getSecond());

	//	cClock locClock = mClock++;		// postfix
	//	showValue("\nlocClock    ");
	//	showValue(" HH:MM:SS");
	//	showValue(" ", locClock.getHour());
	//	showValue(":", locClock.getMinute());
	//	showValue(":", locClock.getSecond());
	//	showValue("\n");
		
		mClockApplication.run();
	}
}