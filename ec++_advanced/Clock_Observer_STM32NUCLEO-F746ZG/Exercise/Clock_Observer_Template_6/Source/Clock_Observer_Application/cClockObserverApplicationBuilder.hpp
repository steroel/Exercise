#ifndef __cClockObserverApplicationBuilder_HPP__
#define __cClockObserverApplicationBuilder_HPP__

#include "TypeDefinitions.hpp"

//#include<memory>

#include "../Clock/cClock.hpp"
using Clock::cClock;

//** For instantiation on stack, the includes for the corresponding headers are required
//** For instantiation on heap, the forward declaration is enough

//#include "../Clock/cAnalogClock.hpp"
//#include "../Clock/cDigitalClock.hpp"
//#include "../Clock/cAnalogDigitalClock.hpp"

namespace Clock { class cAnalogClock; }
namespace Clock { class cDigitalClock; }
namespace Clock { class cAnalogDigitalClock; }

using Clock::cAnalogClock;
using Clock::cDigitalClock;
using Clock::cAnalogDigitalClock;

namespace Clock_Source { template<uint32_t ArrayLength> class tcClockArray; }
namespace Clock_Source { class cClockContainer; }
namespace Clock_Source { class cTickTimer; }
using Clock_Source::tcClockArray;
using Clock_Source::cClockContainer;
using Clock_Source::cTickTimer;


namespace Platform { namespace Hardware_Abstraction { namespace Device_Driver_Abstraction { namespace STM32F7xx { namespace TIMER { class cSTM32F7xxTIMER_Driver; } }}}}
using Platform::Hardware_Abstraction::Device_Driver_Abstraction::STM32F7xx::TIMER::cSTM32F7xxTIMER_Driver;


namespace Clock_Observer_Application
{
	class cClockObserverApplicationBuilder
	{
		public:
			explicit cClockObserverApplicationBuilder(void);
			~cClockObserverApplicationBuilder();
		
			void execute(void);
				
		private:
			cClock 				          mClock;
		
			cAnalogClock*				  mptrAnalogClock;
			cDigitalClock*				  mptrDigitalClock;
			cAnalogDigitalClock*		  mptrAnalogDigitalClock;

			tcClockArray<10>*			  mptrClockArray;
			cClockContainer*			  mptrClockContainer;

			cTickTimer*		              mptrTickTimer;
			//**
		
			void buildRelations(void);
	};
}

#endif //__cClockObserverApplicationBuilder_HPP__
