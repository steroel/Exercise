#ifndef __cSTM32F7xxNVIC_Dispatcher_HPP
#define __cSTM32F7xxNVIC_Dispatcher_HPP

#include "TypeDefinitions.hpp"

// Forward declaration to avoid include in header file
namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			class icbInterruptDispatcher;
			class icbInterruptAcknowledge;
		}
	}
}
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::icbInterruptDispatcher;
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::icbInterruptAcknowledge;

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			namespace STM32F7xx
			{
				namespace NVIC_Dispatcher
				{
					class cSTM32F7xxNVIC_Dispatcher
					{
						public:
							static void init(void);
						
							static void registerInterruptCallback(icbInterruptDispatcher* const ptrInterruptCallbackObject, const InterruptVectorNumber_t InterruptVectorNumber);
							static void unregisterInterruptCallback(const InterruptVectorNumber_t InterruptVectorNumber);
						
							static void registerInterruptAcknowledge(icbInterruptAcknowledge* const parPtrInterruptAcknowledgeObject, const InterruptVectorNumber_t InterruptVectorNumber);
							static void unregisterInterruptAcknowledge(const InterruptVectorNumber_t InterruptVectorNumber);
						
							// Interrupt service
							static void TIM7_IRQHandler(void);
						
						private:
							static icbInterruptDispatcher* mptrCallbackObject[InterruptVectorNumberAmount];
							static icbInterruptAcknowledge* mptrAcknowledgeObject[InterruptVectorNumberAmount];
					};
				}
			}
		}
	}
}

#endif // __STM32F7xx_NVIC_Dispatcher_HPP
