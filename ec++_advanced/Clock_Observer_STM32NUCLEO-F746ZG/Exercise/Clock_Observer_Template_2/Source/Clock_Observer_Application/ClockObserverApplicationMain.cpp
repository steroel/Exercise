#include "ClockObserverApplicationMain.hpp"
using Clock_Observer_Application::cClockObserverApplicationBuilder;

#include "stm32f7xx_hal.h"

#include <exception>

int main(void)
{
	configHardware();
	
	showValue("\nClock Observer is starting ...\n");

	cClockObserverApplicationBuilder locClockObserverApplicationBuilder;
	locClockObserverApplicationBuilder.execute();

	NVIC_SystemReset(); // software reset
}
