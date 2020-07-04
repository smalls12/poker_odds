#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "FindStraightsAndFlushes.hpp"

class TestSuiteFindStraightsAndFlushes : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteFindStraightsAndFlushes() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteFindStraightsAndFlushes() {
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
TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraight)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::KING, Suit::CLUB },
		{ Rank::QUEEN, Suit::HEART },
		{ Rank::JACK, Suit::SPADE },
		{ Rank::TEN, Suit::HEART }
	}};

	// sort first
    std::sort(cards.begin(), cards.end());

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT);
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindARoyalFlush)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::KING, Suit::DIAMOND },
		{ Rank::QUEEN, Suit::DIAMOND },
		{ Rank::JACK, Suit::DIAMOND },
		{ Rank::TEN, Suit::DIAMOND }
	}};

	// sort first
    std::sort(cards.begin(), cards.end());

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::ROYAL_FLUSH);
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraightFlush)
{
	std::vector<Card> cards{{
		{ Rank::KING, Suit::DIAMOND },
		{ Rank::QUEEN, Suit::DIAMOND },
		{ Rank::JACK, Suit::DIAMOND },
		{ Rank::TEN, Suit::DIAMOND },
		{ Rank::NINE, Suit::DIAMOND }
	}};

	// sort first
    std::sort(cards.begin(), cards.end());

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_FLUSH);
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindAFlush)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::KING, Suit::DIAMOND },
		{ Rank::QUEEN, Suit::DIAMOND },
		{ Rank::JACK, Suit::DIAMOND },
		{ Rank::NINE, Suit::DIAMOND }
	}};

	// sort first
    std::sort(cards.begin(), cards.end());

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::FLUSH);
}

// }  // namespace - could surround Project1Test in a namespace