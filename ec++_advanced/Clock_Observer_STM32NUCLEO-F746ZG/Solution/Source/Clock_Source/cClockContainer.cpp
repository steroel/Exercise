#include "cClockContainer.hpp"
#include "../Common/icObserver.hpp"

#include <algorithm>

namespace Clock_Source
{
	void cClockContainer::attach(std::shared_ptr<icObserver> ptrObserver)
	{
		if (ptrObserver != nullptr)
		{
			//mObserverPtrList.push_back(ptrObserver);
			mObserverPtrList.emplace_back(ptrObserver);
		}
	}

	void cClockContainer::detach(std::shared_ptr<icObserver> ptrObserver)
	{
		//for(list<std::shared_ptr<icObserver>>::iterator it = mObserverPtrList.begin(); it != mObserverPtrList.end() ; ++it)
		/*for (auto it = mObserverPtrList.begin(); it != mObserverPtrList.end(); ++it)
		{
			if (*it == ptrObserver)
			{
				mObserverPtrList.erase(it);
				break;  //!!! run-time error no end update
			}
		}*/


//		auto posIt = std::find(mObserverPtrList.begin(), mObserverPtrList.end(), ptrObserver);
//		if(posIt != mObserverPtrList.end())
//		{
//			mObserverPtrList.erase(posIt);
//		}



		for (auto it = mObserverPtrList.begin(); it != mObserverPtrList.end(); ++it)
		{
			if (*it == ptrObserver)
			{
				it = mObserverPtrList.erase(it);
				//break;
			}
		}

		// mObserverPtrList.remove(ptrObserver);

		// not possible!
//		for (auto& observer : mObserverPtrList)
//		{
//		if (observer == ptrObserver)
//			{
//				mObserverPtrList.erase(observer);
//				break;
//			}
//		}


	}
		
	void cClockContainer::notify(void)
	{
		//for(list<std::shared_ptr<icObserver>>::iterator it = mObserverPtrList.begin(); it != mObserverPtrList.end() ; ++it)
		for (const auto& observer : mObserverPtrList)
		{
			//(*it)->update();
			//(*it)->show();
			observer->update();
			observer->show();
		}

		for_each(mObserverPtrList.begin(), mObserverPtrList.end(),
				//[](std::shared_ptr<icObserver> ptrObserver){ ptrObserver->update();
				//                                             ptrObserver->show(); });
				[](auto ptrObserver){ ptrObserver->update();
				                      ptrObserver->show(); });
	}
}
