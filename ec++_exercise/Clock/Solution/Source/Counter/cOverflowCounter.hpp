#ifndef __cOverflowCounter_HPP__
#define __cOverflowCounter_HPP__

#include "cLimitCounter.hpp"

namespace Counter
{
	class cOverflowCounter final : public cLimitCounter
	{
		public:
			cOverflowCounter(const uint32_t CountValue, const uint32_t CountLimit, cLimitCounter& refNextCounter);
			~cOverflowCounter() override =default;
		
			void resetCountValue(void) override final;
			void count(void) override final;

		private:
			cLimitCounter& mrefNextCounter;
	};
}

#endif // __cOverflowCounter_HPP__
