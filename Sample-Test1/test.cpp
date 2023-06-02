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