#include "ClockObserverApplicationMain.hpp"
using Clock_Observer_Application::cClockObserverApplicationBuilder;

#include "stm32f7xx_hal.h"

#include <exception>


int main(void)
{
	configHardware();

	try
	{
		showValue("\nClock Observer is starting ...\n");

		cClockObserverApplicationBuilder locClockObserverApplicationBuilder{};
		locClockObserverApplicationBuilder.execute();
	}
	catch(const std::exception& refSystemException)
	{
		showValue("\nSystem exception: ", refSystemException.what());
	}
	catch(...)
	{
		showValue("\nUnserviced exception");
	}

	NVIC_SystemReset(); // software reset
}
