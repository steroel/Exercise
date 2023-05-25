#include "excRangeException.hpp"

namespace User_Exception
{
	const char* excRangeException::what(void) const noexcept
	{
		return "User-Exception::excRangeException";
	}
}
