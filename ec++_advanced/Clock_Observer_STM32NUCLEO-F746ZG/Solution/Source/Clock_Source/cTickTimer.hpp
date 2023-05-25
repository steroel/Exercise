#ifndef __cTickTimer_HPP__
#define __cTickTimer_HPP__

#include "TypeDefinitions.hpp"
#include "../Platform/Hardware_Abstraction/Device_Driver_Abstraction/icbInterruptDispatcher.hpp"
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::icbInterruptDispatcher;

#include "../Common/icSubject.hpp"
using Common::icSubject;

namespace Clock_Source
{
	class cTickTimer final: public icbInterruptDispatcher
	{
		public:
			explicit cTickTimer(void) =default;
			virtual ~cTickTimer()     =default;
			
			void set_ptr_iSubject(std::shared_ptr<icSubject> ptrSubject, const uint32_t Index);
			
			void tick(void);

		private:
			static const uint32_t mArrayLength = 2;
			std::shared_ptr<icSubject> mptr_icSubject[mArrayLength];
		
			void notifyInterruptService(void) override final;
	};
}

#endif // __cTickTimer_HPP__
