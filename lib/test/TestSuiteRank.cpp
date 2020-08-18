#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Rank.hpp"

class TestSuiteRank : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteRank() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteRank() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case for Project1.
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(TestSuiteRank, TestEquality)
{
	EXPECT_TRUE(Rank::ACE == Rank::ACE);
}

TEST_F(TestSuiteRank, TestInEquality)
{
	EXPECT_TRUE(Rank::ACE != Rank::KING);
}

TEST_F(TestSuiteRank, TestRanking)
{
	EXPECT_TRUE(Rank::ACE > Rank::KING);
	EXPECT_TRUE(Rank::KING > Rank::QUEEN);
	EXPECT_TRUE(Rank::QUEEN > Rank::JACK);
	EXPECT_TRUE(Rank::JACK > Rank::TEN);
	EXPECT_TRUE(Rank::TEN > Rank::NINE);
	EXPECT_TRUE(Rank::NINE > Rank::EIGHT);
	EXPECT_TRUE(Rank::EIGHT > Rank::SEVEN);
	EXPECT_TRUE(Rank::SEVEN > Rank::SIX);
	EXPECT_TRUE(Rank::SIX > Rank::FIVE);
	EXPECT_TRUE(Rank::FIVE > Rank::FOUR);
	EXPECT_TRUE(Rank::FOUR > Rank::THREE);
	EXPECT_TRUE(Rank::THREE > Rank::TWO);
}

// }  // namespace - could surround Project1Test in a namespace