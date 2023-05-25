#ifndef __cClockObserverApplicationBuilder_HPP__
#define __cClockObserverApplicationBuilder_HPP__

#include "TypeDefinitions.hpp"

#include<memory>

#include "../Clock/cClock.hpp"
using Clock::cClock;

namespace Clock { class cAnalogClock; }

//class Clock::cAnalogClock;

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
		
			//cAnalogClock*           mptrAnalogClock;
			//cDigitalClock*          mptrDigitalClock;
			//cAnalogDigitalClock*    mptrAnalogDigitalClock;
			//tcClockArray<10>*       mptrClockArray;
			//cClockContainer*        mptrClockContainer;
			//cTickTimer*             mptrTickTimer; 
			//cSTM32F7xxTIMER_Driver* mptrTimer;
		
			std::shared_ptr<cAnalogClock>           mptrAnalogClock;
			std::shared_ptr<cDigitalClock>          mptrDigitalClock;
			std::shared_ptr<cAnalogDigitalClock>    mptrAnalogDigitalClock;
			std::shared_ptr<tcClockArray<10>>       mptrClockArray;
			std::shared_ptr<cClockContainer>        mptrClockContainer;
			std::shared_ptr<cTickTimer>             mptrTickTimer; 
			std::shared_ptr<cSTM32F7xxTIMER_Driver> mptrTimer {nullptr};
		
			void buildRelations(void);
	};
}

#endif //__cClockObserverApplicationBuilder_HPP__
