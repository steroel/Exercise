#ifndef __mSTM32F7xx_NVIC_Dispatcher_Types_HPP__
#define __mSTM32F7xx_NVIC_Dispatcher_Types_HPP__

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
					//enum class InterruptVectorNumber_t
					typedef enum
					{
						WWDG_InterruptVectorNumber               =0, 
						PVD_InterruptVectorNumber			           =1, 
						TAMP_STAMP_InterruptVectorNumber			   =2, 
						RTC_WKUP_InterruptVectorNumber			     =3, 
						FLASH_InterruptVectorNumber			         =4, 
						RCC_InterruptVectorNumber 		 	         =5,
						EXTI0_InterruptVectorNumber			         =6, 
						EXTI1_InterruptVectorNumber			         =7, 
						EXTI2_InterruptVectorNumber			         =8, 
						EXTI3_InterruptVectorNumber			         =9, 
						EXTI4_InterruptVectorNumber			         =10, 
						DMA1_Stream0_InterruptVectorNumber	     =11, 
						DMA1_Stream1_InterruptVectorNumber	     =12, 
						DMA1_Stream2_InterruptVectorNumber	     =13, 
						DMA1_Stream3_InterruptVectorNumber	     =14, 
						DMA1_Stream4_InterruptVectorNumber	     =15, 
						DMA1_Stream5_InterruptVectorNumber	     =16, 
						DMA1_Stream6_InterruptVectorNumber	     =17, 
						ADC_InterruptVectorNumber		             =18, 
						CAN1_TX_InterruptVectorNumber		         =19, 
						CAN1_RX0_InterruptVectorNumber		       =20, 
						CAN1_RX1_InterruptVectorNumber		       =21, 
						CAN1_SCE_InterruptVectorNumber		       =22, 
						EXTI9_5_InterruptVectorNumber		         =23, 
						TIM1_BRK_TIM9_InterruptVectorNumber		   =24, 
						TIM1_UP_TIM10_InterruptVectorNumber		   =25, 
						TIM1_TRG_COM_TIM11_InterruptVectorNumber =26, 
						TIM1_CC_InterruptVectorNumber		         =27,
						TIM2_InterruptVectorNumber 			         =28,
						TIM3_InterruptVectorNumber 			         =29,
						TIM4_InterruptVectorNumber 			         =30,
						I2C1_EV_InterruptVectorNumber		         =31,
						I2C1_ER_InterruptVectorNumber		         =32,
						I2C2_EV_InterruptVectorNumber		         =33,
						I2C2_ER_InterruptVectorNumber		         =34,
						SPI1_InterruptVectorNumber 			         =35,
						SPI2_InterruptVectorNumber 			         =36,
						USART1_InterruptVectorNumber 		         =37,
						USART2_InterruptVectorNumber 		         =38,
						USART3_InterruptVectorNumber 		         =39,
						EXTI15_10_InterruptVectorNumber 		     =40,
						RTC_Alarm_InterruptVectorNumber 		     =41,
						OTG_FS_WKUP_InterruptVectorNumber	       =42,
						TIM8_BRK_TIM12_InterruptVectorNumber	   =43,
						TIM8_UP_TIM13_InterruptVectorNumber      =44,
						TIM8_TRG_COM_TIM14_InterruptVectorNumber =45,
						TIM8_CC_InterruptVectorNumber	           =46,
						DMA1_Stream7_InterruptVectorNumber	     =47,
						FSMC_InterruptVectorNumber	             =48,
						SDMMC1_InterruptVectorNumber	           =49,
						TIM5_InterruptVectorNumber 			         =50,
						SPI3_InterruptVectorNumber 			         =51,
						UART4_InterruptVectorNumber 			       =52,
						UART5_InterruptVectorNumber 			       =53,
						TIM6_DAC_InterruptVectorNumber 			     =54,
						TIM7_InterruptVectorNumber 			         =55,
						DMA2_Stream0_InterruptVectorNumber	     =56,
						DMA2_Stream1_InterruptVectorNumber	     =57,
						DMA2_Stream2_InterruptVectorNumber	     =58,
						DMA2_Stream3_InterruptVectorNumber	     =59,
						DMA2_Stream4_InterruptVectorNumber	     =60,
						ETH_InterruptVectorNumber                =61,
						ETH_WKUP_InterruptVectorNumber 	         =62,
						CAN2_TX_InterruptVectorNumber 	         =63,
						CAN2_RX0_InterruptVectorNumber 	         =64,
						CAN2_RX1_InterruptVectorNumber 	         =65,
						CAN2_SCE_InterruptVectorNumber 	         =66,
						OTG_FS_InterruptVectorNumber 		         =67,
						DMA2_Stream5_InterruptVectorNumber	     =68,
						DMA2_Stream6_InterruptVectorNumber	     =69,
						DMA2_Stream7_InterruptVectorNumber	     =70,
						USART6_InterruptVectorNumber	           =71,
						I2C3_EV_InterruptVectorNumber	           =72,
						I2C3_ER_InterruptVectorNumber	           =73,	
						OTG_HS_EP1_OUT_InterruptVectorNumber     =74,
						OTG_HS_EP1_IN_InterruptVectorNumber	     =75,
						OTG_HS_WKUP_InterruptVectorNumber	       =76,
						OTG_HS_InterruptVectorNumber	           =77,
						DCMI_InterruptVectorNumber	             =78,
						CRYP_InterruptVectorNumber	             =79,
						HASH_RNG_InterruptVectorNumber	         =80,
						FPU_InterruptVectorNumber	               =81,
						UART7_InterruptVectorNumber	             =82,
						UART8_InterruptVectorNumber	             =83,
						SPI4_InterruptVectorNumber	             =84,
						SPI5_InterruptVectorNumber	             =85,
						SPI6_InterruptVectorNumber	             =86,
						SAI1_InterruptVectorNumber	             =87,
						LCD_TFT_InterruptVectorNumber            =88,
						LCD_TFT_ERROR_InterruptVectorNumber      =89,
						DMA2D_InterruptVectorNumber	             =90,
						SAI2_InterruptVectorNumber	             =91,
						QuadSPI_InterruptVectorNumber	           =92,
						LP_TIMER1_InterruptVectorNumber	         =93,
						HDMI_CEC_InterruptVectorNumber	         =94,
						I2C4_EV_InterruptVectorNumber	           =95,
						I2C4_ER_InterruptVectorNumber	           =96,
						SPDIFRX_InterruptVectorNumber	           =97,
						InterruptVectorNumberAmount              =98
					} InterruptVectorNumber_t;
					
					typedef enum
					{
						InterruptPriorityHighest =0, 
						InterruptPriority_1			 =1, 
						InterruptPriority_2			 =2, 
						InterruptPriority_3			 =3, 
						InterruptPriority_4			 =4, 
						InterruptPriority_5 		 =5,
						InterruptPriority_6			 =6, 
						InterruptPriority_7			 =7, 
						InterruptPriority_8			 =8, 
						InterruptPriority_9			 =9, 
						InterruptPriority_10		 =10, 
						InterruptPriority_11	   =11, 
						InterruptPriority_12	   =12, 
						InterruptPriority_13	   =13, 
						InterruptPriority_14     =14, 
						InterruptPriorityLowest  =15
					} InterruptPriority_t;
				}
			}
		}
	}
}
	
#endif // __mSTM32F7xx_NVIC_Dispatcher_Types_HPP__
