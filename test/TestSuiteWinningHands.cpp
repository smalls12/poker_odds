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
            { Rank::ACE, Suit::DIAMOND },
            { Rank::TEN, Suit::SPADE },
            { Rank::TEN, Suit::DIAMOND },
            { Rank::EIGHT, Suit::DIAMOND },
            { Rank::SIX, Suit::SPADE },
            { Rank::FOUR, Suit::DIAMOND },
            { Rank::TWO, Suit::CLUB }
        },
        {
            { Rank::TEN, Suit::SPADE },
            { Rank::TEN, Suit::DIAMOND }
        });
    
    OnePairHand hand2( 1,
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::TEN, Suit::HEART },
            { Rank::TEN, Suit::CLUB },
            { Rank::EIGHT, Suit::SPADE },
            { Rank::SIX, Suit::DIAMOND },
            { Rank::FOUR, Suit::CLUB },
            { Rank::TWO, Suit::SPADE }
        },
        {
            { Rank::TEN, Suit::SPADE },
            { Rank::TEN, Suit::DIAMOND }
        });
    
    HighCardHand hand3( 2,
        {
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::JACK, Suit::SPADE },
            { Rank::NINE, Suit::DIAMOND },
            { Rank::SEVEN, Suit::HEART },
            { Rank::FIVE, Suit::SPADE },
            { Rank::THREE, Suit::DIAMOND },
            { Rank::TWO, Suit::HEART }
        },
        {
            { Rank::ACE, Suit::DIAMOND }
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
