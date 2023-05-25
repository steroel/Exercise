#ifndef __icbcInterruptDispatcher_HPP__
#define __icbcInterruptDispatcher_HPP__

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			class icbcInterruptDispatcher
			{
				public:
					virtual void notifyInterruptService(void) =0;
			};
		}
	}
}

#endif // __icbcInterruptDispatcher_HPP__
