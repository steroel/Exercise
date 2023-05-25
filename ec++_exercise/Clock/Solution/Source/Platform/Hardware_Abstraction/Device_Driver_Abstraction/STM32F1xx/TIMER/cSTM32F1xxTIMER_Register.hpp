#ifndef __cSTM32F1xxTIMER_Register_HPP__
#define __cSTM32F1xxTIMER_Register_HPP__

#include "TypeDefinitions.hpp"

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			namespace STM32F1xx
			{
				namespace TIMER
				{
					class cSTM32F1xxTIMER_Register
					{
						public:
							void setTIM_CR1(const vuint32_t TIM_CR1_RegisterValue) volatile;
							void setTIM_CR2(const vuint32_t TIM_CR2_RegisterValue) volatile;
							void setTIM_SMCR(const vuint32_t TIM_SMCR_RegisterValue) volatile;
							void setTIM_DIER(const vuint32_t TIM_DIER_RegisterValue) volatile;
							void setTIM_SR(const vuint32_t TIM_SR_RegisterValue) volatile;
							void setTIM_EGR(const vuint32_t TIM_EGR_RegisterValue) volatile;
							void setTIM_CCMR1(const vuint32_t TIM_CCMR1_RegisterValue) volatile;
							void setTIM_CCMR2(const vuint32_t TIM_CCMR2_RegisterValue) volatile;
							void setTIM_CCER(const vuint32_t TIM_CCER_RegisterValue) volatile;
							void setTIM_CNT(const vuint32_t TIM_CNT_RegisterValue) volatile;
							void setTIM_PSC(const vuint32_t TIM_PSC_RegisterValue) volatile;
							void setTIM_ARR(const vuint32_t TIM_ARR_RegisterValue) volatile;
							void setTIM_CCR1(const vuint32_t TIM_CCR1_RegisterValue) volatile;
							void setTIM_CCR2(const vuint32_t TIM_CCR2_RegisterValue) volatile;
							void setTIM_CCR3(const vuint32_t TIM_CCR3_RegisterValue) volatile;
							void setTIM_CCR4(const vuint32_t TIM_CCR4_RegisterValue) volatile;
							void setTIM_DCR(const vuint32_t TIM_DCR_RegisterValue) volatile;
							void setTIM_DMAR(const vuint32_t TIM_DMAR_RegisterValue) volatile;
							
							vuint32_t getTIM_CR1(void) const volatile; 
							vuint32_t getTIM_CR2(void) const volatile;
							vuint32_t getTIM_SMCR(void) const volatile;
							vuint32_t getTIM_DIER(void) const volatile;
							vuint32_t getTIM_SR(void) const volatile;
							vuint32_t getTIM_EGR(void) const volatile;
							vuint32_t getTIM_CCMR1(void) const volatile;
							vuint32_t getTIM_CCMR2(void) const volatile;
							vuint32_t getTIM_CCER(void) const volatile;
							vuint32_t getTIM_CNT(void) const volatile;
							vuint32_t getTIM_PSC(void) const volatile;
							vuint32_t getTIM_ARR(void) const volatile;
							vuint32_t getTIM_CCR1(void) const volatile;
							vuint32_t getTIM_CCR2(void) const volatile;
							vuint32_t getTIM_CCR3(void) const volatile;
							vuint32_t getTIM_CCR4(void) const volatile;
							vuint32_t getTIM_DCR(void) const volatile;
							vuint32_t getTIM_DMAR(void) const volatile;

						protected:
							cSTM32F1xxTIMER_Register(void) = default;
							
							// do not use virtual, because the shifted address offset based on the VMT address 
							~cSTM32F1xxTIMER_Register() = default;
						
						private:
							vuint32_t TIM_CR1;
							vuint32_t TIM_CR2;
							vuint32_t TIM_SMCR;
							vuint32_t TIM_DIER;
							vuint32_t TIM_SR;
							vuint32_t TIM_EGR;
							vuint32_t TIM_CCMR1;
							vuint32_t TIM_CCMR2;
							vuint32_t TIM_CCER;
							vuint32_t TIM_CNT;
							vuint32_t TIM_PSC;
							vuint32_t TIM_ARR;
							vuint32_t RESERVED_1;
							vuint32_t TIM_CCR1;
							vuint32_t TIM_CCR2;
							vuint32_t TIM_CCR3;
							vuint32_t TIM_CCR4;
							vuint32_t RESERVED_2;
							vuint32_t TIM_DCR;
							vuint32_t TIM_DMAR;
					};
				}	
			}
		}
	}
}

#endif // __cSTM32F7xxTIMER_Register_HPP__
