#ifndef __icbInterruptDispatcher_HPP__
#define __icbInterruptDispatcher_HPP__

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			class icbInterruptDispatcher
			{
				public:
					virtual void notifyInterruptService(void) =0;
			};
		}
	}
}

#endif // __icbInterruptDispatcher_HPP__
