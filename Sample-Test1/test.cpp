#include "pch.h"
#include "../Project16/similarityChecker.cpp"


TEST(SimilarityCheckTestCase, InvalidArgument) {
	SimilarityChecker checker;
	EXPECT_THROW(checker.checkStr("ABS","123"), std::invalid_argument);
	EXPECT_THROW(checker.checkStr("ABS", "ABc"), std::invalid_argument);
}

TEST(SimilarityCheckTestCase, CheckLength) {
	SimilarityChecker checker;
	EXPECT_EQ(60, checker.checkStr("AAA", "BBB"));
	EXPECT_EQ(39, checker.checkStr("AAA", "BBBB"));
	EXPECT_EQ(30, checker.checkStr("AA", "BBB"));
	EXPECT_EQ(60, checker.checkStr("AAAA", "BBBB"));
}


TEST(SimilarityCheckTestCase, CheckAlphabet) {
	SimilarityChecker checker;
	EXPECT_EQ(100, checker.checkStr("BBB", "BBB"));
	EXPECT_EQ(100, checker.checkStr("ABCDEFG", "ABCDEFG"));
	EXPECT_EQ(73, checker.checkStr("ABCDEFG", "ABCDEFGHI"));
	EXPECT_EQ(15, checker.checkStr("ABCDEFG", "TTTT"));
}