#ifndef __tcClockArray_HPP__
#define __tcClockArray_HPP__

#define TC_ARRAY

#ifdef TC_ARRAY
	#include "../Common/tcArray.hpp"
#else
	#include <array>
#endif

#include "../Common/icSubject.hpp"
using namespace Common;

namespace Clock_Source
{
	template<uint32_t ArrayLength>
	class tcClockArray : public icSubject
	{
		public:
			explicit tcClockArray(void) =default;
			~tcClockArray() override =default;

			void attach(std::shared_ptr<icObserver> ptrObserver) override;
			void detach(std::shared_ptr<icObserver> ptrObserver) override;
		
			void notify(void) override;
		
		private:
			#ifdef TC_ARRAY
				tcArray<std::shared_ptr<icObserver>, ArrayLength> mObserverPtrArray {nullptr};
			#else
				std::array<std::shared_ptr<icObserver>, ArrayLength> mObserverPtrArray {nullptr};
			#endif
	};

	/*template<uint32_t ArrayLength>
	tcClockArray<ArrayLength>::tcClockArray(void) :
		mObserverPtrArray{ nullptr }
	{
		// no implementation
	}*/
	
	template<uint32_t ArrayLength>
	void tcClockArray<ArrayLength>::attach(std::shared_ptr<icObserver> ptrObserver)
	{
		if (ptrObserver != nullptr)
		{
			#ifdef TC_ARRAY
				mObserverPtrArray.insert(ptrObserver);
			#else
				mObserverPtrArray.back() = ptrObserver;
			#endif
		}
	}

	template<uint32_t ArrayLength>
	void tcClockArray<ArrayLength>::detach(std::shared_ptr<icObserver> ptrObserver)
	{
		if (ptrObserver != nullptr)
		{
			#ifdef TC_ARRAY
				mObserverPtrArray.erase(ptrObserver);
			#else
				for (auto& observer : mObserverPtrArray)
				{
					if (observer == ptrObserver)
					{
						observer = nullptr;
						break;
					}
				}
			#endif
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
