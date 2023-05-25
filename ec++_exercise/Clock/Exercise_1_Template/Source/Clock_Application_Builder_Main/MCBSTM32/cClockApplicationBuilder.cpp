#include "cClockApplicationBuilder.hpp"

#include "../../Platform/Hardware_Abstraction/Device_Driver_Abstraction/STM32F1xx/NVIC_Dispatcher/cSTM32F1xxNVIC_Driver.hpp"
#include "../../Platform/Hardware_abstraction/Device_Driver_Abstraction/STM32F1xx/NVIC_Dispatcher/cSTM32F1xxNVIC_Dispatcher.hpp"
using namespace Platform::Hardware_Abstraction::Device_Driver_Abstraction::STM32F1xx::NVIC_Dispatcher;

#include "../../Platform/Hardware_Abstraction/imBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

namespace Clock_Application_Builder_Main
{
	cClockApplicationBuilder::cClockApplicationBuilder(void)
	{
		//ex3
		
		//ex4

		//ex5 mClockApplication.setPtr_icTimer(&mTIM2);
	}

	void cClockApplicationBuilder::execute(void)
	{
		cSTM32F1xxNVIC_Dispatcher::init();
		//ex5 cSTM32F1xxNVIC_Dispatcher::registerInterruptCallback(..., TIM2_InterruptVectorNumber);
		cSTM32F1xxNVIC_Dispatcher::registerInterruptAcknowledge(&mTIM2, TIM2_InterruptVectorNumber);
		
		cSTM32F1xxNVIC_Driver::setPriority(TIM2_InterruptVectorNumber, InterruptPriorityLowest);
		cSTM32F1xxNVIC_Driver::enableIRQ(TIM2_InterruptVectorNumber);
		
		mClockApplication.run();
	}
}