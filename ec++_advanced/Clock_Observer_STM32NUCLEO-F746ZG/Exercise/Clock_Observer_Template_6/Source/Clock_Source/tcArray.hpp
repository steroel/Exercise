#ifndef __tcArray_HPP__
#define __tcArray_HPP__

#include "TypeDefinitions.hpp"

#include <stdexcept>

namespace Common
{
	template<typename Element_T, uint32_t ArrayLength>
	class tcArray
	{
		public:
			explicit tcArray(Element_T InitValue);
			virtual ~tcArray() =default;

			void insert(Element_T Element);
			void erase(Element_T Element);
			Element_T& operator[](const uint32_t Index);
			const Element_T& operator[](const uint32_t Index) const;

			// required to operate with range-based for-loop:
			Element_T* begin(void);
			Element_T* end(void);

		private:
			const Element_T mInitValue;
			Element_T mArray[ArrayLength];
	};

	template<typename Element_T, uint32_t ArrayLength>
	tcArray<Element_T, ArrayLength>::tcArray(Element_T InitValue) :
		mInitValue{ InitValue },
		mArray { InitValue }
	{
		//uint32_t locLoopIndex = 0;
		////for (auto& locElement : mArray)
		//for(locLoopIndex = 0; locLoopIndex < ArrayLength; locLoopIndex++)
		////{
			////locElement = InitValue;
			//mArray[locLoopIndex] = InitValue;
		////}
	}

	template<typename Element_T, uint32_t ArrayLength>
	void tcArray<Element_T, ArrayLength>::insert(Element_T Element)
	{
		//uint32_t locLoopIndex = 0;

		if (Element != mInitValue)
		{
			for (auto& locElement : mArray)
			//for(locLoopIndex = 0; locLoopIndex < ArrayLength; ++locLoopIndex)
			{
				if (locElement == mInitValue)
				//if (mArray[locLoopIndex] == mInitValue)
				{
					locElement = Element;
				//	mArray[locLoopIndex] = Element;
					break;
				}
			}
		}
	}

	template<typename Element_T, uint32_t ArrayLength>
	void tcArray<Element_T, ArrayLength>::erase(Element_T Element)
	{
		//uint32_t locLoopIndex = 0;
		if (Element != mInitValue)
		{
			for (auto& locElement : mArray)
			//for(locLoopIndex = 0; locLoopIndex < ArrayLength; locLoopIndex++)
			{
				if (locElement == Element)
				//if (mArray[locLoopIndex] == Element)
				{
					//mArray[locLoopIndex] = mInitValue;
					locElement = mInitValue;
					break;
				}
			}
		}
	}

	template<typename Element_T, uint32_t ArrayLength>
	Element_T& tcArray<Element_T, ArrayLength>::operator[](const uint32_t Index)
	{
		if (Index < ArrayLength)
		{
			return mArray[Index];
		}
		else
		{
			throw(std::range_error{ "Invalid Common::tcArray length" });
		}

		//return mInitValue;
	}

	template<typename Element_T, uint32_t ArrayLength>
	const Element_T& tcArray<Element_T, ArrayLength>::operator[](const uint32_t Index) const
	{
		if (Index < ArrayLength)
		{
			return mArray[Index];
		}
		else
		{
			throw(std::range_error{ "Invalid Common::tcArray length" });
		}

		//return mInitValue;
	}

	template<typename Element_T, uint32_t ArrayLength>
	Element_T* tcArray<Element_T, ArrayLength>::begin(void)
	{
		return &mArray[0]; // returns a pointer to the first element
	}

	template<typename Element_T, uint32_t ArrayLength>
	Element_T* tcArray<Element_T, ArrayLength>::end(void)
	{
		return &mArray[ArrayLength]; // returns a pointer to one past the last element
	}
}

#endif // __tcArray_HPP__
