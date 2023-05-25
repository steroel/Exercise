#ifndef __cSTM32F7xxNVIC_Register_HPP__
#define __cSTM32F7xxNVIC_Register_HPP__

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
					class cSTM32F7xxNVIC_Register
					{
						public:
							void setNVIC_ISER(const vuint32_t NVIC_ISER_RegisterValue, const uint32_t RegisterIndex) volatile;
							void setNVIC_ICER(const vuint32_t NVIC_ICER_RegisterValue, const uint32_t RegisterIndex) volatile;
							void setNVIC_ISPR(const vuint32_t NVIC_ISPR_RegisterValue, const uint32_t RegisterIndex) volatile;
							void setNVIC_ICPR(const vuint32_t NVIC_ICPR_RegisterValue, const uint32_t RegisterIndex) volatile;
							void setNVIC_IABR(const vuint32_t NVIC_IABR_RegisterValue, const uint32_t RegisterIndex) volatile;
							void setNVIC_IP(const vuint8_t NVIC_IP_RegisterValue, const uint32_t RegisterIndex) volatile;

							vuint32_t getNVIC_ISER(const uint32_t RegisterIndex) const volatile;
							vuint32_t getNVIC_ICER(const uint32_t RegisterIndex) const volatile;
							vuint32_t getNVIC_ISPR(const uint32_t RegisterIndex) const volatile;
							vuint32_t getNVIC_ICPR(const uint32_t RegisterIndex) const volatile;
							vuint32_t getNVIC_IABR(const uint32_t RegisterIndex) const volatile;
							vuint8_t  getNVIC_IP(const uint32_t RegisterIndex) const volatile;

						protected:
							cSTM32F7xxNVIC_Register(void) =default;
							~cSTM32F7xxNVIC_Register(void) =default;
							
						private:
							vuint32_t NVIC_ISER[8];
							vuint32_t RESERVED_1[0x18];
							vuint32_t NVIC_ICER[8];
							vuint32_t RESERVED_2[0x18];
							vuint32_t NVIC_ISPR[8];
							vuint32_t RESERVED_3[0x18];
							vuint32_t NVIC_ICPR[8];
							vuint32_t RESERVED_4[0x18];
							vuint32_t NVIC_IABR[8];
							vuint32_t RESERVED_5[0x38];
							//vuint32_t NVIC_IPR[60];
							vuint8_t NVIC_IP[240]; // registers are byte accessible
							vuint32_t RESERVED_6[0x283];
							vuint32_t NVIC_STIR;
					};
				}
			}
		}
	}
}

#endif // __cSTM32F7xxNVIC_Register_HPP__
