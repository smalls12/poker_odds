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
TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraight_Ace_High)
{
	Cards cards{{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::HEART },
		new Card{ Rank::JACK, Suit::SPADE },
		new Card{ Rank::TEN, Suit::HEART }
	}};

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT);
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraight_Ace_Low)
{
	Cards cards{{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::FIVE, Suit::CLUB },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::SPADE },
		new Card{ Rank::TWO, Suit::HEART }
	}};

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_ACE_LOW);

	std::cout << (*result).rank << std::endl;
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindARoyalFlush)
{
	Cards cards{{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::DIAMOND },
		new Card{ Rank::QUEEN, Suit::DIAMOND },
		new Card{ Rank::JACK, Suit::DIAMOND },
		new Card{ Rank::TEN, Suit::DIAMOND }
	}};

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::ROYAL_FLUSH);
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraightFlush)
{
	Cards cards{{
		new Card{ Rank::KING, Suit::DIAMOND },
		new Card{ Rank::QUEEN, Suit::DIAMOND },
		new Card{ Rank::JACK, Suit::DIAMOND },
		new Card{ Rank::TEN, Suit::DIAMOND },
		new Card{ Rank::NINE, Suit::DIAMOND }
	}};

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_FLUSH);
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraightFlushAceLow)
{
	Cards cards{{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::FIVE, Suit::DIAMOND },
		new Card{ Rank::FOUR, Suit::DIAMOND },
		new Card{ Rank::THREE, Suit::DIAMOND },
		new Card{ Rank::TWO, Suit::DIAMOND }
	}};

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_FLUSH_ACE_LOW);
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindAFlush)
{
	Cards cards{{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::DIAMOND },
		new Card{ Rank::QUEEN, Suit::DIAMOND },
		new Card{ Rank::JACK, Suit::DIAMOND },
		new Card{ Rank::NINE, Suit::DIAMOND }
	}};

	// sort first
    std::sort(cards.begin(), cards.end());

	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::FLUSH);
}

// }  // namespace - could surround Project1Test in a namespace