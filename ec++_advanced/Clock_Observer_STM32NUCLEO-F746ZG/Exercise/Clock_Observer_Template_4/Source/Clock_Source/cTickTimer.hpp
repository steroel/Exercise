#ifndef __cTickTimer_HPP__
#define __cTickTimer_HPP__

#include "TypeDefinitions.hpp"
#include "../Platform/Hardware_Abstraction/Device_Driver_Abstraction/icbInterruptDispatcher.hpp"
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::icbInterruptDispatcher;

#include "../Common/icSubject.hpp"
using Common::icSubject;

namespace Clock_Source
{
	class cTickTimer //**
	{
		public:
			explicit cTickTimer(void) =default;
			virtual ~cTickTimer()     =default;
			
			void set_ptr_iSubject(icSubject* ptrSubject, const uint32_t Index);
			
			void tick(void);

		private:
			static const uint32_t mArrayLength = 2;
			icSubject* mptr_icSubject[mArrayLength];
		
			//**
	};
}

#endif // __cTickTimer_HPP__
