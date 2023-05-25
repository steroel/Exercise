#include "cSTM32F7xxTIMER_Register.hpp"

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
					void cSTM32F7xxTIMER_Register::setTIM_CR1(const vuint32_t TIM_CR1_RegisterValue) volatile
					{
						TIM_CR1 = TIM_CR1_RegisterValue;
					}

					void cSTM32F7xxTIMER_Register::setTIM_CR2(const vuint32_t TIM_CR2_RegisterValue) volatile
					{
						TIM_CR2 = TIM_CR2_RegisterValue;
					}

					void cSTM32F7xxTIMER_Register::setTIM_DIER(const vuint32_t TIM_DIER_RegisterValue) volatile
					{
						TIM_DIER = TIM_DIER_RegisterValue;
					}

					void cSTM32F7xxTIMER_Register::setTIM_SR(const vuint32_t TIM_SR_RegisterValue) volatile
					{
						TIM_SR = TIM_SR_RegisterValue;
					}

					void cSTM32F7xxTIMER_Register::setTIM_EGR(const vuint32_t TIM_EGR_RegisterValue) volatile
					{
						TIM_EGR = TIM_EGR_RegisterValue;
					}

					void cSTM32F7xxTIMER_Register::setTIM_CNT(const vuint32_t TIM_CNT_RegisterValue) volatile
					{
						TIM_CNT = TIM_CNT_RegisterValue;
					}

					void cSTM32F7xxTIMER_Register::setTIM_PSC(const vuint32_t TIM_PSC_RegisterValue) volatile
					{
						TIM_PSC = TIM_PSC_RegisterValue;
					}

					void cSTM32F7xxTIMER_Register::setTIM_ARR(const vuint32_t TIM_ARR_RegisterValue) volatile
					{
						TIM_ARR = TIM_ARR_RegisterValue;
					}
					

					vuint32_t cSTM32F7xxTIMER_Register::getTIM_CR1(void) const volatile  
					{
						return TIM_CR1;
					}

					vuint32_t cSTM32F7xxTIMER_Register::getTIM_CR2(void) const volatile
					{
						return TIM_CR2;
					}

					vuint32_t cSTM32F7xxTIMER_Register::getTIM_DIER(void) const volatile
					{
						return TIM_DIER;
					}

					vuint32_t cSTM32F7xxTIMER_Register::getTIM_SR(void) const volatile
					{
						return TIM_SR;
					}

					vuint32_t cSTM32F7xxTIMER_Register::getTIM_EGR(void) const volatile
					{
						return TIM_EGR;
					}

					vuint32_t cSTM32F7xxTIMER_Register::getTIM_CNT(void) const volatile
					{
						return TIM_CNT;
					}

					vuint32_t cSTM32F7xxTIMER_Register::getTIM_PSC(void) const volatile
					{
						return TIM_PSC;
					}

					vuint32_t cSTM32F7xxTIMER_Register::getTIM_ARR(void) const volatile
					{
						return TIM_ARR;
					}
				}
			}
		}
	}
}
