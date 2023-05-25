#ifndef __cLimitCounter_HPP__
#define __cLimitCounter_HPP__

#include "TypeDefinitions.hpp"

namespace Counter
{
	class cLimitCounter
	{
		public:
			explicit cLimitCounter(const uint32_t CountValue, const uint32_t CountLimit) noexcept;
			virtual ~cLimitCounter() =default;

			void setCountValue(const uint32_t CountValue) noexcept;
			uint32_t getCountValue(void) const noexcept;
			
			virtual void resetCountValue(void) noexcept(true);
			virtual void count(void) noexcept(false);

		protected:
			uint32_t mCountValue;
			const uint32_t mCountLimit;
	};
}
#endif // __cLimitCounter_HPP__
