#include "cClock.hpp"

#include "../User_Exception/excRangeException.hpp"
#include "../User_Exception/extcRangeException.hpp"

#include "../Platform/Hardware_Abstraction/iBasicIO.hpp"
using namespace Platform::Hardware_Abstraction;

#include <iostream>
#include <iomanip>
#include <typeinfo>

namespace Clock
{
	//**
	
	/*
	void cClock::show(void) const
	{
		std::cout << "[HH:MM:SS] ";
		std::cout << std::setfill('0') << std::setw(2) << getHour()   << ":";
		std::cout << std::setfill('0') << std::setw(2) << getMinute() << ":";
		std::cout << std::setfill('0') << std::setw(2) << getSecond();
	}
	*/
}
