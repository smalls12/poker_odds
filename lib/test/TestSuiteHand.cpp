#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Card.hpp"
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
TEST_F(TestSuiteHand, TestEquality_BaseHand_SingleHand_Equal)
{   
	Player player(0);
    Hand hand(player, HandRank::HIGH_CARD);
	EXPECT_TRUE(hand == hand);
}

TEST_F(TestSuiteHand, TestEquality_BaseHand_TwoHands_Equal)
{   
	Player player(0);
    Hand hand1(player, HandRank::HIGH_CARD);
	Hand hand2(player, HandRank::HIGH_CARD);
	EXPECT_TRUE(hand1 == hand2);
}

TEST_F(TestSuiteHand, TestEquality_BaseHand_TwoHands_GreaterThan)
{   
	Player player(0);
    Hand hand1(player, HandRank::ONE_PAIR);
	Hand hand2(player, HandRank::HIGH_CARD);
	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_HighCard_TwoHands_GreaterThan)
{
	CardBuffer<7> cards1{
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	Player player(0);
	auto hand1 = new HighCardHand(player);
	hand1->Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	auto hand2 = new HighCardHand(player);
	hand2->Reset(&cards2);

	EXPECT_TRUE(*hand1 > *hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_v1)
{
	CardBuffer<7> cards1{
		new Card{ Rank::NINE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	Player player(0);
	OnePairHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::EIGHT, Suit::CLUB },
		new Card{ Rank::EIGHT, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	OnePairHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_v2)
{
	CardBuffer<7> cards1{
		new Card{ Rank::NINE, Suit::CLUB },
		new Card{ Rank::NINE, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	Player player(0);
	OnePairHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	HighCardHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_OnePair_v3)
{
	CardBuffer<7> cards1{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	Player player(0);
	OnePairHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::NINE, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	OnePairHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_v1)
{
	CardBuffer<7> cards1{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	Player player(0);
	TwoPairHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	TwoPairHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_TwoPair_v2)
{
	CardBuffer<7> cards1{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	Player player(0);
	TwoPairHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	TwoPairHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestEquality_ThreeOfAKind_v1)
{
	CardBuffer<7> cards1{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	Player player(0);
	ThreeOfAKindHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	ThreeOfAKindHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestEquality_FourOfAKind_v1)
{
	CardBuffer<7> cards1{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::SEVEN, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	Player player(0);
	FourOfAKindHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
        new Card{ Rank::JACK, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	FourOfAKindHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 < hand2);
}

TEST_F(TestSuiteHand, TestEquality_FullHouse_v1)
{
	CardBuffer<7> cards1{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::HEART },
		new Card{ Rank::KING, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
		new Card{ Rank::SEVEN, Suit::CLUB }
	};

	Player player(0);
	FullHouseHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::HEART },
		new Card{ Rank::QUEEN, Suit::DIAMOND },
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
		new Card{ Rank::SEVEN, Suit::CLUB }
	};

	FullHouseHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_FullHouse_v2)
{
	CardBuffer<7> cards1{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::KING, Suit::HEART },
		new Card{ Rank::KING, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
		new Card{ Rank::SEVEN, Suit::CLUB }
	};

	Player player(0);
	FullHouseHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::HEART },
		new Card{ Rank::QUEEN, Suit::DIAMOND },
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
		new Card{ Rank::SEVEN, Suit::CLUB }
	};

	FullHouseHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 > hand2);
}

TEST_F(TestSuiteHand, TestEquality_FullHouse_v3)
{
	CardBuffer<7> cards1{
		new Card{ Rank::FIVE, Suit::DIAMOND },
		new Card{ Rank::FIVE, Suit::CLUB },
		new Card{ Rank::KING, Suit::HEART },
		new Card{ Rank::KING, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
		new Card{ Rank::SEVEN, Suit::CLUB }
	};

	Player player(0);
	FullHouseHand hand1(player);
	hand1.Reset(&cards1);

	CardBuffer<7> cards2{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::HEART },
		new Card{ Rank::QUEEN, Suit::DIAMOND },
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
		new Card{ Rank::SEVEN, Suit::CLUB }
	};

	FullHouseHand hand2(player);
	hand2.Reset(&cards2);

	EXPECT_TRUE(hand1 > hand2);
}

// // }  // namespace - could surround Project1Test in a namespace