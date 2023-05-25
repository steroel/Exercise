#ifndef __icTimer_HPP__
#define __icTimer_HPP__

namespace Platform
{
	namespace Hardware_Abstraction
	{
		namespace Device_Driver_Abstraction
		{
			class icTimer
			{
				public:
					virtual void start(void) volatile =0;
					virtual void stop(void) volatile =0;
			};
		}
	}
}

#endif // __icTimer_HPP__
