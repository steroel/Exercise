#ifndef __icbcInterrputAcknowledge_HPP__
#define __icbcInterrputAcknowledge_HPP__

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			class icbcInterruptAcknowledge
			{
				public:
					virtual void notifyInterruptAcknowledge(void) volatile =0;
			};
		}
	}
}

#endif // __icbcInterrputAcknowledge_HPP__
