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
        new Card{ Rank::ACE, Suit::DIAMOND },
        new Card{ Rank::KING, Suit::CLUB },
        new Card{ Rank::QUEEN, Suit::HEART },
        new Card{ Rank::JACK, Suit::HEART },
        new Card{ Rank::NINE, Suit::HEART }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::HIGH_CARD);

    Cards temp({ new Card{ Rank::ACE, Suit::DIAMOND } });

    EXPECT_TRUE(std::equal( std::begin(results.cards), std::end(results.cards),
                            std::begin(temp), std::end(temp),
                            [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; }));
}

TEST_F(TestSuiteValidateHand, Validate_OnePair)
{
    Cards cards({
        new Card{ Rank::ACE, Suit::DIAMOND },
        new Card{ Rank::ACE, Suit::CLUB },
        new Card{ Rank::QUEEN, Suit::HEART },
        new Card{ Rank::JACK, Suit::HEART },
        new Card{ Rank::NINE, Suit::HEART }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::ONE_PAIR);

    Cards temp({ new Card{ Rank::ACE, Suit::DIAMOND }, new Card{ Rank::ACE, Suit::CLUB } });

    EXPECT_TRUE(std::equal( std::begin(results.cards), std::end(results.cards),
                            std::begin(temp), std::end(temp),
                            [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; }));
}

TEST_F(TestSuiteValidateHand, Validate_TwoPair)
{
    Cards cards({
        new Card{ Rank::ACE, Suit::DIAMOND },
        new Card{ Rank::ACE, Suit::CLUB },
        new Card{ Rank::JACK, Suit::CLUB },
        new Card{ Rank::JACK, Suit::HEART },
        new Card{ Rank::NINE, Suit::HEART }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::TWO_PAIR);

    Cards temp({ new Card{ Rank::ACE, Suit::DIAMOND }, new Card{ Rank::ACE, Suit::CLUB }, new Card{ Rank::JACK, Suit::CLUB }, new Card{ Rank::JACK, Suit::HEART } });

    EXPECT_TRUE(std::equal( std::begin(results.cards), std::end(results.cards),
                            std::begin(temp), std::end(temp),
                            [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; }));
}

TEST_F(TestSuiteValidateHand, Validate_ThreeOfAKind)
{
    Cards cards({
        new Card{ Rank::ACE, Suit::DIAMOND },
        new Card{ Rank::KING, Suit::CLUB },
        new Card{ Rank::JACK, Suit::CLUB },
        new Card{ Rank::JACK, Suit::HEART },
        new Card{ Rank::JACK, Suit::DIAMOND }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::THREE_OF_A_KIND);

    Cards temp({ new Card{ Rank::JACK, Suit::CLUB }, new Card{ Rank::JACK, Suit::HEART },new Card{ Rank::JACK, Suit::DIAMOND } });

    EXPECT_TRUE(std::equal( std::begin(results.cards), std::end(results.cards),
                            std::begin(temp), std::end(temp),
                            [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; }));
}

TEST_F(TestSuiteValidateHand, Validate_Straight)
{
    Cards cards({
        new Card{ Rank::KING, Suit::DIAMOND },
        new Card{ Rank::QUEEN, Suit::CLUB },
        new Card{ Rank::JACK, Suit::CLUB },
        new Card{ Rank::TEN, Suit::HEART },
        new Card{ Rank::NINE, Suit::DIAMOND }
    });

    ValidatedHand results = ValidateHand::DetermineHandRank(cards);

    EXPECT_TRUE(results.rank == HandRank::STRAIGHT);
    
    Cards temp({ new Card{ Rank::KING, Suit::DIAMOND }, new Card{ Rank::QUEEN, Suit::CLUB },new Card{ Rank::JACK, Suit::CLUB }, new Card{ Rank::TEN, Suit::HEART }, new Card{ Rank::NINE, Suit::DIAMOND } });

    EXPECT_TRUE(std::equal( std::begin(results.cards), std::end(results.cards),
                            std::begin(temp), std::end(temp),
                            [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; }));
}

// }  // namespace - could surround Project1Test in a namespace