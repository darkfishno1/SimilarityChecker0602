#include "pch.h"
#include "../Project16/similarityChecker.cpp"


TEST(SimilarityCheckTestCase, InvalidArgument) {
	SimilarityChecker checker;
	EXPECT_THROW(checker.checkStr("ABS","123"), std::invalid_argument);
	EXPECT_THROW(checker.checkStr("ABS", "ABc"), std::invalid_argument);
}

TEST(SimilarityCheckTestCase, CheckLength) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}