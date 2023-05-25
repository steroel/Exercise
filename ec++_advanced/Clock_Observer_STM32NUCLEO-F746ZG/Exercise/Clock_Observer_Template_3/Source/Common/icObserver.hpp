#ifndef __icObserver_HPP__
#define __icObserver_HPP__

namespace Common
{
	class icObserver
	{
		public:
			virtual ~icObserver() =default;
				
			virtual void update(void)  =0;
			virtual void show(void) const =0;
	};
}
#endif // __icObserver_HPP__
