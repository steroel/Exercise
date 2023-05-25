#ifndef __icbInterruptAcknowledge_HPP__
#define __icbInterruptAcknowledge_HPP__

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			class icbInterruptAcknowledge
			{
				public:
					virtual void notifyInterruptAcknowledge(void) volatile =0;
			};
		}
	}
}

#endif // __icbInterruptAcknowledge_HPP__
