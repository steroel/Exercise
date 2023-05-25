#include "cSTM32F7xxTIMER_Driver.hpp"
#include "cSTM32F7xxTIMER_Register.hpp"

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			namespace STM32F7xx
			{
				namespace TIMER
				{
					cSTM32F7xxTIMER_Driver::cSTM32F7xxTIMER_Driver(const volatile vuint32_t ptrRegisterBaseAddress):
						//mptrRegisterBaseAddress((cSTM32F7xxTIMER_Register* const volatile)ptrRegisterBaseAddress)
						mptrRegisterBaseAddress(reinterpret_cast<cSTM32F7xxTIMER_Register* const volatile>(ptrRegisterBaseAddress))
					{ 
						//1Hz = 72MHz / (18000[PSC] * 4000[ARR])
						mptrRegisterBaseAddress->setTIM_PSC (0x00004650);	// divider 1 = 18000
						mptrRegisterBaseAddress->setTIM_ARR (0x00000FA0);	// divider 2 = 40000
						mptrRegisterBaseAddress->setTIM_DIER(0x00000001);	// enable update interrupt 
					}

					cSTM32F7xxTIMER_Driver::~cSTM32F7xxTIMER_Driver()
					{
						mptrRegisterBaseAddress->setTIM_PSC (0x00000000);
						mptrRegisterBaseAddress->setTIM_ARR (0x00000000);
						mptrRegisterBaseAddress->setTIM_DIER(0x00000000);
					}

					void cSTM32F7xxTIMER_Driver::start(void) volatile
					{
						uint32_t locRegisterValue = mptrRegisterBaseAddress->getTIM_CR1();
						mptrRegisterBaseAddress->setTIM_CR1(locRegisterValue |= 0x00000001);	// enable counter
					}

					void cSTM32F7xxTIMER_Driver::stop(void) volatile
					{
						uint32_t locRegisterValue = mptrRegisterBaseAddress->getTIM_CR1();
						mptrRegisterBaseAddress->setTIM_CR1(locRegisterValue &= ~0x00000001);	// disable counter
					}

					void cSTM32F7xxTIMER_Driver::notifyInterruptAcknowledge(void) volatile
					{
						clearUIEInterruptFlag();
					}

	//				void cSTM32F7xxTIMER_Driver::clearCC1InterruptFlag(void) volatile
	//				{
	//					uint32_t locRegisterValue = mptrRegisterBaseAddress->getTIM_SR();
	//					mptrRegisterBaseAddress->setTIM_SR((locRegisterValue) &= (~(1<<1)));	
	//				}

					void cSTM32F7xxTIMER_Driver::clearUIEInterruptFlag(void) volatile
					{
						uint32_t locRegisterValue = mptrRegisterBaseAddress->getTIM_SR();
						mptrRegisterBaseAddress->setTIM_SR((locRegisterValue) &= (~(1<<0)));	
					}
				}
			}
		}
	}
}
