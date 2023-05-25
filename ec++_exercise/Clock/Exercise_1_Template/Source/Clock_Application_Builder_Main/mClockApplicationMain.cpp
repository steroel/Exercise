#include "mClockApplicationMain.hpp"

void executeLimitCounter(void)
{
	//ex1
	
	while(true)
	{
		showValue("\n<A>: Count locLimitCounter");
		showValue("\n<B>: Set   locLimitCounter to 5");
		showValue("\n<C>: Reset locLimitCounter");
		
		//ex1 showValue("\n\nlocLimitCounter CountValue = ", ...);
		//ex1 showValue("\n                CountLimit = ", ...);
		
		switch (getCommand())
		{
			//ex1 case 'A': ... break;
			//ex1 case 'B': ... break;
			//ex1 case 'C': ... break;
			default: 
				showValue("\nError: Unsupported test case!\n");	
			break;
		}
	}
}

void executeClock(void)
{
	//ex2
	
	while(true)
	{
		showValue("\n<A>: Update locClock");
		showValue("\n<B>: Set    locClock to 23:59:55");
		showValue("\n<C>: Reset  locClock");
		
		showValue("\n\nlocClock HH:MM:SS");
		//ex2 cClockApplication::showClock(...);
		
		switch (getCommand())
		{
			//ex2 case 'A': ... break;
			//ex2 case 'B': ... break;
			//ex2 case 'C': ... break;
			default: 
				showValue("\nError: Unsupported test case!\n");	
			break;
		}
	}
}

int main(void)
{
	configHardware();
	
	showValue("\nMicroConsult GmbH");
	showValue("\nEC++ Seminar");
	showValue("\nExercise Clock ...\n");
	
	::executeLimitCounter();
	//ex2 ::executeClock();
	
	//ex3
	
	//return 0; since C++11, 0 it is automatically returned by default
}
