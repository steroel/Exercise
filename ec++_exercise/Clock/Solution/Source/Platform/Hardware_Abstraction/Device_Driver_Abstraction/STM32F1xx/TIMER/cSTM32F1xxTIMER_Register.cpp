#include "cSTM32F1xxTIMER_Register.hpp"

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
					void cSTM32F1xxTIMER_Register::setTIM_CR1(const vuint32_t TIM_CR1_RegisterValue) volatile
					{
						TIM_CR1 = TIM_CR1_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CR2(const vuint32_t TIM_CR2_RegisterValue) volatile
					{
						TIM_CR2 = TIM_CR2_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_SMCR(const vuint32_t TIM_SMCR_RegisterValue) volatile
					{
						TIM_SMCR = TIM_SMCR_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_DIER(const vuint32_t TIM_DIER_RegisterValue) volatile
					{
						TIM_DIER = TIM_DIER_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_SR(const vuint32_t TIM_SR_RegisterValue) volatile
					{
						TIM_SR = TIM_SR_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_EGR(const vuint32_t TIM_EGR_RegisterValue) volatile
					{
						TIM_EGR = TIM_EGR_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CCMR1(const vuint32_t TIM_CCMR1_RegisterValue) volatile
					{
						TIM_CCR1 = TIM_CCMR1_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CCMR2(const vuint32_t TIM_CCMR2_RegisterValue) volatile
					{
						TIM_CCR2 = TIM_CCMR2_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CCER(const vuint32_t TIM_CCER_RegisterValue) volatile
					{
						TIM_CCER = TIM_CCER_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CNT(const vuint32_t TIM_CNT_RegisterValue) volatile
					{
						TIM_CNT = TIM_CNT_RegisterValue;
					}
				
					void cSTM32F1xxTIMER_Register::setTIM_PSC(const vuint32_t TIM_PSC_RegisterValue) volatile
					{
						TIM_PSC = TIM_PSC_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_ARR(const vuint32_t TIM_ARR_RegisterValue) volatile
					{
						TIM_ARR = TIM_ARR_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CCR1(const vuint32_t TIM_CCR1_RegisterValue) volatile
					{
						TIM_CCR1 = TIM_CCR1_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CCR2(const vuint32_t TIM_CCR2_RegisterValue) volatile
					{
						TIM_CCR2 = TIM_CCR2_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CCR3(const vuint32_t TIM_CCR3_RegisterValue) volatile
					{
						TIM_CCR3 = TIM_CCR3_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_CCR4(const vuint32_t TIM_CCR4_RegisterValue) volatile
					{
						TIM_CCR4 = TIM_CCR4_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_DCR(const vuint32_t TIM_DCR_RegisterValue) volatile
					{
						TIM_DCR = TIM_DCR_RegisterValue;
					}
					
					void cSTM32F1xxTIMER_Register::setTIM_DMAR(const vuint32_t TIM_DMAR_RegisterValue) volatile
					{
						TIM_DMAR = TIM_DMAR_RegisterValue;
					}
					
					
					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CR1(void) const volatile
					{
						return TIM_CR1;
					}

					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CR2(void) const volatile
					{
						return TIM_CR2;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_SMCR(void) const volatile
					{
						return TIM_SMCR;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_DIER(void) const volatile
					{
						return TIM_DIER;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_SR(void) const volatile
					{
						return TIM_SR;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_EGR(void) const volatile
					{
						return TIM_EGR;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CCMR1(void) const volatile
					{
						return TIM_CCR1;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CCMR2(void) const volatile
					{
						return TIM_CCR2;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CCER(void) const volatile
					{
						return TIM_CCER;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CNT(void) const volatile
					{
						return TIM_CNT;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_PSC(void) const volatile
					{
						return TIM_PSC;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_ARR(void) const volatile
					{
						return TIM_ARR;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CCR1(void) const volatile
					{
						return TIM_CCR1;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CCR2(void) const volatile
					{
						return TIM_CCR2;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CCR3(void) const volatile
					{
						return TIM_CCR3;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_CCR4(void) const volatile
					{
						return TIM_CCR4;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_DCR(void) const volatile
					{
						return TIM_DCR;
					}


					vuint32_t cSTM32F1xxTIMER_Register::getTIM_DMAR(void) const volatile
					{
						return TIM_DMAR;
					}
				}
			}
		}
	}
}
