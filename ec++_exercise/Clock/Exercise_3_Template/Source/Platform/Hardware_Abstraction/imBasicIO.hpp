#ifndef __imBasicIO_HPP__
#define __imBasicIO_HPP__

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

		void showValue(const char* ptrText1, int8_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, int16_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, int32_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, int64_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, uint8_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, uint16_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, uint32_t Number, const char* ptrText2);
		void showValue(const char* ptrText1, uint64_t Number, const char* ptrText2);
		
		//void showValue(const char* ptrText1, double Number, const char* ptrText2);
		void showValue(const char* ptrText1, bool Evaluation, const char* ptrText2);

		void showValue(const char* ptrText);
		void showValue(const char* ptrText1, const char* ptrText2);

		//void showValue(std::string ptrText);
		//void showValue(std::string ptrText1, std::string ptrText2);

		char getCommand(void);
	}
}

#endif // __imBasicIO_HPP__
