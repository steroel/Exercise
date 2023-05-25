#include "cSTM32F1xxNVIC_Dispatcher.hpp"
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::STM32F1xx::NVIC_Dispatcher::cSTM32F1xxNVIC_Dispatcher;

extern "C"
{
	void TIM2_IRQHandler(void)
	{
		cSTM32F1xxNVIC_Dispatcher::TIM2_IRQHandler();
	}
}
