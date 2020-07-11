#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Hand.hpp"

class TestSuiteWinningHands : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteWinningHands() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteWinningHands() {
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
TEST_F(TestSuiteWinningHands, TestEquality)
{
    OnePairHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::TEN, Suit::SPADE },
            new Card{ Rank::TEN, Suit::DIAMOND },
            new Card{ Rank::EIGHT, Suit::DIAMOND },
            new Card{ Rank::SIX, Suit::SPADE },
            new Card{ Rank::FOUR, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::CLUB }
        },
        {
            new Card{ Rank::TEN, Suit::SPADE },
            new Card{ Rank::TEN, Suit::DIAMOND }
        });
    
    OnePairHand hand2( 1,
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::TEN, Suit::HEART },
            new Card{ Rank::TEN, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::SPADE },
            new Card{ Rank::SIX, Suit::DIAMOND },
            new Card{ Rank::FOUR, Suit::CLUB },
            new Card{ Rank::TWO, Suit::SPADE }
        },
        {
            new Card{ Rank::TEN, Suit::SPADE },
            new Card{ Rank::TEN, Suit::DIAMOND }
        });
    
    HighCardHand hand3( 2,
        {
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::SPADE },
            new Card{ Rank::NINE, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::FIVE, Suit::SPADE },
            new Card{ Rank::THREE, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::HEART }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });

	Hands hands{ hand3, hand1, hand2 };

    EXPECT_TRUE(hand1 == hand2);
    EXPECT_TRUE(hand1 > hand3);
    EXPECT_TRUE(hand2 > hand3);

    std::sort(hands.begin(), hands.end(), std::greater<Hand>());
    Hands::iterator it1 = std::adjacent_find(hands.begin(), hands.end());
    if( it1 != hands.begin() )
    {
        // this means that there was only one winner
        
    }
    else
    {
        std::cout << "multiple winners" << std::endl;
    }
}

// }  // namespace - could surround Project1Test in a namespace
