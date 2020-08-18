#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "FindStraights.hpp"

class TestSuiteFindStraights : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteFindStraights() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteFindStraights() {
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
TEST_F(TestSuiteFindStraights, FindingStraight_v1)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
        new Card{ Rank::EIGHT, Suit::SPADE },
		new Card{ Rank::TWO, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, true);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::ROYAL_FLUSH);

	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v2)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::EIGHT, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART }
	};

	std::optional<HandRank> result1 = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result1);
	EXPECT_TRUE(*result1 == HandRank::STRAIGHT);
	
	std::cout << *result1 << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v3)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::EIGHT, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT);
	
	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v4)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::EIGHT, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT);
	
	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v5)
{
	CardBuffer<7> cards{
		new Card{ Rank::EIGHT, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT);
	
	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v6)
{
	CardBuffer<7> cards{
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::FOUR, Suit::DIAMOND },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT);
	
	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v7)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::EIGHT, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT_ACE_LOW);
	
	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v8)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::TEN, Suit::DIAMOND },
		new Card{ Rank::EIGHT, Suit::HEART },
        new Card{ Rank::FIVE, Suit::CLUB },
		new Card{ Rank::FOUR, Suit::CLUB },
		new Card{ Rank::THREE, Suit::CLUB },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, true);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT_FLUSH_ACE_LOW);
	
	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_NotAStraight)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::NINE, Suit::CLUB },
        new Card{ Rank::EIGHT, Suit::SPADE },
		new Card{ Rank::TWO, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, true);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::FLUSH);
	
	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v9)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::SPADE },
		new Card{ Rank::TEN, Suit::HEART },
		new Card{ Rank::EIGHT, Suit::SPADE },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
        new Card{ Rank::FIVE, Suit::DIAMOND },
		new Card{ Rank::FIVE, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_FALSE(result);
}

TEST_F(TestSuiteFindStraights, FindingStraight_v10)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::SPADE },
		new Card{ Rank::KING, Suit::HEART },
		new Card{ Rank::QUEEN, Suit::SPADE },
		new Card{ Rank::JACK, Suit::DIAMOND },
        new Card{ Rank::TEN, Suit::DIAMOND },
		new Card{ Rank::FIVE, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT);

	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v11)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::SPADE },
		new Card{ Rank::FIVE, Suit::HEART },
		new Card{ Rank::FOUR, Suit::SPADE },
		new Card{ Rank::THREE, Suit::DIAMOND },
        new Card{ Rank::TWO, Suit::DIAMOND },
		new Card{ Rank::TWO, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT_ACE_LOW);

	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v12)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FIVE, Suit::HEART },
		new Card{ Rank::FOUR, Suit::SPADE },
		new Card{ Rank::THREE, Suit::DIAMOND },
        new Card{ Rank::TWO, Suit::DIAMOND },
		new Card{ Rank::TWO, Suit::HEART }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT);

	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v13)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::SPADE },
		new Card{ Rank::THREE, Suit::SPADE },
        new Card{ Rank::TWO, Suit::CLUB },
		new Card{ Rank::TWO, Suit::SPADE }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, true);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT_FLUSH);

	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v14)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::SPADE },
		new Card{ Rank::THREE, Suit::SPADE },
        new Card{ Rank::TWO, Suit::SPADE },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, true);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT_FLUSH);

	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v15)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::SPADE },
		new Card{ Rank::THREE, Suit::SPADE },
        new Card{ Rank::TWO, Suit::DIAMOND },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, false);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT);

	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingStraight_v16)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::SPADE },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
		new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::SPADE },
		new Card{ Rank::THREE, Suit::SPADE },
        new Card{ Rank::TWO, Suit::SPADE },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, true);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::STRAIGHT_FLUSH_ACE_LOW);

	std::cout << *result << std::endl;
}

TEST_F(TestSuiteFindStraights, FindingFlush_v1)
{
	CardBuffer<7> cards{
		new Card{ Rank::KING, Suit::SPADE },
		new Card{ Rank::SEVEN, Suit::SPADE },
		new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::SPADE },
		new Card{ Rank::THREE, Suit::SPADE },
        new Card{ Rank::TWO, Suit::DIAMOND },
		new Card{ Rank::TWO, Suit::SPADE }
	};

	std::optional<HandRank> result = FindStraights::FindRank(cards, true);
	EXPECT_TRUE(result);
	EXPECT_TRUE(*result == HandRank::FLUSH);

	std::cout << *result << std::endl;
}

// TEST_F(TestSuiteFindStraights, FindAStraight_Ace_High)
// {
// 	CardBuffer<7> cards{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::KING, Suit::CLUB },
// 		new Card{ Rank::QUEEN, Suit::HEART },
// 		new Card{ Rank::JACK, Suit::SPADE },
// 		new Card{ Rank::TEN, Suit::HEART },
//         new Card{ Rank::FOUR, Suit::SPADE },
// 		new Card{ Rank::TWO, Suit::HEART }
// 	};

// 	std::optional<HandRank> result = FindStraights::FindRank(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE(*result == HandRank::ROYAL_FLUSH);

//     std::cout << *result << std::endl;
// }

// TEST_F(TestSuiteFindStraights, FindAStraight_Ace_Low)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::FIVE, Suit::CLUB },
// 		new Card{ Rank::FOUR, Suit::HEART },
// 		new Card{ Rank::THREE, Suit::SPADE },
// 		new Card{ Rank::TWO, Suit::HEART }
// 	}};

// 	std::optional<ValidatedHand> result = FindStraights::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_ACE_LOW);

// 	std::cout << (*result).rank << std::endl;
// }

// TEST_F(TestSuiteFindStraights, FindARoyalFlush)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::QUEEN, Suit::DIAMOND },
// 		new Card{ Rank::JACK, Suit::DIAMOND },
// 		new Card{ Rank::TEN, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindStraights::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::ROYAL_FLUSH);
// }

// TEST_F(TestSuiteFindStraights, FindAStraightFlush)
// {
// 	Cards cards{{
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::QUEEN, Suit::DIAMOND },
// 		new Card{ Rank::JACK, Suit::DIAMOND },
// 		new Card{ Rank::TEN, Suit::DIAMOND },
// 		new Card{ Rank::NINE, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindStraights::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_FLUSH);
// }

// TEST_F(TestSuiteFindStraights, FindAStraightFlushAceLow)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::FIVE, Suit::DIAMOND },
// 		new Card{ Rank::FOUR, Suit::DIAMOND },
// 		new Card{ Rank::THREE, Suit::DIAMOND },
// 		new Card{ Rank::TWO, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindStraights::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_FLUSH_ACE_LOW);
// }

// TEST_F(TestSuiteFindStraights, FindAFlush)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::QUEEN, Suit::DIAMOND },
// 		new Card{ Rank::JACK, Suit::DIAMOND },
// 		new Card{ Rank::NINE, Suit::DIAMOND }
// 	}};

// 	// sort first
//     std::sort(cards.begin(), cards.end());

// 	std::optional<ValidatedHand> result = FindStraights::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::FLUSH);
// }

// // }  // namespace - could surround Project1Test in a namespace