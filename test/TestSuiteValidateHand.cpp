#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Cards.hpp"
#include "ValidateHand.hpp"

class TestSuiteValidateHand : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteValidateHand() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteValidateHand() {
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
TEST_F(TestSuiteValidateHand, Validate_HighCard)
{
    Cards cards({
        { Rank::ACE, Suit::DIAMOND },
        { Rank::KING, Suit::CLUB },
        { Rank::QUEEN, Suit::HEART },
        { Rank::JACK, Suit::HEART },
        { Rank::NINE, Suit::HEART }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::HIGH_CARD);
    EXPECT_TRUE(results.cards == Cards({ { Rank::ACE, Suit::DIAMOND } }));
}

TEST_F(TestSuiteValidateHand, Validate_OnePair)
{
    Cards cards({
        { Rank::ACE, Suit::DIAMOND },
        { Rank::ACE, Suit::CLUB },
        { Rank::QUEEN, Suit::HEART },
        { Rank::JACK, Suit::HEART },
        { Rank::NINE, Suit::HEART }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::ONE_PAIR);
    EXPECT_TRUE(results.cards == Cards({ { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB } }));
}

TEST_F(TestSuiteValidateHand, Validate_TwoPair)
{
    Cards cards({
        { Rank::ACE, Suit::DIAMOND },
        { Rank::ACE, Suit::CLUB },
        { Rank::JACK, Suit::CLUB },
        { Rank::JACK, Suit::HEART },
        { Rank::NINE, Suit::HEART }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::TWO_PAIR);
    EXPECT_TRUE(results.cards == Cards({ { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB }, { Rank::JACK, Suit::CLUB }, { Rank::JACK, Suit::HEART } }));
}

TEST_F(TestSuiteValidateHand, Validate_ThreeOfAKind)
{
    Cards cards({
        { Rank::ACE, Suit::DIAMOND },
        { Rank::KING, Suit::CLUB },
        { Rank::JACK, Suit::CLUB },
        { Rank::JACK, Suit::HEART },
        { Rank::JACK, Suit::DIAMOND }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::THREE_OF_A_KIND);
    EXPECT_TRUE(results.cards == Cards({ { Rank::JACK, Suit::CLUB }, { Rank::JACK, Suit::HEART },{ Rank::JACK, Suit::DIAMOND } }));
}

TEST_F(TestSuiteValidateHand, Validate_Straight)
{
    Cards cards({
        { Rank::KING, Suit::DIAMOND },
        { Rank::QUEEN, Suit::CLUB },
        { Rank::JACK, Suit::CLUB },
        { Rank::TEN, Suit::HEART },
        { Rank::NINE, Suit::DIAMOND }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::STRAIGHT);
    EXPECT_TRUE(results.cards == Cards({ { Rank::KING, Suit::DIAMOND }, { Rank::QUEEN, Suit::CLUB },{ Rank::JACK, Suit::CLUB }, { Rank::TEN, Suit::HEART }, { Rank::NINE, Suit::DIAMOND } }));
}

// }  // namespace - could surround Project1Test in a namespace