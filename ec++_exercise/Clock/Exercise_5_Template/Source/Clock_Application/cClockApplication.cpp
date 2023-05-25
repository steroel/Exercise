#include "../Clock_Application/cClockApplication.hpp"

#include "../Platform/Hardware_Abstraction/imBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

#include <stdio.h>

namespace Clock_Application
{
	void cClockApplication::setPtr_icClock(icClock* const ptr_icClock, const uint8_t Index)
	{
		if (Index < mAmountClocks)
		{
			mptr_icClock[Index] = ptr_icClock;
		}
	}

	//ex5
				
	void cClockApplication::notifyAlarm(void)
	{
		showValue("\nA L A R M");
	}

	void cClockApplication::run(void)
	{	
		while(true)
		{
			for (auto locLoopIndex = 0; locLoopIndex < mAmountClocks; locLoopIndex++)
			{
				if(mptr_icClock[locLoopIndex] != nullptr)
				{
					showValue("\nClock[", locLoopIndex);
					showValue("] HH:MM:SS");
					showClock(mptr_icClock[locLoopIndex] -> getHour(),
										mptr_icClock[locLoopIndex] -> getMinute(),
										mptr_icClock[locLoopIndex] -> getSecond());
				}
				else
				{
					showValue("\nError: Pointer interface clock in not initialized!");
				}	
			}
			
			showValue("\n\n<A>: Update and show Clock[ 0 ]");
			showValue("\n<B>: Reset  and show Clock[ 0 ]");
			showValue("\n<C>: Update and show Clock[ 1 ]");
			showValue("\n<D>: Reset  and show Clock[ 1 ]");
			//ex5 showValue("\n<E>: Start 1s tick timer");
			//ex5 showValue("\n<F>: Stop  1s tick timer");
			
			if( (mptr_icClock[0] != nullptr) && (mptr_icClock[1] != nullptr) )
			{
				switch (getCommand())
				{
					case 'A': mptr_icClock[0] -> update(); break;
					case 'B': mptr_icClock[0] -> reset(); break;
					case 'C': mptr_icClock[1] -> update(); break;
					case 'D': mptr_icClock[1] -> reset(); break;
					//ex5 case 'E': mptr_icTimer -> start(); break;
					//ex5 case 'F': mptr_icTimer -> stop(); break;
					default: 
						showValue("\nError: Unsupported test case!\n");	
					break;
				}
			}
			else
			{
				showValue("\nError: Pointer interface clock is not initialized!");
			}	
		}
	}

//ex5
//	void cClockApplication::notifyInterruptService(void)
//	{
//		for (auto locLoopIndex= 0; locLoopIndex < mAmountClocks; locLoopIndex++)
//		{
//			if(mptr_icClock[locLoopIndex] != nullptr)
//			{
//				mptr_icClock[locLoopIndex] -> update();

//				showValue("\nClock[", locLoopIndex);
//				showValue("] HH:MM:SS");
//				showClock(mptr_icClock[locLoopIndex] -> getHour(),
//									mptr_icClock[locLoopIndex] -> getMinute(),
//									mptr_icClock[locLoopIndex] -> getSecond());
//			}
//			else
//			{
//				showValue("\nError: Pointer interface clock in not initialized!");
//			}
//		}
//		showValue("\n");
//	}

	void cClockApplication::showClock(const uint32_t Hour, const uint32_t Minute, const uint32_t Second)
	{
		printf("%02d",  Hour);
		printf(":%02d", Minute);
		printf(":%02d", Second);
	}
}