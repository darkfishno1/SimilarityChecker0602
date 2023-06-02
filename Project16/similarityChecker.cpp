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
			throw std::invalid_argument("���� �־����");
		}
		if (isUpperCaseAlphaBet(inputStr)) {
			throw std::invalid_argument("�빮�ھ��ĺ��� �ƴ�");
		}
	}
};