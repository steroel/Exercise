#ifndef __I_NVIC_Dispatcher_Types_H
#define __I_NVIC_Dispatcher_Types_H


#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
  WWDG_InterruptVectorNumber			= 0, 
  PVD_InterruptVectorNumber			    = 1, 
  TAMPER_InterruptVectorNumber			= 2, 
  RTC_InterruptVectorNumber			    = 3, 
  FLASH_InterruptVectorNumber			= 4, 
  RCC_5_InterruptVectorNumber 		 	= 5,
  EXTI0_InterruptVectorNumber			= 6, 
  EXTI1_InterruptVectorNumber			= 7, 
  EXTI2_InterruptVectorNumber			= 8, 
  EXTI3_InterruptVectorNumber			= 9, 
  EXTI4_InterruptVectorNumber			=10, 
  DMA1_Channel1_InterruptVectorNumber	=11, 
  DMA1_Channel2_InterruptVectorNumber	=12, 
  DMA1_Channel3_InterruptVectorNumber	=13, 
  DMA1_Channel4_InterruptVectorNumber	=14, 
  DMA1_Channel5_InterruptVectorNumber	=15, 
  DMA1_Channel6_InterruptVectorNumber	=16, 
  DMA1_Channel7_InterruptVectorNumber	=17, 
  ADC1_2_InterruptVectorNumber		    =18, 
  CAN1_TX_InterruptVectorNumber		    =19, 
  CAN1_RX0_InterruptVectorNumber		=20, 
  CAN1_RX1_InterruptVectorNumber		=21, 
  CAN1_SCE_InterruptVectorNumber		=22, 
  EXTI9_5_InterruptVectorNumber		    =23, 
  TIM1_BRK_InterruptVectorNumber		=24, 
  TIM1_UP_InterruptVectorNumber		    =25, 
  TIM1_TRG_COM_InterruptVectorNumber	=26, 
  TIM1_CC_InterruptVectorNumber		    =27,
  TIM2_InterruptVectorNumber 			=28,
  TIM3_InterruptVectorNumber 			=29,
  TIM4_InterruptVectorNumber 			=30,
  I2C1_EV_InterruptVectorNumber		    =31,
  I2C1_ER_InterruptVectorNumber		    =32,
  I2C2_EV_InterruptVectorNumber		    =33,
  I2C2_ER_InterruptVectorNumber		    =34,
  SPI1_InterruptVectorNumber 			=35,
  SPI2_InterruptVectorNumber 			=36,
  USART1_InterruptVectorNumber 		    =37,
  USART2_InterruptVectorNumber 		    =38,
  USART3_InterruptVectorNumber 		    =39,
  EXTI15_10_InterruptVectorNumber 		=40,
  RTCAlarm_InterruptVectorNumber 		=41,
  OTG_FS_WKUP_InterruptVectorNumber	    =42,
  TIM5_InterruptVectorNumber 			=50,
  SPI3_InterruptVectorNumber 			=51,
  UART4_InterruptVectorNumber 			=52,
  UART5_InterruptVectorNumber 			=53,
  TIM6_InterruptVectorNumber 			=54,
  TIM7_InterruptVectorNumber 			=55,
  DMA2_Channel1_InterruptVectorNumber	=56,
  DMA2_Channel2_InterruptVectorNumber	=57,
  DMA2_Channel3_InterruptVectorNumber	=58,
  DMA2_Channel4_InterruptVectorNumber	=59,
  DMA2_Channel5_InterruptVectorNumber	=60,
  ETH_InterruptVectorNumber             =61,
  ETH_WKUP_InterruptVectorNumber 	    =62,
  CAN2_TX_InterruptVectorNumber 	    =63,
  CAN2_RX0_InterruptVectorNumber 	    =64,
  CAN2_RX1_InterruptVectorNumber 	    =65,
  CAN2_SCE_InterruptVectorNumber 	    =66,
  OTG_FS_InterruptVectorNumber 		    =67
} interruptVectorNumber_t;

//#define INTERRUPT_VECTOR_AMOUNT       68

#ifdef __cplusplus
}
#endif


#endif // __I_NVIC_Dispatcher_Types_H
