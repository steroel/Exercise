#ifndef __cSTM32F7xxTIMER_Register_HPP__
#define __cSTM32F7xxTIMER_Register_HPP__

#include "TypeDefinitions.hpp"

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
					class cSTM32F7xxTIMER_Register
					{
						public:
							void setTIM_CR1(const vuint32_t TIM_CR1_RegisterValue) volatile;
							void setTIM_CR2(const vuint32_t TIM_CR2_RegisterValue) volatile;
							void setTIM_DIER(const vuint32_t TIM_DIER_RegisterValue) volatile;
							void setTIM_SR(const vuint32_t TIM_SR_RegisterValue) volatile;
							void setTIM_EGR(const vuint32_t TIM_ERG_RegisterValue) volatile;
							void setTIM_CNT(const vuint32_t TIM_CNT_RegisterValue) volatile;
							void setTIM_PSC(const vuint32_t TIM_PSC_RegisterValue) volatile;
							void setTIM_ARR(const vuint32_t TIM_ARR_RegisterValue) volatile;
							
							vuint32_t getTIM_CR1(void) const volatile; 
							vuint32_t getTIM_CR2(void) const volatile;
							vuint32_t getTIM_DIER(void) const volatile;
							vuint32_t getTIM_SR(void) const volatile;
							vuint32_t getTIM_EGR(void) const volatile;
							vuint32_t getTIM_CNT(void) const volatile;
							vuint32_t getTIM_PSC(void) const volatile;
							vuint32_t getTIM_ARR(void) const volatile;

						protected:
							cSTM32F7xxTIMER_Register(void) = default;
							
							// do not use virtual, because the shifted address offset based on the VMT address 
							~cSTM32F7xxTIMER_Register() = default;
						
						private:
							vuint32_t TIM_CR1;
							vuint32_t TIM_CR2;
							vuint32_t Reserved_1;
							vuint32_t TIM_DIER;
							vuint32_t TIM_SR;
							vuint32_t TIM_EGR;
							vuint32_t Reserved_2 [3];
							vuint32_t TIM_CNT;
							vuint32_t TIM_PSC;
							vuint32_t TIM_ARR;
					};
				}	
			}
		}
	}
}

#endif // __cSTM32F7xxTIMER_Register_HPP__
