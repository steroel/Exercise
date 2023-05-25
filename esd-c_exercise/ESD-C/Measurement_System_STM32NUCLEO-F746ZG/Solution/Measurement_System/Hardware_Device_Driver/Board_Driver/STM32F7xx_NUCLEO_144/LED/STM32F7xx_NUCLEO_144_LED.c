#include "STM32F7xx_NUCLEO_144_LED.h"
#include "I_LED_Config.h"
#include "I_LED.h"

static void STM32F7xx_NUCLEO_144_LED_open(STM32F7xx_NUCLEO_144_LED* ptrLED, const STM32F7xx_NUCLEO_144_LED* const ptrLED_Config);
static void STM32F7xx_NUCLEO_144_LED_close(STM32F7xx_NUCLEO_144_LED* const ptrLED);
static void STM32F7xx_NUCLEO_144_LED_setOn(STM32F7xx_NUCLEO_144_LED* const ptrLED);
static void STM32F7xx_NUCLEO_144_LED_setOff(STM32F7xx_NUCLEO_144_LED* const ptrLED);
static void STM32F7xx_NUCLEO_144_LED_toggle(STM32F7xx_NUCLEO_144_LED* const ptrLED);

void I_LED_open(void* const ptrLED, const void* const ptrLED_Config)
{
	if ( (ptrLED != nullptr) && (ptrLED_Config != nullptr) )
	{
		STM32F7xx_NUCLEO_144_LED_open((STM32F7xx_NUCLEO_144_LED*) ptrLED, (STM32F7xx_NUCLEO_144_LED*) ptrLED_Config);
	}
	else
	{
		// nothing to do
	}
}

void I_LED_close(void* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		STM32F7xx_NUCLEO_144_LED_close((STM32F7xx_NUCLEO_144_LED*) ptrLED);
	}
	else
	{
		// nothing to do
	}
}

void I_LED_setOn(void* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		STM32F7xx_NUCLEO_144_LED_setOn((STM32F7xx_NUCLEO_144_LED*) ptrLED);
	}
	else
	{
		// nothing to do
	}
}

void I_LED_setOff(void* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		STM32F7xx_NUCLEO_144_LED_setOff((STM32F7xx_NUCLEO_144_LED*) ptrLED);
	}
	else
	{
		// nothing to do
	}
}

void I_LED_toggle(void* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		STM32F7xx_NUCLEO_144_LED_toggle((STM32F7xx_NUCLEO_144_LED*) ptrLED);
	}
	else
	{
		// nothing to do
	}
}

static void STM32F7xx_NUCLEO_144_LED_open(STM32F7xx_NUCLEO_144_LED* ptrLED, const STM32F7xx_NUCLEO_144_LED* const ptrLED_Config)
{
	if ( (ptrLED != nullptr) && (ptrLED_Config != nullptr) )
	{
		ptrLED->mptrOutPort       = ptrLED_Config->mptrOutPort;
		ptrLED->mOutPortPinNumber = ptrLED_Config->mOutPortPinNumber;
		
		GPIO_InitTypeDef  GPIO_InitStruct;	
		uint64_t locPortBaseAdress = (uint64_t)ptrLED->mptrOutPort;
		
		switch(locPortBaseAdress)
		{
			case GPIOA_BASE:
				__HAL_RCC_GPIOA_CLK_ENABLE();
			break;
			case GPIOB_BASE:
				__HAL_RCC_GPIOB_CLK_ENABLE();
			break;
			case GPIOC_BASE:
				__HAL_RCC_GPIOC_CLK_ENABLE();
			break;
			case GPIOD_BASE:
				__HAL_RCC_GPIOD_CLK_ENABLE();
			break;
			case GPIOE_BASE:
				__HAL_RCC_GPIOE_CLK_ENABLE();
			break;
			case GPIOF_BASE:
				__HAL_RCC_GPIOF_CLK_ENABLE();
			break;
			case GPIOG_BASE:
				__HAL_RCC_GPIOG_CLK_ENABLE();
			break;
			case GPIOH_BASE:
				__HAL_RCC_GPIOH_CLK_ENABLE();
			break;
			case GPIOI_BASE:
				__HAL_RCC_GPIOI_CLK_ENABLE();
			break;
			case GPIOJ_BASE:
				__HAL_RCC_GPIOJ_CLK_ENABLE();
			break;
			case GPIOK_BASE:
				__HAL_RCC_GPIOK_CLK_ENABLE();
			break;
			default:
				// nothing to do
			break;			
		}
		
		/* Configure the GPIO_LED pin */
		GPIO_InitStruct.Pin   = ptrLED->mOutPortPinNumber; //GPIO_PIN[Led];
		GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull  = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		
		HAL_GPIO_Init(ptrLED->mptrOutPort, &GPIO_InitStruct);
		HAL_GPIO_WritePin(ptrLED->mptrOutPort, ptrLED->mOutPortPinNumber, GPIO_PIN_RESET);
	}
	else
	{
		// nothing to do
	}
}

static void STM32F7xx_NUCLEO_144_LED_close(STM32F7xx_NUCLEO_144_LED* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		HAL_GPIO_WritePin(ptrLED->mptrOutPort, ptrLED->mOutPortPinNumber, GPIO_PIN_RESET);
		HAL_GPIO_DeInit(ptrLED->mptrOutPort, (uint32_t)ptrLED->mptrOutPort);
			
		ptrLED->mptrOutPort =  nullptr;
		ptrLED->mptrOutPort =  0;
	}
	else
	{
		// nothing to do
	}
}

static void STM32F7xx_NUCLEO_144_LED_setOn(STM32F7xx_NUCLEO_144_LED* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		HAL_GPIO_WritePin(ptrLED->mptrOutPort, ptrLED->mOutPortPinNumber, GPIO_PIN_SET); 
	}
	else
	{
		// nothing to do
	}
}

static void STM32F7xx_NUCLEO_144_LED_setOff(STM32F7xx_NUCLEO_144_LED* const ptrLED)
{
	if (ptrLED != nullptr)
	{
		HAL_GPIO_WritePin(ptrLED->mptrOutPort, ptrLED->mOutPortPinNumber, GPIO_PIN_RESET);
	}
	else
	{
		// nothing to do
	}
}

static void STM32F7xx_NUCLEO_144_LED_toggle(STM32F7xx_NUCLEO_144_LED* const ptrLED)
{
	uint32_t locPortValue = 0;
	
	if (ptrLED != nullptr)
	{
		HAL_GPIO_TogglePin(ptrLED->mptrOutPort, ptrLED->mOutPortPinNumber);
	}
	else
	{
		// nothing to do
	}
}
