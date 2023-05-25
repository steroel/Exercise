#include "cTickTimer.hpp"

namespace Clock_Source
{
	void cTickTimer::set_ptr_iSubject(icSubject* ptrSubject, const uint32_t Index)
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

	//**
	
	void cTickTimer::tick(void)
	{
		uint32_t locIndex = 0;
		
		for(locIndex = 0; locIndex < mArrayLength; locIndex++)
		{
			if(mptr_icSubject[locIndex] != nullptr)
			{
				//**
			}
			else
			{
				// no implementation
			}
		}
	}
}
