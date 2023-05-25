#ifndef __iBasicIO_HPP__
#define __iBasicIO_HPP__

#include "TypeDefinitions.hpp"

namespace Platform
{
	namespace Hardware_Abstraction
	{
		void showValue(const char* ptrText, const int8_t Number);
		void showValue(const char* ptrText, const int16_t Number);
		void showValue(const char* ptrText, const int32_t Number);
		void showValue(const char* ptrText, const int64_t Number);
		void showValue(const char* ptrText, const uint8_t Number);
		void showValue(const char* ptrText, const uint16_t Number);
		void showValue(const char* ptrText, const uint32_t Number);
		void showValue(const char* ptrText, const uint64_t Number);

		//void showValue(const char* ptrText, const double Number);
		void showValue(const char* ptrText, const bool Evaluation);

		void showValue(const char* ptrText1, const int8_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, const int16_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, const int32_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, const int64_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, const uint8_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, const uint16_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, const uint32_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, const uint64_t Number, const char* ptrText2);
		
		//void showValue(const char* ptrText1, double Number, const char* ptrText2);
		void showValue(const char* ptrText1, const bool Evaluation, const char* ptrText2);

		void showValue(const char* ptrText);
		void showValue(const char* ptrText1, const char* ptrText2);

		//void showValue(std::string ptrText);
		//void showValue(std::string ptrText1, std::string ptrText2);

		char getCommand(void);
	}
}

#endif // __iBasicIO_HPP__
