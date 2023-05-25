#ifndef __cClockContainer_HPP__
#define __cClockContainer_HPP__

#include "../Common/icSubject.hpp"
using Common::icSubject;
using Common::icObserver;

#include <list>

namespace Clock_Source
{
	class cClockContainer : public icSubject
	{
		public:
			explicit cClockContainer(void) =default;
			~cClockContainer() override =default;
			
			void attach(std::shared_ptr<icObserver> ptrObserver) override;
			void detach(std::shared_ptr<icObserver> ptrObserver) override;
		
			void notify(void) override;

		private:
			std::list<std::shared_ptr<icObserver>> mObserverPtrList;
	};
}

#endif // __cClockContainer_HPP__
