#ifndef __extcRangeException_HPP__
#define __extcRangeException_HPP__

#include <exception>

namespace User_Exception
{
	template<typename Range_T, typename ThrowingObject_T>
	class extcRangeException : public std::exception
	{
		public:
			explicit extcRangeException(void) =default;
			explicit extcRangeException(const Range_T OutOfRangeValue, ThrowingObject_T* const ptrThrowingObject = nullptr);
			~extcRangeException() override =default;
		
			Range_T getOutOfRangeValue(void) const;
			ThrowingObject_T* getThrowingObject(void) const;
		
			const char* what(void) const noexcept override;
		
		private:
			Range_T mOutOfRangeValue = 0;
			ThrowingObject_T* mptrThrowingObject = nullptr;
	};
	
	template<typename Range_T, typename ThrowingObject_T>
	extcRangeException<Range_T, ThrowingObject_T>::extcRangeException(const Range_T OutOfRangeValue, ThrowingObject_T* const ptrThrowingObject) :
		mOutOfRangeValue{ OutOfRangeValue},
		mptrThrowingObject{ ptrThrowingObject}
	{
		// no implementation
	}
	
	template<typename Range_T, typename ThrowingObject_T>
	Range_T extcRangeException<Range_T, ThrowingObject_T>::getOutOfRangeValue(void) const
	{
		return mOutOfRangeValue;
	}
	
	template<typename Range_T, typename ThrowingObject_T>
	ThrowingObject_T* extcRangeException<Range_T, ThrowingObject_T>::getThrowingObject(void) const
	{
		return mptrThrowingObject;
	}
	
	template<typename Range_T, typename ThrowingObject_T>
	const char* extcRangeException<Range_T, ThrowingObject_T>::what(void) const noexcept
	{
		return "User-Exception::RangeException";
	}
}

#endif // __extcRangeException__
