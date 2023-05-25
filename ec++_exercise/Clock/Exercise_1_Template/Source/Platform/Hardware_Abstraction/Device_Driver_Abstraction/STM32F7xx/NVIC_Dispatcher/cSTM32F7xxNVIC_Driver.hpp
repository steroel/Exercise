#ifndef __cSTM32F7xxNVIC_Driver_HPP__
#define __cSTM32F7xxNVIC_Driver_HPP__

#include "TypeDefinitions.hpp"


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
					
					class cSTM32F7xxNVIC_Register;
					
					class cSTM32F7xxNVIC_Driver
					{
						public:
							static void enableIRQ(const InterruptVectorNumber_t InterruptVectorNumber);
							static void disableIRQ(const InterruptVectorNumber_t InterruptVectorNumber);
							static void setPendingIRQ(const InterruptVectorNumber_t InterruptVectorNumber);
							static void clearPendingIRQ(const InterruptVectorNumber_t InterruptVectorNumber);	
							static uint32_t getPendingIRQ(const InterruptVectorNumber_t InterruptVectorNumber);
							static void setPriority(const InterruptVectorNumber_t InterruptVectorNumber, InterruptPriority_t InterruptPriority);
							static InterruptPriority_t getPriority(const InterruptVectorNumber_t InterruptVectorNumber);

						private:
							static cSTM32F7xxNVIC_Register* const volatile mptrRegisterBaseAddress;	
					};
				}
			}
		}
	}
}

#endif // __cSTM32F7xxNVIC_Driver_HPP__
