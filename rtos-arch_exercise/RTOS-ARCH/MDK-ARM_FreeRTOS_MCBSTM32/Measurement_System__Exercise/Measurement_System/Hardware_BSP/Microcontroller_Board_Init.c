#include "STM32F10x.h"
#include "MCBSTM32.h"
#include "LCD_KS0066U.h"
#include "Serial.h"

//-----------------------------------------------------------------------------
void initMicrocontrollerPeripherals(void)
{
	NVIC_InitTypeDef  NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	ADC_InitTypeDef   ADC_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	// set the Vector Table base address at 0x08000000
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
		
	NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x05;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	// enable GPIOA clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// enable ADC1 clock                                                        
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
  // enable TIM 2 clock
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
	//SysTick_CLKSourceConfig( SysTick_CLKSource_HCLK );	
	
 	// configure PA1 (ADC Channel1) as analog input
  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	// Timer 2 configuration for triggering the ADC with the CC2 event
	// 10 times per second
	TIM_TimeBaseInitStructure.TIM_Period = 0x7530; 			// 600kHz : 60000 (0xEA60) = 10Hz (100ms) trigger 
																											// 600kHz : 30000 (0x7530)  
	TIM_TimeBaseInitStructure.TIM_Prescaler = 0x78;		//  72MHz : 120 (0x78) = 600kHz
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

	ADC_Cmd(ADC1, ENABLE);												// enable ADC1 
	ADC_ResetCalibration(ADC1);										// enable ADC1 reset calibration register
	while(ADC_GetResetCalibrationStatus(ADC1));		// check the end of ADC1 reset calibration register
	ADC_StartCalibration(ADC1);										// start ADC1 calibration
	while(ADC_GetCalibrationStatus(ADC1));				// check the end of ADC1 calibration
  //TIM_Cmd(TIM2, ENABLE);												// enable TIM2	
}

//-----------------------------------------------------------------------------
void initBoard(void)
{
	LED_init(LED1);
  LED_init(LED2);
  LED_init(LED3);
  LED_init(LED4);
  LED_init(LED5);
  LED_init(LED6);
  LED_init(LED7);
  LED_init(LED8);
  //SD_lowLevel_init();
	COM_lowLevel_init(COM1);
	SER_init();
	LCD_lowLevel_init();
 	LCD_init();
	PB_init(BUTTON_TAMPER, BUTTON_MODE_GPIO);
}
