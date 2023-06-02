#include <string>
#include <stdexcept>
using namespace std;

class SimilarityChecker
{

public:
	int checkLength(string str1, string str2)
	{
		int str1Len = (int)str1.length();
		int str2Len = (int)str2.length();
		int gap;
		int shortStrLen;
		if(str1Len >= str2Len)
		{
			gap = str1Len - str2Len;
			shortStrLen = str2Len;
		}
		else
		{
			gap = str2Len - str1Len;
			shortStrLen = str1Len;
		}

		if (gap == 0)
			return 60;

		return (int)((1.0f - (float)gap / (float)shortStrLen) * 60);

	}
	int checkStr(string str1, string str2)
	{
		assertIllegalArgument(str1);
		assertIllegalArgument(str2);

		int lenScore = checkLength(str1, str2);

		return lenScore;
	}
private:
	bool isUpperCaseAlphaBet(string inputStr) {
		for (char ch : inputStr) {
			if (ch >= 'A' && ch <= 'Z') continue;
			return true;
		}
		return false;
	}

	void assertIllegalArgument(string inputStr) {
		if (inputStr == "") {
			throw std::invalid_argument("값을 넣어야함");
		}
		if (isUpperCaseAlphaBet(inputStr)) {
			throw std::invalid_argument("대문자알파벳이 아님");
		}
	}
};