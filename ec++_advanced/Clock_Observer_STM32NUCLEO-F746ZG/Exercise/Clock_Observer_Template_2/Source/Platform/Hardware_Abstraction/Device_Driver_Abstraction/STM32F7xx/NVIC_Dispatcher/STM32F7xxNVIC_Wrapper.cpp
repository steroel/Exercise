#include "cSTM32F7xxNVIC_Dispatcher.hpp"
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::STM32F7xx::NVIC_Dispatcher::cSTM32F7xxNVIC_Dispatcher;

extern "C"
{
	void TIM7_IRQHandler(void)
	{
		cSTM32F7xxNVIC_Dispatcher::TIM7_IRQHandler();
	}
}
