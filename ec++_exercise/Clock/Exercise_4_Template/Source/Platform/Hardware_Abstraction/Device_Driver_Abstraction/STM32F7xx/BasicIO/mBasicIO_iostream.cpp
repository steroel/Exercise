#include "..\..\..\imBasicIO.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::flush;

#include <iomanip>
using std::setiosflags;

namespace Platform
{
	namespace Hardware_Abstraction
	{
		void showValue(const char* ptrText, const int8_t Number)
		{
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const int16_t Number)
		{
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const int32_t Number)
		{
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const int64_t Number)
		{
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const uint8_t Number)
		{
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const uint16_t Number)
		{
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const uint32_t Number)
		{
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const uint64_t Number)
		{
			//cout << ptrText << hex << number << " ";
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const double Number)
		{
			cout << ptrText << " " << Number << " ";
		}

		void showValue(const char* ptrText, const bool Evaluation)
		{
			if (Evaluation == true)
			{
				cout << ptrText << " ";
			}
		}

		void showValue(const char* ptrText1, int8_t Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, int16_t Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, int32_t Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, int64_t Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, uint8_t Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, uint16_t Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, uint32_t Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, uint64_t Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, double Number, const char* ptrText2)
		{
			cout << ptrText1 << Number << ptrText2;
		}

		void showValue(const char* ptrText1, bool Evaluation, const char* ptrText2)
		{
			if (Evaluation == true) cout << ptrText1 << ptrText2;
		}

		void showValue(const char* ptrText)
		{
			cout << ptrText << " ";
		}

		void showValue(const char* ptrText1, const char* ptrText2)
		{
			cout << ptrText1 << ptrText2 << " ";
		}

//		void showValue(std::string ptrText)
//		{
//			cout << ptrText;
//		}

//		void showValue(std::string ptrText1, std::string ptrText2)
//		{
//			cout << ptrText1 << ptrText2 << " ";
//		}

		char getCommand(void)
		{
			char locCharacter = 0;
			char locTemp = 0;

			cout << "\n::> " << flush;

			while (true)
			{
				cin.clear();
				switch (cin.get())
				{
					case '1': case 'A': case 'a': locCharacter = 'A'; break;
					case '2': case 'B': case 'b': locCharacter = 'B'; break;
					case '3': case 'C': case 'c': locCharacter = 'C'; break;
					case '4': case 'D': case 'd': locCharacter = 'D'; break;
					case '5': case 'E': case 'e': locCharacter = 'E'; break;
					case '6': case 'F': case 'f': locCharacter = 'F'; break;
					case '7': case 'G': case 'g': locCharacter = 'G'; break;
					case '8': case 'H': case 'h': locCharacter = 'H'; break;
					case '9': case 'I': case 'i': locCharacter = 'I'; break;
					case '0': case 'J': case 'j': locCharacter = 'J'; break;
										case 'K': case 'k': locCharacter = 'K'; break;
										case 'L': case 'l': locCharacter = 'L'; break;
										case 'M': case 'm': locCharacter = 'M'; break;
										case 'N': case 'n': locCharacter = 'N'; break;
										case 'O': case 'o': locCharacter = 'O'; break;
										case 'P': case 'p': locCharacter = 'P'; break;
										case 'Q': case 'q': locCharacter = 'Q'; break;
										case 'R': case 'r': locCharacter = 'R'; break;
										case 'S': case 's': locCharacter = 'S'; break;
										case 'T': case 't': locCharacter = 'T'; break;
										case 'U': case 'u': locCharacter = 'U'; break;
										case 'V': case 'v': locCharacter = 'V'; break;
										case 'W': case 'w': locCharacter = 'W'; break;
										case 'X': case 'x': locCharacter = 'X'; break;
										case 'Y': case 'y': locCharacter = 'Y'; break;
										case 'Z': case 'z': locCharacter = 'Z'; break;
					case '\n':
						locTemp = locCharacter;
						locCharacter = 0;
						return locTemp;
					break;
					default:
						showValue("\nError: Unsupported input!");
						return 0;
					break;
				}
			}
		}
	}
}
