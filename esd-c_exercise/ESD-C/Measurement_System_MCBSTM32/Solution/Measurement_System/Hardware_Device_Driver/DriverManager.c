#include "stm32f10x.h"
#include "DriverManager.h"
#include "I_Button_Config.h"
#include "I_LED_Config.h"
#include "I_LCD_Text_Config.h"

#include "I_GPIO_Config.h"
#include "I_NVIC_Dispatcher_Config.h"

#include "RegisterMap_STM32F103.h"
#include "USART_STM32F103.h"

void DriverManager_construct(DriverManager* const ptrDriverManager)
{
	// 1st part uses CMCIS driver
	GPIO_Driver_STM32F103   locGPIO_Driver_STM32F103_Config;
	Button_MCBSTM32         locButton_MCBSTM32_Config;
	LED_MCBSTM32            locLED_MCBSTM32_Config;
	LCD_Text_AC162D_KS0066U locLCD_Text_AC162D_KS0066U_Config;
	
	NVIC_InitTypeDef  NVIC_InitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	ADC_InitTypeDef   ADC_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
		
	COM_lowLevel_init(COM1);
	USART_init();
	
	// clock enables
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	// CMSIS
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	// CMSIS
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	// CMSIS
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		
	// set the Vector Table base address at 0x08000000
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x05;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
  
 	// configure PA1 (ADC Channel1) as analog input
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// Timer 2 configuration for triggering the ADC with the CC2 event
	// 10 times per second
	TIM_TimeBaseInitStructure.TIM_Period = 0x7530; 			// 600kHz : 60000 (0xEA60) = 10Hz (100ms) trigger 
															// 600kHz : 30000 (0x7530)    
	TIM_TimeBaseInitStructure.TIM_Prescaler = 0x78;			// 72MHz : 120 (0x78) = 600kHz
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0x0;	
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit( TIM2, &TIM_TimeBaseInitStructure );
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;                
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	  
	// ADC1 configuration (ADC1CLK = 18 MHz)
	ADC_InitStructure.ADC_Mode               = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode       = ENABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv   = ADC_ExternalTrigConv_T2_CC2;
	ADC_InitStructure.ADC_DataAlign          = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel       = 1;
	ADC_Init(ADC1, &ADC_InitStructure);

	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_55Cycles5);
	ADC_ExternalTrigConvCmd(ADC1, ENABLE);
	// ADC 1 interrupt configuration
	ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);

	ADC_Cmd(ADC1, ENABLE);						// enable ADC1 
	ADC_ResetCalibration(ADC1);					// enable ADC1 reset calibration register
	while(ADC_GetResetCalibrationStatus(ADC1));	// check the end of ADC1 reset calibration register
	ADC_StartCalibration(ADC1);					// start ADC1 calibration
	while(ADC_GetCalibrationStatus(ADC1));		// check the end of ADC1 calibration
	TIM_Cmd(TIM2, ENABLE);						// enable TIM2	
		
	// 2nd part with specific drivers
	if (ptrDriverManager != nullptr)
	{
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOC_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Input;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Input;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_13;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_13;
		I_GPIO_open(&ptrDriverManager->objGPI_ButtonTAMP, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOA_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Input;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Input;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_0;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_0;
		I_GPIO_open(&ptrDriverManager->objGPI_ButtonWKUP, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOB_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_8;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_8;
		I_GPIO_open(&ptrDriverManager->objGPO_PB8_LED, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOB_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_9;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_9;
		I_GPIO_open(&ptrDriverManager->objGPO_PB9_LED, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOB_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_10;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_10;
		I_GPIO_open(&ptrDriverManager->objGPO_PB10_LED, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOB_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_11;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_11;
		I_GPIO_open(&ptrDriverManager->objGPO_PB11_LED, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOB_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_12;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_12;
		I_GPIO_open(&ptrDriverManager->objGPO_PB12_LED, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOB_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_13;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_13;
		I_GPIO_open(&ptrDriverManager->objGPO_PB13_LED, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOB_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_14;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_14;
		I_GPIO_open(&ptrDriverManager->objGPO_PB14_LED, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOB_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_15;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_15;
		I_GPIO_open(&ptrDriverManager->objGPO_PB15_LED, &locGPIO_Driver_STM32F103_Config);
		
		locButton_MCBSTM32_Config.mActivity = LowActiveButton;
		locButton_MCBSTM32_Config.mPreviousState = UndefinedButtonState;
		locButton_MCBSTM32_Config.mDebounceValue = 500;
		locButton_MCBSTM32_Config.mptrInPort = &ptrDriverManager-> objGPI_ButtonTAMP;
		I_Button_open(&ptrDriverManager->objButtonTAMP, &locButton_MCBSTM32_Config);
		
		locButton_MCBSTM32_Config.mptrInPort = &ptrDriverManager-> objGPI_ButtonWKUP;
		I_Button_open(&ptrDriverManager->objButtonWKUP, &locButton_MCBSTM32_Config);
			
		locLED_MCBSTM32_Config.mActivity = HighActiveLED;
		locLED_MCBSTM32_Config.mptrOutPort = &ptrDriverManager->objGPO_PB8_LED;
		I_LED_open(&ptrDriverManager->objLED[0], &locLED_MCBSTM32_Config);
		
		locLED_MCBSTM32_Config.mActivity = HighActiveLED;
		locLED_MCBSTM32_Config.mptrOutPort = &ptrDriverManager->objGPO_PB9_LED;
		I_LED_open(&ptrDriverManager->objLED[1], &locLED_MCBSTM32_Config);
		
		locLED_MCBSTM32_Config.mActivity = HighActiveLED;
		locLED_MCBSTM32_Config.mptrOutPort = &ptrDriverManager->objGPO_PB10_LED;
		I_LED_open(&ptrDriverManager->objLED[2], &locLED_MCBSTM32_Config);
		
		locLED_MCBSTM32_Config.mActivity = HighActiveLED;
		locLED_MCBSTM32_Config.mptrOutPort = &ptrDriverManager->objGPO_PB11_LED;
		I_LED_open(&ptrDriverManager->objLED[3], &locLED_MCBSTM32_Config);
		
		locLED_MCBSTM32_Config.mActivity = HighActiveLED;
		locLED_MCBSTM32_Config.mptrOutPort = &ptrDriverManager->objGPO_PB12_LED;
		I_LED_open(&ptrDriverManager->objLED[4], &locLED_MCBSTM32_Config);
		
		locLED_MCBSTM32_Config.mActivity = HighActiveLED;
		locLED_MCBSTM32_Config.mptrOutPort = &ptrDriverManager->objGPO_PB13_LED;
		I_LED_open(&ptrDriverManager->objLED[5], &locLED_MCBSTM32_Config);
		
		locLED_MCBSTM32_Config.mActivity = HighActiveLED;
		locLED_MCBSTM32_Config.mptrOutPort = &ptrDriverManager->objGPO_PB14_LED;
		I_LED_open(&ptrDriverManager->objLED[6], &locLED_MCBSTM32_Config);
		
		locLED_MCBSTM32_Config.mActivity = HighActiveLED;
		locLED_MCBSTM32_Config.mptrOutPort = &ptrDriverManager->objGPO_PB15_LED;
		I_LED_open(&ptrDriverManager->objLED[7], &locLED_MCBSTM32_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOC_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_10;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_10;
		I_GPIO_open(&ptrDriverManager->objGPIO_LCD_Control_E, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOC_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_11;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_11;
		I_GPIO_open(&ptrDriverManager->objGPIO_LCD_Control_RW, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOC_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_12;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_12;
		I_GPIO_open(&ptrDriverManager->objGPIO_LCD_Control_RS, &locGPIO_Driver_STM32F103_Config);
		
		locGPIO_Driver_STM32F103_Config.mptrGPIO_Register_STM32F103 = (GPIO_Register_STM32F103*)GPIOC_BASEADR;
		locGPIO_Driver_STM32F103_Config.mMode           = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mModeBackup     = GPIO_Output_50MHz;
		locGPIO_Driver_STM32F103_Config.mOutputMode     = GPO_GenaralPurpose_PushPull;
		locGPIO_Driver_STM32F103_Config.mInputMode      = GPI_Floating;
		locGPIO_Driver_STM32F103_Config.mBitPositionMSB = GPIO_Bit_3;
		locGPIO_Driver_STM32F103_Config.mBitPositionLSB = GPIO_Bit_0;
		I_GPIO_open(&ptrDriverManager->objGPIO_LCD_Data, &locGPIO_Driver_STM32F103_Config);
			
		locLCD_Text_AC162D_KS0066U_Config.mptrGPIO_LCD_Control_E  = &ptrDriverManager->objGPIO_LCD_Control_E;
		locLCD_Text_AC162D_KS0066U_Config.mptrGPIO_LCD_Control_RW = &ptrDriverManager->objGPIO_LCD_Control_RW;
		locLCD_Text_AC162D_KS0066U_Config.mptrGPIO_LCD_Control_RS = &ptrDriverManager->objGPIO_LCD_Control_RS;
		locLCD_Text_AC162D_KS0066U_Config.mptrGPIO_LCD_Data       = &ptrDriverManager->objGPIO_LCD_Data;
		locLCD_Text_AC162D_KS0066U_Config.mBusDelay_2N            = 0;
		locLCD_Text_AC162D_KS0066U_Config.mDataBusWidth           = DataBus_4Bit;
		locLCD_Text_AC162D_KS0066U_Config.mLines                  = Line_2;
		locLCD_Text_AC162D_KS0066U_Config.mColumns                = Columns_16;
		locLCD_Text_AC162D_KS0066U_Config.mDots 		              = Dots_5x8;
		I_LCD_Text_open(&ptrDriverManager->objLCD_Text, &locLCD_Text_AC162D_KS0066U_Config);
	}
	else
	{
		// nothing to do
	}
}
