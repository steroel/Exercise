#include "../../../icbcInterruptDispatcher.hpp"
#include "../../../icbcInterruptAcknowledge.hpp"
#include "cSTM32F1xxNVIC_Dispatcher.hpp"
#include "mMCBSTM32_LED.h"

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
					icbcInterruptDispatcher*  cSTM32F1xxNVIC_Dispatcher::mptrCallbackObject[InterruptVectorNumberAmount];
					icbcInterruptAcknowledge* cSTM32F1xxNVIC_Dispatcher::mptrAcknowledgeObject[InterruptVectorNumberAmount];

					void cSTM32F1xxNVIC_Dispatcher::init(void)
					{
						uint32_t locLoopCounter = 0;
						
						for(locLoopCounter = 0; locLoopCounter < InterruptVectorNumberAmount; locLoopCounter++)
						{
							mptrCallbackObject[locLoopCounter]    = nullptr;
							mptrAcknowledgeObject[locLoopCounter] = nullptr;
						}
					}

					void cSTM32F1xxNVIC_Dispatcher::registerInterruptCallback(icbcInterruptDispatcher* const ptrInterruptCallbackObject, const InterruptVectorNumber_t InterruptVectorNumber)
					{
						if (ptrInterruptCallbackObject != nullptr)
						{
							mptrCallbackObject[InterruptVectorNumber] = ptrInterruptCallbackObject;
						}
						else
						{
							// no implementation
						}
					}

					void cSTM32F1xxNVIC_Dispatcher::unregisterInterruptCallback(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						mptrCallbackObject[InterruptVectorNumber] = nullptr;
					}

					void cSTM32F1xxNVIC_Dispatcher::registerInterruptAcknowledge(icbcInterruptAcknowledge* const ptrInterruptAcknowledgeObject, const InterruptVectorNumber_t InterruptVectorNumber)
					{
						if (ptrInterruptAcknowledgeObject != nullptr)
						{
							mptrAcknowledgeObject[InterruptVectorNumber] = ptrInterruptAcknowledgeObject;
						}
						else
						{
							// no implementation
						}
					}

					void cSTM32F1xxNVIC_Dispatcher::unregisterInterruptAcknowledge(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						mptrAcknowledgeObject[InterruptVectorNumber] = nullptr;
					}

					void cSTM32F1xxNVIC_Dispatcher::TIM2_IRQHandler(void)
					{
						if (mptrAcknowledgeObject[TIM2_InterruptVectorNumber] != nullptr)
						{
							mptrAcknowledgeObject[TIM2_InterruptVectorNumber]->notifyInterruptAcknowledge();
						}
						else
						{
							// no implelemntation
						}
						
						#if( TARGET == 1)
							BSP_LED_Toggle(LED1);
						#endif
						
						
						if (mptrCallbackObject[TIM2_InterruptVectorNumber] != nullptr)
						{
							// call interrupt service
							mptrCallbackObject[TIM2_InterruptVectorNumber]->notifyInterruptService(); 
						}
						else
						{
							// no implementation
						}
					}
				}
			}
		}
	}
}
