#ifndef __cSTM32F7xxTIMER_Driver_HPP__
#define __cSTM32F7xxTIMER_Driver_HPP__

#include "TypeDefinitions.hpp"
#include "../../../icbcInterruptAcknowledge.hpp"
#include "../../../icTimer.hpp"

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
					class cSTM32F7xxTIMER_Register;
		
					class cSTM32F7xxTIMER_Driver : public icbcInterruptAcknowledge, public icTimer
					{
						public:
							explicit cSTM32F7xxTIMER_Driver(const volatile vuint32_t ptrRegisterBaseAddress);
							virtual ~cSTM32F7xxTIMER_Driver();

							void notifyInterruptAcknowledge(void) volatile override;

							void start(void) volatile override;
							void stop(void) volatile override;

						private:
							//void clearCC1InterruptFlag(void) volatile;
							void clearUIEInterruptFlag(void) volatile;

						private:
							 volatile cSTM32F7xxTIMER_Register* const volatile mptrRegisterBaseAddress;
					};
				}
			}
		}
	}
}

#endif // __cSTM32F7xxTIMER_Driver_HPP__
