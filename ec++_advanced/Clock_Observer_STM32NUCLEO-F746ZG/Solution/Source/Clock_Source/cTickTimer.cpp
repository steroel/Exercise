#include "cTickTimer.hpp"

namespace Clock_Source
{
	void cTickTimer::set_ptr_iSubject(std::shared_ptr<icSubject> ptrSubject, const uint32_t Index)
	{
		if(Index < mArrayLength)
		{
			mptr_icSubject[Index] = ptrSubject;
		}
		else
		{
			// no implementation
		}
	}

	void cTickTimer::notifyInterruptService(void)
	{
	 	tick();
	}
	
	void cTickTimer::tick(void)
	{
		uint32_t locIndex = 0;
		
		for(locIndex = 0; locIndex < mArrayLength; locIndex++)
		{
			if(mptr_icSubject[locIndex] != nullptr)
			{
				mptr_icSubject[locIndex] -> notify();
			}
			else
			{
				// no implementation
			}
		}
	}
}
