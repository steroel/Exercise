#ifndef __excRangeException_HPP__
#define __excRangeException_HPP__

#include <exception>

namespace User_Exception
{
	class excRangeException : public std::exception
	{
		public:
			explicit excRangeException(void) =default;
			~excRangeException() override =default;

			const char* what(void) const noexcept override;
	};
}

#endif // __excRangeException__
