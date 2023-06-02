#include <string>
#include <stdexcept>
using namespace std;

class SimilarityChecker
{

public:
	int checkStr(string str1, string str2)
	{
		assertIllegalArgument(str1);
		assertIllegalArgument(str2);


		return 0;
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