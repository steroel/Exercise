#include "cClockObserverApplicationBuilder.hpp"

#include "../Platform/Hardware_Abstraction/Device_Driver_Abstraction/STM32F7xx/TIMER/cSTM32F7xxTIMER_Driver.hpp"
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::STM32F7xx::TIMER::cSTM32F7xxTIMER_Driver;

#include "stm32f746xx.h"	// Register base address definition

#include "../Platform/Hardware_Abstraction/iBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

#include "../Platform/Hardware_Abstraction/Device_Driver_Abstraction/STM32F7xx/NVIC_Dispatcher/cSTM32F7xxNVIC_Driver.hpp"
#include "../Platform/Hardware_Abstraction/Device_Driver_Abstraction/STM32F7xx/NVIC_Dispatcher/cSTM32F7xxNVIC_Dispatcher.hpp"
using namespace Platform::Hardware_Abstraction::Device_Driver_Abstraction::STM32F7xx::NVIC_Dispatcher;

#include "../Clock/cAnalogClock.hpp"
#include "../Clock/cDigitalClock.hpp"
#include "../Clock/cAnalogDigitalClock.hpp"
#include "../Clock_Source/tcClockArray.hpp"
#include "../Clock_Source/cClockContainer.hpp"
#include "../Clock_Source/cTickTimer.hpp"

namespace Clock_Observer_Application
{
	cClockObserverApplicationBuilder::cClockObserverApplicationBuilder(void) :
	  mClock{ 23, 59, 50 },
	  mptrAnalogClock{ new cAnalogClock{ 23, 59, 49 } },
	  mptrDigitalClock{ new cDigitalClock { 23, 59, 48 } },
	  mptrAnalogDigitalClock{ new cAnalogDigitalClock{ 23, 59, 47, 23, 59, 46 } }
	  //mAnalogDigitalClock{ 23, 59, 47 }
	{
		//**
		//**
		//**
		//**
		//**

		mptrTickTimer           = new cTickTimer{ };
		//**
				
		buildRelations();
	}

	cClockObserverApplicationBuilder::~cClockObserverApplicationBuilder()
	{
		//**
		delete mptrAnalogClock;
		delete mptrDigitalClock;
		delete mptrAnalogDigitalClock;
		delete mptrTickTimer;
		//**
	}
	
	void cClockObserverApplicationBuilder::buildRelations(void)
	{
		//**
		//**
		
		/*
		cSTM32F7xxNVIC_Dispatcher::init();
		cSTM32F7xxNVIC_Dispatcher::registerInterruptCallback(mptrTickTimer.get(), TIM7_InterruptVectorNumber);
		cSTM32F7xxNVIC_Dispatcher::registerInterruptAcknowledge(mptrTimer.get(), TIM7_InterruptVectorNumber);
		*/
	}

	void cClockObserverApplicationBuilder::execute(void)
	{
		bool locTimerState = false;
		
		cAnalogClock locAnalogClock{ 22, 60, 59 };  // object for user exception
		
		cSTM32F7xxNVIC_Driver::setPriority(TIM7_InterruptVectorNumber, InterruptPriorityLowest);
		cSTM32F7xxNVIC_Driver::enableIRQ(TIM7_InterruptVectorNumber);
		
		showValue("\nClock Observer");
				
		while(true)
		{
			showValue("\n\n<A> Update and show Clock");
			showValue("\n<B> Reset  and show Clock");
			showValue("\n<C> Update and show AnalogClock");
			showValue("\n<D> Update and show DigitalClock");
			showValue("\n<E> Update and show AnalogDigitalClock");
			showValue("\n<F> Exception User_Exception::ex(t)cRangeException");
			showValue("\n<G> Exception std::bad_alloc");
			showValue("\n<H> Attach clocks to   ClockArray");
			showValue("\n<I> Detach clocks from ClockArray");
			showValue("\n<J> Notify clocks of   ClockArray");
			showValue("\n<K> Attach clocks to   ClockContainer");
			showValue("\n<L> Detach clocks from ClockContainer");
			showValue("\n<M> Notify clocks of   ClockContainer");
			showValue("\n<N> Tick   clocks of   ClockArray and ContainerArray");
			showValue("\n<O> Tick 1s timer on / off");
			
			switch (getCommand())
			{
				case 'A':
					mClock.update();
					mClock.show();
				break;
				
				case 'B':
					mClock.reset();
					mClock.show();
				break;
				
				case 'C':
					mptrAnalogClock->update();
					mptrAnalogClock->show();
				break;
				
				case 'D':
					mptrDigitalClock->update();
					mptrDigitalClock->show();
				break;
				
				case 'E':
					mptrAnalogDigitalClock->update();
					mptrAnalogDigitalClock->show();
				break;
				
				case 'F':
					locAnalogClock.show();
					locAnalogClock.update(); //user exception: excRangeException or extcRangeException
					locAnalogClock.show();
				break;
				
				case 'G':
					while(true)
					{
						volatile uint32_t* locPtr = new uint32_t { 10 };	//system exception: bad_alloc
						*locPtr = 10; 										//to avoid compiler optimization
					} 
				break;
				
				case 'H': 
					//**
				break;
				
				case 'I':
					//**
				break;
				
				case 'J':
					//**
				break;
				
				case 'K': 
					//**
				break;
				
				case 'L':
					//**
				break;
				
				case 'M':
					//**
				break;
				
				case 'N': 
					//**
				break;
												
				case 'O': 
					/*
					if (locTimerState == false)
					{
						mptrTimer->start();
					}
					else
					{
						mptrTimer->stop();
					}
					*/
					
					if (locTimerState == false)
					{
						locTimerState = true;
					}
					else
					{
						locTimerState = false;
					}
				break;
				
				default:
					// no implementation
				break;
			}
		}
	}	
}
