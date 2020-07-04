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
    Hand hand( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB }, { Rank::ACE, Suit::HEART } } );
	EXPECT_TRUE(hand == hand);
}

TEST_F(TestSuiteHand, TestEquality_Card_SameRank_DifferentSuits)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::KING, Suit::DIAMOND }, { Rank::QUEEN, Suit::DIAMOND } } );
    Hand hand2( 0, { { Rank::ACE, Suit::CLUB }, { Rank::KING, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } );
	EXPECT_TRUE(hand1 == hand2);
}

TEST_F(TestSuiteHand, TestInEquality_Card_SameSuit_DifferentRanks)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::KING, Suit::DIAMOND }, { Rank::QUEEN, Suit::DIAMOND } } );
    Hand hand2( 0, { { Rank::JACK, Suit::DIAMOND }, { Rank::TEN, Suit::DIAMOND }, { Rank::NINE, Suit::DIAMOND } } );
	EXPECT_TRUE(hand1 != hand2);
}

TEST_F(TestSuiteHand, TestHighHandRank_HighCard_HighCard)
{
    Hand hand1( 0, { { Rank::KING, Suit::DIAMOND }, { Rank::QUEEN, Suit::SPADE }, { Rank::JACK, Suit::HEART } } );
    Hand hand2( 0, { { Rank::ACE, Suit::CLUB }, { Rank::KING, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } );
	EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestHighHandRank_OnePair_HighCard)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::SPADE }, { Rank::KING, Suit::HEART } } );
    Hand hand2( 0, { { Rank::ACE, Suit::CLUB }, { Rank::KING, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } );
	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestHighHandRank_OnePair_OnePair)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::SPADE }, { Rank::KING, Suit::HEART } } );
    Hand hand2( 0, { { Rank::KING, Suit::DIAMOND }, { Rank::KING, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } );
	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestHighHandRank_OnePair_OnePair_SameCardRanks)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::SPADE }, { Rank::KING, Suit::HEART } } );
    Hand hand2( 0, { { Rank::ACE, Suit::HEART }, { Rank::ACE, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } );
	EXPECT_TRUE(hand1 > hand2); // ???
}

TEST_F(TestSuiteHand, TestHighHandRank_OnePair_TwoPair)
{
    Hand hand1( 0, {
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::KING, Suit::HEART },
		{ Rank::QUEEN, Suit::CLUB }
	});

	Hand hand2( 0, {
		{ Rank::ACE, Suit::SPADE },
		{ Rank::ACE, Suit::HEART },
		{ Rank::QUEEN, Suit::HEART },
		{ Rank::QUEEN, Suit::SPADE }
	});

	EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestRank_HighCard_OneCard)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND } } );
	EXPECT_EQ(hand1.getHandRank().rank, HandRank::HIGH_CARD);
}

TEST_F(TestSuiteHand, TestRank_HighCard_TwoCards)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::KING, Suit::CLUB } } );
	EXPECT_EQ(hand1.getHandRank().rank, HandRank::HIGH_CARD);
}

TEST_F(TestSuiteHand, TestRank_HighCard_ThreeCards)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::KING, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } );
	EXPECT_EQ(hand1.getHandRank().rank, HandRank::HIGH_CARD);
}

TEST_F(TestSuiteHand, TestRank_HighCard_FourCards)
{
    Hand hand1( 0, {
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::KING, Suit::CLUB },
		{ Rank::QUEEN, Suit::HEART },
		{ Rank::JACK, Suit::HEART }
	});

	EXPECT_EQ(hand1.getHandRank().rank, HandRank::HIGH_CARD);
}

TEST_F(TestSuiteHand, TestRank_HighCard_FiveCards)
{
	Hand hand1( 0, {
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::KING, Suit::CLUB },
		{ Rank::QUEEN, Suit::HEART },
		{ Rank::JACK, Suit::HEART },
		{ Rank::NINE, Suit::HEART }
	});

	EXPECT_EQ(hand1.getHandRank().rank, HandRank::HIGH_CARD);
}

TEST_F(TestSuiteHand, TestRank_OnePair_TwoCards)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB } } );
	EXPECT_EQ(hand1.getHandRank().rank, HandRank::ONE_PAIR);
}

TEST_F(TestSuiteHand, TestRank_OnePair_ThreeCards)
{
    Hand hand1( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } );
	EXPECT_EQ(hand1.getHandRank().rank, HandRank::ONE_PAIR);
}

TEST_F(TestSuiteHand, TestRank_OnePair_FourCards)
{
	Hand hand1( 0, {
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::QUEEN, Suit::HEART },
		{ Rank::JACK, Suit::HEART }
	});

	EXPECT_EQ(hand1.getHandRank().rank, HandRank::ONE_PAIR);
}

TEST_F(TestSuiteHand, TestRank_OnePair_FiveCards)
{
	Hand hand1( 0, {
		{ Rank::ACE, Suit::DIAMOND },
		{ Rank::ACE, Suit::CLUB },
		{ Rank::QUEEN, Suit::HEART },
		{ Rank::JACK, Suit::HEART },
		{ Rank::NINE, Suit::HEART }
	});

	EXPECT_EQ(hand1.getHandRank().rank, HandRank::ONE_PAIR);
}

TEST_F(TestSuiteHand, TestRank_OnePair_OneCard_AddCard)
{
    Hand hand( 0, { { Rank::ACE, Suit::DIAMOND } } );
	hand.addCard({ Rank::ACE, Suit::CLUB });
	EXPECT_EQ(hand.getHandRank().rank, HandRank::ONE_PAIR);
}

TEST_F(TestSuiteHand, TestRank_OnePair_TwoCards_AddCard)
{
    Hand hand( 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB } } );
	hand.addCard({ Rank::QUEEN, Suit::HEART });
	EXPECT_EQ(hand.getHandRank().rank, HandRank::ONE_PAIR);
}

// }  // namespace - could surround Project1Test in a namespace