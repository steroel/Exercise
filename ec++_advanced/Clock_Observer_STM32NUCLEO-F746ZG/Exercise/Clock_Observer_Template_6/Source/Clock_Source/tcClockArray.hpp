#ifndef __tcClockArray_HPP__
#define __tcClockArray_HPP__

#include "../Common/icSubject.hpp"
#include "../Common/tcArray.hpp"
using namespace Common;

namespace Clock_Source
{
	template<uint32_t ArrayLength>
	class tcClockArray : public icSubject
	{
		public:
			explicit tcClockArray(void) =default;
			~tcClockArray() override =default;

			void attach(icObserver* const ptrObserver) override;
			void detach(icObserver* const ptrObserver) override;

			void notify(void) override;
		
		private:
			tcArray<icObserver*, ArrayLength> mObserverPtrArray {nullptr};
	};

	template<uint32_t ArrayLength>
	void tcClockArray<ArrayLength>::attach(icObserver* ptrObserver)
	{
		if (ptrObserver != nullptr)
		{
			mObserverPtrArray.insert(ptrObserver);
		}
	}

	template<uint32_t ArrayLength>
	void tcClockArray<ArrayLength>::detach(icObserver* ptrObserver)
	{
		if (ptrObserver != nullptr)
		{
			mObserverPtrArray.erase(ptrObserver);
		}
	}

	template<uint32_t ArrayLength>
	void tcClockArray<ArrayLength>::notify(void)
	{
		//for (uint32_t locLoopIndex = 0; locLoopIndex < ArrayLength + 1; locLoopIndex++)  // manipulation to get std::range_error in case of invalid array index with tcArray
		/*for (uint32_t locLoopIndex = 0; locLoopIndex < ArrayLength; locLoopIndex++)
		{
			if (mObserverPtrArray[locLoopIndex] != nullptr)
			{
				mObserverPtrArray[locLoopIndex]->update();
				mObserverPtrArray[locLoopIndex]->show();
			}
		}*/

		for (auto & observer : mObserverPtrArray) //begin() and end() functions are required to implement in the Common::tcArray class!
		{
			if (observer != nullptr)
			{
				observer->update();
				observer->show();
			}
		}
	}
}

#endif // __tcClockArray_HPP__
