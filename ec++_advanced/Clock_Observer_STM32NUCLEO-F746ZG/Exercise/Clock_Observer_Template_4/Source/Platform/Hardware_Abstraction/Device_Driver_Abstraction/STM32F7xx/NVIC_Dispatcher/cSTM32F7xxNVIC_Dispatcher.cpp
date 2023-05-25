#include "../../../icbInterruptDispatcher.hpp"
#include "../../../icbInterruptAcknowledge.hpp"
#include "cSTM32F7xxNVIC_Dispatcher.hpp"
#include "stm32f7xx_nucleo_144.h"


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
					icbInterruptDispatcher*  cSTM32F7xxNVIC_Dispatcher::mptrCallbackObject[InterruptVectorNumberAmount];
					icbInterruptAcknowledge* cSTM32F7xxNVIC_Dispatcher::mptrAcknowledgeObject[InterruptVectorNumberAmount];

					void cSTM32F7xxNVIC_Dispatcher::init(void)
					{
						uint32_t locLoopCounter = 0;
						
						for(locLoopCounter = 0; locLoopCounter < InterruptVectorNumberAmount; locLoopCounter++)
						{
							mptrCallbackObject[locLoopCounter] = nullptr;
							mptrAcknowledgeObject[locLoopCounter] = nullptr;
						}
					}

					void cSTM32F7xxNVIC_Dispatcher::registerInterruptCallback(icbInterruptDispatcher* const ptrInterruptCallbackObject, const InterruptVectorNumber_t InterruptVectorNumber)
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

					void cSTM32F7xxNVIC_Dispatcher::unregisterInterruptCallback(const InterruptVectorNumber_t interruptVectorNumber)
					{
						mptrCallbackObject[interruptVectorNumber] = nullptr;
					}

					void cSTM32F7xxNVIC_Dispatcher::registerInterruptAcknowledge(icbInterruptAcknowledge* const ptrInterruptAcknowledgeObject, const InterruptVectorNumber_t InterruptVectorNumber)
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

					void cSTM32F7xxNVIC_Dispatcher::unregisterInterruptAcknowledge(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						mptrAcknowledgeObject[InterruptVectorNumber] = nullptr;
					}

					void cSTM32F7xxNVIC_Dispatcher::TIM7_IRQHandler(void)
					{
						if (mptrAcknowledgeObject[TIM7_InterruptVectorNumber] != nullptr)
						{
							mptrAcknowledgeObject[TIM7_InterruptVectorNumber]->notifyInterruptAcknowledge();
						}
						else
						{
							// no implelemntation
						}
						
						BSP_LED_Toggle(LED_GREEN);
						
						if (mptrCallbackObject[TIM7_InterruptVectorNumber] != nullptr)
						{
							// call interrupt service
							mptrCallbackObject[TIM7_InterruptVectorNumber]->notifyInterruptService(); 
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
