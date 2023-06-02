#include <string>
#include <stdexcept>
using namespace std;

#define MAX_ALPHABET 'Z'-'A'

class SimilarityChecker
{
	const int numberOfAlphabet = MAX_ALPHABET;
public:
	void checkStrCount(string str1, int checkListForStr1[MAX_ALPHABET])
	{
		for(char str: str1)
		{
			checkListForStr1[str - 'A'] = 1;
		}
	}

	int checkAlphaetMatching(string str1, string str2)
	{
		int checkListForStr1[MAX_ALPHABET] = { 0, };
		int checkListForStr2[MAX_ALPHABET] = { 0, };

		checkStrCount(str1, checkListForStr1);
		checkStrCount(str2, checkListForStr2);

		int totalCnt = 0;
		int sameCnt = 0;

		for(int n = 0; n < numberOfAlphabet; n++)
		{
			if (checkListForStr1[n] == 1 || checkListForStr2[n] == 1)
				totalCnt++;

			if (checkListForStr1[n] == 1 && checkListForStr2[n] == 1)
				sameCnt++;

		}
		return (int)(((float)sameCnt / (float)totalCnt) * 40.0f);

	}

	
	int checkLength(const string& str1, const string& str2)
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

		return checkLength(str1, str2) + checkAlphaBetMatching(str1, str2);
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
