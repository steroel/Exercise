#ifndef __extcRangeException_HPP__
#define __extcRangeException_HPP__

#include <exception>

namespace User_Exception
{
	template<typename Range_T, typename ThrowingObject_T>
	class extcRangeException : public std::exception
	{
		public:
			//**
		private:
			//**
	};
	
	//**
}

#endif // __extcRangeException__
