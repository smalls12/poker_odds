#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "HighCardHand.hpp"
#include "TwoPairHand.hpp"
#include "ThreeOfAKindHand.hpp"

class TestSuiteHand : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteHand() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteHand() {
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
TEST_F(TestSuiteHand, TestEquality)
{
    HighCardHand hand( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::KING, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } }, { { Rank::ACE, Suit::DIAMOND } } );
	EXPECT_TRUE(hand == hand);
}

TEST_F(TestSuiteHand, TestEquality_Card_SameRank_DifferentSuits)
{
    HighCardHand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::KING, Suit::DIAMOND }, { Rank::QUEEN, Suit::DIAMOND } }, { { Rank::ACE, Suit::DIAMOND } } );
    HighCardHand hand2( 0, { { Rank::ACE, Suit::CLUB }, { Rank::KING, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } }, { { Rank::ACE, Suit::DIAMOND } } );
	EXPECT_TRUE(hand1 == hand2);
}

TEST_F(TestSuiteHand, TestInEquality_Card_SameSuit_DifferentRanks)
{
    HighCardHand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::KING, Suit::DIAMOND }, { Rank::QUEEN, Suit::DIAMOND } }, { { Rank::ACE, Suit::DIAMOND } } );
    HighCardHand hand2( 0, { { Rank::JACK, Suit::DIAMOND }, { Rank::TEN, Suit::DIAMOND }, { Rank::NINE, Suit::DIAMOND } }, { { Rank::ACE, Suit::DIAMOND } } );
	EXPECT_TRUE(hand1 != hand2);
}

TEST_F(TestSuiteHand, TestEquality_HighCard_HighCard)
{
    HighCardHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::KING, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND }
        });

    HighCardHand hand2( 0,
        {
            { Rank::KING, Suit::CLUB },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::CLUB }
        },
        {
            { Rank::KING, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_HighCard_HighCard_SameValidatedCards_3cards)
{
    HighCardHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::KING, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND }
        });

    HighCardHand hand2( 0,
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::KING, Suit::CLUB },
            { Rank::JACK, Suit::CLUB }
        },
        {
            { Rank::ACE, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_HighCard_HighCard_SameValidatedCards_5cards)
{
    HighCardHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::KING, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::JACK, Suit::DIAMOND },
            { Rank::NINE, Suit::CLUB }
        },
        {
            { Rank::ACE, Suit::DIAMOND }
        });

    HighCardHand hand2( 0,
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::KING, Suit::CLUB },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::CLUB },
            { Rank::EIGHT, Suit::HEART }
        },
        {
            { Rank::ACE, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_HighCard)
{
    TwoPairHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE },
            { Rank::QUEEN, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE }
        });

    HighCardHand hand2( 0,
        {
            { Rank::KING, Suit::CLUB },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::CLUB }
        },
        {
            { Rank::KING, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_HighCard)
{
    ThreeOfAKindHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART },
            { Rank::KING, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART } 
        });

    HighCardHand hand2( 0,
        {
            { Rank::JACK, Suit::DIAMOND },
            { Rank::TEN, Suit::DIAMOND },
            { Rank::NINE, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND }
        } );

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_ThreeOfAKind)
{
    ThreeOfAKindHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART },
            { Rank::KING, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART } 
        });

    ThreeOfAKindHand hand2( 0,
        {
            { Rank::KING, Suit::DIAMOND },
            { Rank::KING, Suit::CLUB },
            { Rank::KING, Suit::HEART },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::JACK, Suit::DIAMOND }
        },
        {
            { Rank::KING, Suit::DIAMOND },
            { Rank::KING, Suit::CLUB },
            { Rank::KING, Suit::HEART } 
        });

	EXPECT_TRUE(hand1 > hand2);
}












// }  // namespace - could surround Project1Test in a namespace