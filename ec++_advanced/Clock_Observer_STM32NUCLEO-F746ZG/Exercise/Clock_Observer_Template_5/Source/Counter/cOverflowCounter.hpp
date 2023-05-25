#ifndef __cOverflowCounter_HPP__
#define __cOverflowCounter_HPP__

#include "cLimitCounter.hpp"

namespace Counter
{
	class cOverflowCounter : public cLimitCounter
	{
		public:
			explicit cOverflowCounter(const uint32_t CountValue, const uint32_t CountLimit, cLimitCounter& refNextCounter);
			~cOverflowCounter() override =default;
			
			void resetCountValue(void) noexcept final;
			void count(void) noexcept(false) final;

		private:
			cLimitCounter& mrefNextCounter;
	};
}

#endif // __cOverflowCounter_HPP__
