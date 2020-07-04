#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "CardExactMatch.hpp"
#include "FindHighCard.hpp"

class TestSuiteFindHighCard : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteFindHighCard() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteFindHighCard() {
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
TEST_F(TestSuiteFindHighCard, FindHighCard)
{
	std::vector<Card> cards{{
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::KING, Suit::CLUB },
		{ Rank::QUEEN, Suit::HEART },
		{ Rank::JACK, Suit::SPADE },
		{ Rank::TEN, Suit::HEART }
	}};

	std::optional<ValidatedHand> result = FindHighCard::Find(cards);
	EXPECT_TRUE(result);
	EXPECT_TRUE((*result).rank == HandRank::HIGH_CARD);
	EXPECT_TRUE(CardExactMatch( { (*result).cards[0] }) == CardExactMatch( { { Rank::ACE, Suit::DIAMOND } } ));
}

// }  // namespace - could surround Project1Test in a namespace