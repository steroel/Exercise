#include "cSTM32F7xxNVIC_Driver.hpp"
#include "cSTM32F7xxNVIC_Register.hpp"
#include "stm32f746xx.h"	// Register base address definitions


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
					//cSTM32F7xxNVIC_Register* const volatile cSTM32F7xxNVIC_Driver::mptrRegisterBaseAddress = (cSTM32F7xxNVIC_Register* volatile const)NVIC_BASE;
					cSTM32F7xxNVIC_Register* const volatile cSTM32F7xxNVIC_Driver::mptrRegisterBaseAddress = reinterpret_cast<cSTM32F7xxNVIC_Register* volatile const>(NVIC_BASE);					

					void cSTM32F7xxNVIC_Driver::enableIRQ(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						const uint32_t locRegisterIndex       = (InterruptVectorNumber / 32);
						const uint32_t locRegisterBitPosition = (InterruptVectorNumber % 32);
						
						uint32_t locRegisterValue = mptrRegisterBaseAddress->getNVIC_ISER(locRegisterIndex);   // read
						locRegisterValue          = locRegisterValue | (0x00000001 << locRegisterBitPosition); // modify - set bit
						mptrRegisterBaseAddress->setNVIC_ISER(locRegisterValue, locRegisterIndex);             // write
					}

					void cSTM32F7xxNVIC_Driver::disableIRQ(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						const uint32_t locRegisterIndex       = (InterruptVectorNumber / 32);
						const uint32_t locRegisterBitPosition = (InterruptVectorNumber % 32);
						
						uint32_t locRegisterValue = mptrRegisterBaseAddress->getNVIC_ICER(locRegisterIndex);   // read
						locRegisterValue          = locRegisterValue | (0x00000001 << locRegisterBitPosition); // modify - set bit
						mptrRegisterBaseAddress->setNVIC_ICER(locRegisterValue, locRegisterIndex);             // write	
					}

					void cSTM32F7xxNVIC_Driver::setPendingIRQ(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						const uint32_t locRegisterIndex       = (InterruptVectorNumber / 32);
						const uint32_t locRegisterBitPosition = (InterruptVectorNumber % 32);
						
						uint32_t locRegisterValue = mptrRegisterBaseAddress->getNVIC_ISPR(locRegisterIndex);   // read
						locRegisterValue          = locRegisterValue | (0x00000001 << locRegisterBitPosition); // modify - set bit
						mptrRegisterBaseAddress->setNVIC_ISPR(locRegisterValue, locRegisterIndex);             // write	
					}

					void cSTM32F7xxNVIC_Driver::clearPendingIRQ(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						const uint32_t locRegisterIndex       = (InterruptVectorNumber / 32);
						const uint32_t locRegisterBitPosition = (InterruptVectorNumber % 32);
						
						uint32_t locRegisterValue = mptrRegisterBaseAddress->getNVIC_ICPR(locRegisterIndex);   // read
						locRegisterValue          = locRegisterValue | (0x00000001 << locRegisterBitPosition); // modify - set bit
						mptrRegisterBaseAddress->setNVIC_ICPR(locRegisterValue, locRegisterIndex);             // write
					}
					
					uint32_t cSTM32F7xxNVIC_Driver::getPendingIRQ(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						const uint32_t locRegisterIndex       = (InterruptVectorNumber / 32);
						const uint32_t locRegisterBitPosition = (InterruptVectorNumber % 32);
						
						uint32_t locRegisterValue = mptrRegisterBaseAddress->getNVIC_ISPR(locRegisterIndex);   // read
						locRegisterValue = locRegisterValue & (0x00000001 << locRegisterBitPosition);          // mask
						locRegisterValue = locRegisterValue >> locRegisterBitPosition;                         // lowest bit to evaluate
						return locRegisterValue;
					}

					void cSTM32F7xxNVIC_Driver::setPriority(const InterruptVectorNumber_t InterruptVectorNumber, const InterruptPriority_t InterruptPriority)
					{
						mptrRegisterBaseAddress->setNVIC_IP(InterruptPriority << 4, InterruptVectorNumber);  // this CPU only supports a priority range from 0 to 15,
																																						                     // lowest prio equates 15, highest prio equates 0
																																						                     // represeted by the upper nipple
					}

					InterruptPriority_t cSTM32F7xxNVIC_Driver::getPriority(const InterruptVectorNumber_t InterruptVectorNumber)
					{
						uint8_t locRegisterValue = (mptrRegisterBaseAddress->getNVIC_IP(InterruptVectorNumber)) >> 4;
						return static_cast<InterruptPriority_t>(locRegisterValue);
					}
				}
			}
		}
	}
}