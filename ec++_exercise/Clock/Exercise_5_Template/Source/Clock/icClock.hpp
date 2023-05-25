#ifndef __icClock_HPP__
#define __icClock_HPP__

#include "TypeDefinitions.hpp"

namespace Clock
{
	class icClock
	{
		public:
			virtual ~icClock() =default;
		
			virtual uint32_t getHour(void) const =0;
			virtual uint32_t getMinute(void) const =0;
			virtual uint32_t getSecond(void) const =0;
					
			virtual void reset(void)  =0;			
			virtual void update(void) =0;
	};
}

#endif // __icClock_HPP__
