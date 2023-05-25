#ifndef __tcArray_HPP__
#define __tcArray_HPP__

#include "TypeDefinitions.hpp"

//#include <stdexcept>

namespace Common
{
	template<typename Element_T, uint32_t ArrayLength>
	class tcArray
	{
		public:
			//**
			Element_T& operator[](uint32_t Index);
			const Element_T& operator[](uint32_t Index) const;

		private:
			//**
	};

	//**
}

#endif // __tcArray_HPP__
