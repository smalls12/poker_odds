#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "FindPairs.hpp"

class TestSuiteFindPairs : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteFindPairs() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteFindPairs() {
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
TEST_F(TestSuiteFindPairs, FindFourOfAKind)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::ACE, Suit::HEART },
		{ Rank::ACE, Suit::SPADE },
		{ Rank::KING, Suit::HEART }
	}};

	std::optional<ValidatedHand> result = FindPairs::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::FOUR_OF_A_KIND);
}

TEST_F(TestSuiteFindPairs, FindFullHouse_v1)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::ACE, Suit::HEART },
		{ Rank::KING, Suit::DIAMOND },
		{ Rank::KING, Suit::HEART }
	}};

	std::optional<ValidatedHand> result = FindPairs::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::FULL_HOUSE);
}

TEST_F(TestSuiteFindPairs, FindFullHouse_v2)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::KING, Suit::CLUB },
		{ Rank::KING, Suit::DIAMOND },
		{ Rank::KING, Suit::HEART }
	}};

	std::optional<ValidatedHand> result = FindPairs::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::FULL_HOUSE);
}

TEST_F(TestSuiteFindPairs, FindThreeOfAKind)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::ACE, Suit::HEART },
		{ Rank::KING, Suit::DIAMOND },
		{ Rank::QUEEN, Suit::DIAMOND }
	}};

	std::optional<ValidatedHand> result = FindPairs::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::THREE_OF_A_KIND);
}

TEST_F(TestSuiteFindPairs, FindTwoPair)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::KING, Suit::HEART },
		{ Rank::KING, Suit::DIAMOND },
		{ Rank::QUEEN, Suit::DIAMOND }
	}};

	std::optional<ValidatedHand> result = FindPairs::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::TWO_PAIR);
}

TEST_F(TestSuiteFindPairs, FindOnePair)
{
	std::vector<Card> cards{{
		{ Rank::TWO, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::ACE, Suit::HEART },
		{ Rank::KING, Suit::DIAMOND },
		{ Rank::QUEEN, Suit::DIAMOND }
	}};

	std::optional<ValidatedHand> result = FindPairs::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::ONE_PAIR);
}

// }  // namespace - could surround Project1Test in a namespace