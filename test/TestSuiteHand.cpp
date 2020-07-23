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
    HighCardHand hand( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::QUEEN, Suit::HEART }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });
    
	EXPECT_TRUE(hand == hand);
}

TEST_F(TestSuiteHand, TestEquality_Card_SameRank_DifferentSuits)
{
    HighCardHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
            },
        {
            new Card{ Rank::ACE, Suit::DIAMOND } 
        });
    
    HighCardHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::QUEEN, Suit::HEART }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });
    
	EXPECT_TRUE(hand1 == hand2);
}

TEST_F(TestSuiteHand, TestInEquality_Card_SameSuit_DifferentRanks)
{
    HighCardHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });
    
    HighCardHand hand2( 0,
        {
            new Card{ Rank::JACK, Suit::DIAMOND },
            new Card{ Rank::TEN, Suit::DIAMOND },
            new Card{ Rank::NINE, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });
    
	EXPECT_TRUE(hand1 != hand2);
}

TEST_F(TestSuiteHand, TestEquality_HighCard_HighCard)
{
    HighCardHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });

    HighCardHand hand2( 0,
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::CLUB }
        },
        {
            new Card{ Rank::KING, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_HighCard_HighCard_SameValidatedCards_3cards)
{
    HighCardHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });

    HighCardHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::JACK, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_HighCard_HighCard_SameValidatedCards_5cards)
{
    HighCardHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::DIAMOND },
            new Card{ Rank::NINE, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });

    HighCardHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::HEART }
        },
        {
            new Card{ Rank::ACE, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_HighCard)
{
    OnePairHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE }
        });

    HighCardHand hand2( 0,
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::CLUB }
        },
        {
            new Card{ Rank::KING, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair)
{
    OnePairHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::CLUB }
        },
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::KING, Suit::DIAMOND }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_HighCard_LowerPair)
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

    OnePairHand hand2( 0,
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::JACK, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::FOUR, Suit::SPADE },
            new Card{ Rank::THREE, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::SPADE }
        },
        {
            new Card{ Rank::JACK, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_SameValidatedCards)
{
    OnePairHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::JACK, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_SameValidatedCards_7cards_v1)
{
    OnePairHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::DIAMOND },
            new Card{ Rank::TEN, Suit::SPADE },
            new Card{ Rank::NINE, Suit::DIAMOND },
            new Card{ Rank::EIGHT, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::CLUB },
            new Card{ Rank::TEN, Suit::CLUB },
            new Card{ Rank::NINE, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_SameValidatedCards_7cards_v2)
{
    OnePairHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::FIVE, Suit::DIAMOND },
            new Card{ Rank::FOUR, Suit::SPADE },
            new Card{ Rank::THREE, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::JACK, Suit::CLUB },
            new Card{ Rank::TEN, Suit::CLUB },
            new Card{ Rank::NINE, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART }
        });

    EXPECT_TRUE(hand1 > hand2);
}

// the hand isn't sorted so hand2 is bigger than hand1
TEST_F(TestSuiteHand, TestEquality_OnePair_OnePair_SameValidatedCards_7cards_v3)
{
    OnePairHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE },
            new Card{ Rank::FIVE, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::FOUR, Suit::SPADE },
            new Card{ Rank::THREE, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::SPADE }
        });

    OnePairHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::JACK, Suit::CLUB },
            new Card{ Rank::TEN, Suit::CLUB },
            new Card{ Rank::NINE, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_OnePair)
{
    TwoPairHand hand1( 0,
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::DIAMOND }
        },
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB }
        });

    OnePairHand hand2( 0,
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::CLUB }
        },
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::KING, Suit::DIAMOND }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_TwoPair_v1)
{
    TwoPairHand hand1( 0,
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::DIAMOND }
        },
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB }
        });

    TwoPairHand hand2( 0,
        {
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::SPADE },
            new Card{ Rank::JACK, Suit::HEART },
            new Card{ Rank::JACK, Suit::CLUB },
            new Card{ Rank::TEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::SPADE },
            new Card{ Rank::JACK, Suit::HEART },
            new Card{ Rank::JACK, Suit::CLUB }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_TwoPair_v2)
{
    TwoPairHand hand1( 0,
        {
            new Card{ Rank::JACK, Suit::DIAMOND },
            new Card{ Rank::FOUR, Suit::HEART },
            new Card{ Rank::FOUR, Suit::CLUB },
            new Card{ Rank::THREE, Suit::HEART },
            new Card{ Rank::THREE, Suit::SPADE }
        },
        {
            new Card{ Rank::FOUR, Suit::HEART },
            new Card{ Rank::FOUR, Suit::CLUB },
            new Card{ Rank::THREE, Suit::HEART },
            new Card{ Rank::THREE, Suit::SPADE }
        });

    TwoPairHand hand2( 1,
        {
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::SPADE },
            new Card{ Rank::TEN, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::CLUB },
            new Card{ Rank::TWO, Suit::DIAMOND }
        },
        {
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::SPADE },
            new Card{ Rank::TWO, Suit::CLUB },
            new Card{ Rank::TWO, Suit::DIAMOND }
        });
    
    EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_TwoPair_OnePair_Equivalent)
{
    TwoPairHand hand1( 0,
        {
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::SPADE },
            new Card{ Rank::SEVEN, Suit::CLUB },
            new Card{ Rank::FOUR, Suit::HEART },
            new Card{ Rank::THREE, Suit::SPADE },
            new Card{ Rank::TWO, Suit::HEART },
            new Card{ Rank::TWO, Suit::SPADE }
        },
        {
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::SPADE },
            new Card{ Rank::TWO, Suit::HEART },
            new Card{ Rank::TWO, Suit::SPADE }
        });

    TwoPairHand hand2( 1,
        {
            new Card{ Rank::JACK, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::SPADE },
            new Card{ Rank::TEN, Suit::DIAMOND },
            new Card{ Rank::TEN, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::FIVE, Suit::HEART },
            new Card{ Rank::TWO, Suit::SPADE }
        },
        {
            new Card{ Rank::JACK, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::SPADE },
            new Card{ Rank::TEN, Suit::DIAMOND },
            new Card{ Rank::TEN, Suit::CLUB }
        });
    
    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_TwoPair_SameValidatedCards)
{
    TwoPairHand hand1( 0,
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::DIAMOND }
        },
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB }
        });

    TwoPairHand hand2( 0,
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::SPADE },
            new Card{ Rank::TEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::SPADE }
        });

    EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_TwoPair)
{
    ThreeOfAKindHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART } 
        });

    TwoPairHand hand2( 0,
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::JACK, Suit::DIAMOND }
        },
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::SPADE },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_ThreeOfAKind_v1)
{
    ThreeOfAKindHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::DIAMOND }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART } 
        });

    ThreeOfAKindHand hand2( 0,
        {
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::DIAMOND }
        },
        {
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::KING, Suit::HEART } 
        });

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_ThreeOfAKind_v2)
{
    ThreeOfAKindHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        });

    ThreeOfAKindHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_ThreeOfAKind_v3)
{
    ThreeOfAKindHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        });

    ThreeOfAKindHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_FullHouse_FullHouse_v1)
{
    FullHouseHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB }
        });

    FullHouseHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::ACE, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_FullHouse_FullHouse_v2)
{
    FullHouseHand hand1( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB }
        });

    FullHouseHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_FullHouse_FullHouse_v3)
{
    FullHouseHand hand1( 0,
        {
            new Card{ Rank::FIVE, Suit::DIAMOND },
            new Card{ Rank::FIVE, Suit::CLUB },
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::KING, Suit::HEART },
            new Card{ Rank::KING, Suit::DIAMOND },
            new Card{ Rank::KING, Suit::CLUB },
            new Card{ Rank::FIVE, Suit::DIAMOND },
            new Card{ Rank::FIVE, Suit::CLUB }
        });

    FullHouseHand hand2( 0,
        {
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB },
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::CLUB }
        },
        {
            new Card{ Rank::QUEEN, Suit::HEART },
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::QUEEN, Suit::CLUB },
            new Card{ Rank::ACE, Suit::DIAMOND },
            new Card{ Rank::ACE, Suit::CLUB }
        });

	EXPECT_TRUE(hand1 > hand2);
}

// }  // namespace - could surround Project1Test in a namespace