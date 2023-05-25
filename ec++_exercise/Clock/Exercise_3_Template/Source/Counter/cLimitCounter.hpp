#ifndef __cLinitCounter_HPP__
#define __cLinitCounter_HPP__

#include "TypeDefinitions.hpp"

namespace Counter
{
	class cLimitCounter
	{
		public:
			cLimitCounter(const uint32_t CountValue, const uint32_t CountLimit);
			virtual ~cLimitCounter() =default;

			void setCountValue(const uint32_t CountValue);
			uint32_t getCountValue(void) const;
			uint32_t getCountLimit(void) const;
			void resetCountValue(void);
			void count(void);

		protected:
			uint32_t mCountValue;
			const uint32_t mCountLimit;
	};
}

#endif // __cLinitCounter_HPP__

