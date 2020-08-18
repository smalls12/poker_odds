#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Card.hpp"

class TestSuiteCard : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteCard() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteCard() {
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
TEST_F(TestSuiteCard, TestEquality)
{
    Card card( { Rank::ACE, Suit::DIAMOND } );
	EXPECT_TRUE(card == card);
}

TEST_F(TestSuiteCard, TestEquality_Card_Rank)
{
	// card equality means the ranks match
	// suits cannot match in a single deck of 52 cards
    Card card1( { Rank::ACE, Suit::DIAMOND } );
	Card card2( { Rank::ACE, Suit::CLUB } );
	EXPECT_TRUE(card1 == card2);
}

TEST_F(TestSuiteCard, TestInEquality_Card_Rank)
{
    Card card1( { Rank::ACE, Suit::DIAMOND } );
	Card card2( { Rank::KING, Suit::DIAMOND } );
	EXPECT_TRUE(card1 != card2);
}

TEST_F(TestSuiteCard, TestingAdjacentDifference)
{
    std::vector<Card> cards{ { Rank::ACE, Suit::DIAMOND }, { Rank::QUEEN, Suit::DIAMOND } };

	for (unsigned int i=0; i<cards.size() - 1; i++)
    {
		if( cards[i+1].rank - cards[i].rank != 1 )
		{
			break;
		}
	}
}

TEST_F(TestSuiteCard, TestInEquality_GreaterThan_v1)
{
    Card card1( { Rank::ACE, Suit::DIAMOND } );
	Card card2( { Rank::KING, Suit::DIAMOND } );
	EXPECT_TRUE(card1 > card2);
}

TEST_F(TestSuiteCard, TestInEquality_GreaterThan_v2)
{
    Card card1( { Rank::KING, Suit::DIAMOND } );
	Card card2( { Rank::ACE, Suit::DIAMOND } );
	EXPECT_TRUE(card1 > card2);
}

// }  // namespace - could surround Project1Test in a namespace