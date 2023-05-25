#include "mClockApplicationMain.hpp"

void executeLimitCounter(void)
{
	cLimitCounter locLimitCounter{ 0, 10 };
	
	while(true)
	{
		showValue("\n<A>: Count locLimitCounter");
		showValue("\n<B>: Set   locLimitCounter to 5");
		showValue("\n<C>: Reset locLimitCounter");
		
		showValue("\n\nlocLimitCounter CountValue = ", locLimitCounter.getCountValue());
		showValue("\n                CountLimit = ", locLimitCounter.getCountLimit());
		
		switch (getCommand())
		{
			case 'A': locLimitCounter.count(); break;
			case 'B': locLimitCounter.setCountValue(5); break;
			case 'C': locLimitCounter.resetCountValue(); break;
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
	//::executeClock();
	
	//ex3
	
	//return 0; since C++11, 0 it is automatically returned by default
}
