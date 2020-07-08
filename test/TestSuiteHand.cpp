#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Hand.hpp"

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

TEST_F(TestSuiteHand, TestEquality_OnePair_HighCard)
{
    OnePairHand hand1( 0,
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

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair)
{
    OnePairHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE },
            { Rank::QUEEN, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            { Rank::KING, Suit::CLUB },
            { Rank::KING, Suit::DIAMOND },
            { Rank::JACK, Suit::CLUB }
        },
        {
            { Rank::KING, Suit::CLUB },
            { Rank::KING, Suit::DIAMOND }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_HighCard_LowerPair)
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

    OnePairHand hand2( 0,
        {
            { Rank::KING, Suit::CLUB },
            { Rank::JACK, Suit::DIAMOND },
            { Rank::JACK, Suit::CLUB },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::FOUR, Suit::SPADE },
            { Rank::THREE, Suit::DIAMOND },
            { Rank::TWO, Suit::SPADE }
        },
        {
            { Rank::JACK, Suit::DIAMOND },
            { Rank::JACK, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_SameValidatedCards)
{
    OnePairHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE },
            { Rank::QUEEN, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART },
            { Rank::JACK, Suit::CLUB }
        },
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_SameValidatedCards_7cards_v1)
{
    OnePairHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::JACK, Suit::DIAMOND },
            { Rank::TEN, Suit::SPADE },
            { Rank::NINE, Suit::DIAMOND },
            { Rank::EIGHT, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::CLUB },
            { Rank::TEN, Suit::CLUB },
            { Rank::NINE, Suit::CLUB },
            { Rank::SEVEN, Suit::CLUB }
        },
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_SameValidatedCards_7cards_v2)
{
    OnePairHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::FIVE, Suit::DIAMOND },
            { Rank::FOUR, Suit::SPADE },
            { Rank::THREE, Suit::DIAMOND },
            { Rank::TWO, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART },
            { Rank::JACK, Suit::CLUB },
            { Rank::TEN, Suit::CLUB },
            { Rank::NINE, Suit::CLUB },
            { Rank::EIGHT, Suit::CLUB },
            { Rank::SEVEN, Suit::CLUB }
        },
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART }
        });

    EXPECT_TRUE(hand1 > hand2);
}

// the hand isn't sorted so hand2 is bigger than hand1
TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_SameValidatedCards_7cards_v3)
{
    OnePairHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE },
            { Rank::FIVE, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::FOUR, Suit::SPADE },
            { Rank::THREE, Suit::DIAMOND },
            { Rank::TWO, Suit::DIAMOND }
        },
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART },
            { Rank::JACK, Suit::CLUB },
            { Rank::TEN, Suit::CLUB },
            { Rank::NINE, Suit::CLUB },
            { Rank::EIGHT, Suit::CLUB },
            { Rank::SEVEN, Suit::CLUB }
        },
        {
            { Rank::ACE, Suit::CLUB },
            { Rank::ACE, Suit::HEART }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_OnePair)
{
    TwoPairHand hand1( 0,
        {
            { Rank::KING, Suit::HEART },
            { Rank::KING, Suit::SPADE },
            { Rank::QUEEN, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::DIAMOND }
        },
        {
            { Rank::KING, Suit::HEART },
            { Rank::KING, Suit::SPADE },
            { Rank::QUEEN, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB }
        });

    OnePairHand hand2( 0,
        {
            { Rank::KING, Suit::CLUB },
            { Rank::KING, Suit::DIAMOND },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::CLUB }
        },
        {
            { Rank::KING, Suit::CLUB },
            { Rank::KING, Suit::DIAMOND }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_TwoPair_v1)
{
    TwoPairHand hand1( 0,
        {
            { Rank::KING, Suit::HEART },
            { Rank::KING, Suit::SPADE },
            { Rank::QUEEN, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::DIAMOND }
        },
        {
            { Rank::KING, Suit::HEART },
            { Rank::KING, Suit::SPADE },
            { Rank::QUEEN, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB }
        });

    TwoPairHand hand2( 0,
        {
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::QUEEN, Suit::SPADE },
            { Rank::JACK, Suit::HEART },
            { Rank::JACK, Suit::CLUB },
            { Rank::TEN, Suit::DIAMOND }
        },
        {
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::QUEEN, Suit::SPADE },
            { Rank::JACK, Suit::HEART },
            { Rank::JACK, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_TwoPair_v2)
{
    TwoPairHand hand1( 0,
        {
            { Rank::THREE, Suit::HEART },
            { Rank::THREE, Suit::SPADE },
            { Rank::FOUR, Suit::HEART },
            { Rank::FOUR, Suit::CLUB },
            { Rank::JACK, Suit::DIAMOND }
        },
        {
            { Rank::THREE, Suit::HEART },
            { Rank::THREE, Suit::SPADE },
            { Rank::FOUR, Suit::HEART },
            { Rank::FOUR, Suit::CLUB }
        });

    TwoPairHand hand2( 0,
        {
            { Rank::TWO, Suit::CLUB },
            { Rank::TWO, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::QUEEN, Suit::SPADE },
            { Rank::TEN, Suit::DIAMOND }
        },
        {
            { Rank::TWO, Suit::CLUB },
            { Rank::TWO, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::QUEEN, Suit::SPADE }
        });

    EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_TwoPair_SameValidatedCards)
{
    TwoPairHand hand1( 0,
        {
            { Rank::KING, Suit::HEART },
            { Rank::KING, Suit::SPADE },
            { Rank::QUEEN, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::DIAMOND }
        },
        {
            { Rank::KING, Suit::HEART },
            { Rank::KING, Suit::SPADE },
            { Rank::QUEEN, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB }
        });

    TwoPairHand hand2( 0,
        {
            { Rank::KING, Suit::CLUB },
            { Rank::KING, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::QUEEN, Suit::SPADE },
            { Rank::TEN, Suit::DIAMOND }
        },
        {
            { Rank::KING, Suit::CLUB },
            { Rank::KING, Suit::DIAMOND },
            { Rank::QUEEN, Suit::DIAMOND },
            { Rank::QUEEN, Suit::SPADE }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_TwoPair)
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

    TwoPairHand hand2( 0,
        {
            { Rank::KING, Suit::HEART },
            { Rank::KING, Suit::SPADE },
            { Rank::QUEEN, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB },
            { Rank::JACK, Suit::DIAMOND }
        },
        {
            { Rank::KING, Suit::HEART },
            { Rank::KING, Suit::SPADE },
            { Rank::QUEEN, Suit::HEART },
            { Rank::QUEEN, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_ThreeOfAKind_v1)
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

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_ThreeOfAKind_v2)
{
    ThreeOfAKindHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::KING, Suit::CLUB },
            { Rank::SEVEN, Suit::HEART },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::SEVEN, Suit::CLUB }
        },
        {
            { Rank::SEVEN, Suit::HEART },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::SEVEN, Suit::CLUB }
        });

    ThreeOfAKindHand hand2( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::EIGHT, Suit::CLUB },
            { Rank::SEVEN, Suit::HEART },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::SEVEN, Suit::CLUB }
        },
        {
            { Rank::SEVEN, Suit::HEART },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::SEVEN, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_ThreeOfAKind_v3)
{
    ThreeOfAKindHand hand1( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::KING, Suit::CLUB },
            { Rank::SEVEN, Suit::HEART },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::SEVEN, Suit::CLUB }
        },
        {
            { Rank::SEVEN, Suit::HEART },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::SEVEN, Suit::CLUB }
        });

    ThreeOfAKindHand hand2( 0,
        {
            { Rank::ACE, Suit::DIAMOND },
            { Rank::TWO, Suit::CLUB },
            { Rank::SEVEN, Suit::HEART },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::SEVEN, Suit::CLUB }
        },
        {
            { Rank::SEVEN, Suit::HEART },
            { Rank::SEVEN, Suit::DIAMOND },
            { Rank::SEVEN, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}












// }  // namespace - could surround Project1Test in a namespace