#ifndef __cSTM32F1xxNVIC_Dispatcher_HPP
#define __cSTM32F1xxNVIC_Dispatcher_HPP

#include "TypeDefinitions.hpp"

// Forward declaration to avoid include in header file
namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			class icbcInterruptDispatcher;
			class icbcInterruptAcknowledge;
		}
	}
}
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::icbcInterruptDispatcher;
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::icbcInterruptAcknowledge;

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			namespace STM32F1xx
			{
				namespace NVIC_Dispatcher
				{
					class cSTM32F1xxNVIC_Dispatcher
					{
						public:
							static void init(void);
						
							static void registerInterruptCallback(icbcInterruptDispatcher* const ptrInterruptCallbackObject, const InterruptVectorNumber_t InterruptVectorNumber);
							static void unregisterInterruptCallback(const InterruptVectorNumber_t parInterruptVectorNumber);
						
							static void registerInterruptAcknowledge(icbcInterruptAcknowledge* const ptrInterruptAcknowledgeObject, const InterruptVectorNumber_t InterruptVectorNumber);
							static void unregisterInterruptAcknowledge(const InterruptVectorNumber_t InterruptVectorNumber);
						
							// Interrupt service
							static void TIM2_IRQHandler(void);
						
						private:
							static icbcInterruptDispatcher* mptrCallbackObject[InterruptVectorNumberAmount];
							static icbcInterruptAcknowledge* mptrAcknowledgeObject[InterruptVectorNumberAmount];
					};
				}
			}
		}
	}
}

#endif // __cSTM32F1xxNVIC_Dispatcher_HPP
