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
		//ex3
		
		//ex4
		
		//ex5 mClockApplication.setPtr_icTimer(&mTIM7);
	}

	void cClockApplicationBuilder::execute(void)
	{
		cSTM32F7xxNVIC_Dispatcher::init();
		//ex5 cSTM32F7xxNVIC_Dispatcher::registerInterruptCallback(..., TIM7_InterruptVectorNumber);
		cSTM32F7xxNVIC_Dispatcher::registerInterruptAcknowledge(&mTIM7, TIM7_InterruptVectorNumber);
		
		cSTM32F7xxNVIC_Driver::setPriority(TIM7_InterruptVectorNumber, InterruptPriorityLowest);
		cSTM32F7xxNVIC_Driver::enableIRQ(TIM7_InterruptVectorNumber);
		
		mClockApplication.run();
	}
}