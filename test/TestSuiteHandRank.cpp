#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "HandRank.hpp"

class TestSuiteHandRank : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteHandRank() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteHandRank() {
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
TEST_F(TestSuiteHandRank, TestEquality)
{
	EXPECT_TRUE(HandRank::ROYAL_FLUSH == HandRank::ROYAL_FLUSH);
}

TEST_F(TestSuiteHandRank, TestInEquality)
{
	EXPECT_TRUE(HandRank::ROYAL_FLUSH != HandRank::STRAIGHT_FLUSH);
}

TEST_F(TestSuiteHandRank, TestRanking)
{
	EXPECT_TRUE(HandRank::ROYAL_FLUSH > HandRank::STRAIGHT_FLUSH);
	EXPECT_TRUE(HandRank::STRAIGHT_FLUSH > HandRank::STRAIGHT_FLUSH_ACE_LOW);
	EXPECT_TRUE(HandRank::STRAIGHT_FLUSH_ACE_LOW > HandRank::FOUR_OF_A_KIND);
	EXPECT_TRUE(HandRank::FOUR_OF_A_KIND > HandRank::FULL_HOUSE);
	EXPECT_TRUE(HandRank::FULL_HOUSE > HandRank::FLUSH);
	EXPECT_TRUE(HandRank::FLUSH > HandRank::STRAIGHT);
	EXPECT_TRUE(HandRank::STRAIGHT > HandRank::STRAIGHT_ACE_LOW);
	EXPECT_TRUE(HandRank::STRAIGHT_ACE_LOW > HandRank::THREE_OF_A_KIND);
	EXPECT_TRUE(HandRank::THREE_OF_A_KIND > HandRank::TWO_PAIR);
	EXPECT_TRUE(HandRank::TWO_PAIR > HandRank::ONE_PAIR);
	EXPECT_TRUE(HandRank::ONE_PAIR > HandRank::HIGH_CARD);
}

// }  // namespace - could surround Project1Test in a namespace