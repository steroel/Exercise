#ifndef __icSubject_HPP__
#define __icSubject_HPP__

#include <memory>

namespace Common
{
	class icObserver;
	
	class icSubject
	{
		public:
			virtual ~icSubject() =default;

			virtual void attach(std::shared_ptr<icObserver> ptrObserver) =0;
			virtual void detach(std::shared_ptr<icObserver> ptrObserver) =0;
		
			virtual void notify(void) =0;
	};
}
#endif // __icSubject_HPP__
