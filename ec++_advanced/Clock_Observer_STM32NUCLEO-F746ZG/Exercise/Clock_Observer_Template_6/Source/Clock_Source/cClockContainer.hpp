#ifndef __cClockContainer_HPP__
#define __cClockContainer_HPP__

#include "../Common/icSubject.hpp"
using Common::icSubject;
using Common::icObserver;

#include <list>
using std::list;

namespace Clock_Source
{
	class cClockContainer : public icSubject
	{
		public:
			explicit cClockContainer(void) =default;
			~cClockContainer() override =default;

			void attach(icObserver* const ptrObserver) override;
			void detach(icObserver* const ptrObserver) override;

			void notify(void) override;

		private:
			std::list<icObserver*> mObserverPtrList;
	};
}

#endif // __cClockContainer_HPP__
