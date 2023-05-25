#include "cSTM32F1xxNVIC_Register.hpp"

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
					void cSTM32F1xxNVIC_Register::setNVIC_ISER(const vuint32_t NVIC_ISER_RegisterValue, const uint32_t RegisterIndex) volatile
					{
						NVIC_ISER[RegisterIndex] = NVIC_ISER_RegisterValue;
					}
					
					void cSTM32F1xxNVIC_Register::setNVIC_ICER(const vuint32_t NVIC_ICER_RegisterValue, const uint32_t RegisterIndex) volatile
					{
						NVIC_ICER[RegisterIndex] = NVIC_ICER_RegisterValue;
					}
					
					void cSTM32F1xxNVIC_Register::setNVIC_ISPR(const vuint32_t NVIC_ISPR_RegisterValue, const uint32_t RegisterIndex) volatile
					{
						NVIC_ISPR[RegisterIndex] = NVIC_ISPR_RegisterValue;
					}
					
					void cSTM32F1xxNVIC_Register::setNVIC_ICPR(const vuint32_t NVIC_ICPR_RegisterValue, const uint32_t RegisterIndex) volatile
					{
						NVIC_ICPR[RegisterIndex] = NVIC_ICPR_RegisterValue;
					}
						
					void cSTM32F1xxNVIC_Register::setNVIC_IABR(const vuint32_t NVIC_IABR_RegisterValue, const uint32_t RegisterIndex) volatile
					{
						NVIC_IABR[RegisterIndex] = NVIC_IABR_RegisterValue;
					}
					
					void cSTM32F1xxNVIC_Register::setNVIC_IP(const vuint8_t NVIC_IPR_RegisterValue, const uint32_t RegisterIndex) volatile
					{
						NVIC_IP[RegisterIndex] = NVIC_IPR_RegisterValue;
					}

					vuint32_t cSTM32F1xxNVIC_Register::getNVIC_ISER(const uint32_t RegisterIndex) volatile const
					{
						return NVIC_ISER[RegisterIndex];
					}
					
					vuint32_t cSTM32F1xxNVIC_Register::getNVIC_ICER(const uint32_t RegisterIndex) volatile const
					{
						return NVIC_ICER[RegisterIndex];
					}
					
					vuint32_t cSTM32F1xxNVIC_Register::getNVIC_ISPR(const uint32_t RegisterIndex) volatile const
					{
						return NVIC_ISPR[RegisterIndex];
					}
					
					vuint32_t cSTM32F1xxNVIC_Register::getNVIC_ICPR(const uint32_t RegisterIndex) volatile const
					{
						return NVIC_ICPR[RegisterIndex];
					}
					
					vuint32_t cSTM32F1xxNVIC_Register::getNVIC_IABR(const uint32_t RegisterIndex) volatile const
					{
						return NVIC_IABR[RegisterIndex];
					}
					
					vuint8_t cSTM32F1xxNVIC_Register::getNVIC_IP(const uint32_t RegisterIndex) volatile const
					{
						return NVIC_IP[RegisterIndex];
					}
				}
			}
		}
	}
}
