#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "FindStraightsAndFlushes.hpp"

#include <chrono>

class TestSuiteFindStraightsAndFlushes : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteFindStraightsAndFlushes() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteFindStraightsAndFlushes() {
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
TEST_F(TestSuiteFindStraightsAndFlushes, FindingStraight)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::QUEEN, Suit::HEART },
		new Card{ Rank::JACK, Suit::SPADE },
		new Card{ Rank::TEN, Suit::HEART },
        new Card{ Rank::EIGHT, Suit::SPADE },
		new Card{ Rank::TWO, Suit::HEART }
	};

	FindStraightsAndFlushes::FindRun(cards);
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindingFlush_Sorted)
{
	Card* cards1 = new Card{ Rank::ACE, Suit::DIAMOND };
	Card* cards2 = new Card{ Rank::KING, Suit::DIAMOND };
	Card* cards3 = new Card{ Rank::QUEEN, Suit::CLUB };
	Card* cards4 = new Card{ Rank::JACK, Suit::DIAMOND };
	Card* cards5 = new Card{ Rank::TEN, Suit::DIAMOND };
	Card* cards6 = new Card{ Rank::EIGHT, Suit::SPADE };
	Card* cards7 = new Card{ Rank::TWO, Suit::DIAMOND };

	CardBuffer<7> cards{
		cards1,
		cards2,
		cards3,
		cards4,
		cards5,
		cards6,
		cards7
	};

	auto start = std::chrono::steady_clock::now();
	for(unsigned int x = 0; x < 1000; x++)
	{
		cards[0] = cards1;
		cards[1] = cards2;
		cards[2] = cards3;
		cards[3] = cards4;
		cards[4] = cards5;
		cards[5] = cards6;
		cards[6] = cards7;

		std::sort(std::begin(cards), std::end(cards),
		[](const Card* const lhs, const Card* const rhs){ return (*lhs).suit > (*rhs).suit; });
		
		FindStraightsAndFlushes::FindFlush(cards);
	}
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
}

TEST_F(TestSuiteFindStraightsAndFlushes, FindingFlush_Permutations)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::DIAMOND },
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::JACK, Suit::DIAMOND },
		new Card{ Rank::TEN, Suit::DIAMOND },
        new Card{ Rank::EIGHT, Suit::SPADE },
		new Card{ Rank::TWO, Suit::DIAMOND }
	};

	auto start = std::chrono::steady_clock::now();
	for(unsigned int x = 0; x < 1000; x++)
	{
		FindStraightsAndFlushes::FindFlushPermutations(cards);
	}
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
}

// TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraight_Ace_High)
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

// 	std::optional<HandRank> result = FindStraightsAndFlushes::FindRank(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE(*result == HandRank::ROYAL_FLUSH);

//     std::cout << *result << std::endl;
// }

// TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraight_Ace_Low)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::FIVE, Suit::CLUB },
// 		new Card{ Rank::FOUR, Suit::HEART },
// 		new Card{ Rank::THREE, Suit::SPADE },
// 		new Card{ Rank::TWO, Suit::HEART }
// 	}};

// 	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_ACE_LOW);

// 	std::cout << (*result).rank << std::endl;
// }

// TEST_F(TestSuiteFindStraightsAndFlushes, FindARoyalFlush)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::QUEEN, Suit::DIAMOND },
// 		new Card{ Rank::JACK, Suit::DIAMOND },
// 		new Card{ Rank::TEN, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::ROYAL_FLUSH);
// }

// TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraightFlush)
// {
// 	Cards cards{{
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::QUEEN, Suit::DIAMOND },
// 		new Card{ Rank::JACK, Suit::DIAMOND },
// 		new Card{ Rank::TEN, Suit::DIAMOND },
// 		new Card{ Rank::NINE, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_FLUSH);
// }

// TEST_F(TestSuiteFindStraightsAndFlushes, FindAStraightFlushAceLow)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::FIVE, Suit::DIAMOND },
// 		new Card{ Rank::FOUR, Suit::DIAMOND },
// 		new Card{ Rank::THREE, Suit::DIAMOND },
// 		new Card{ Rank::TWO, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::STRAIGHT_FLUSH_ACE_LOW);
// }

// TEST_F(TestSuiteFindStraightsAndFlushes, FindAFlush)
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

// 	std::optional<ValidatedHand> result = FindStraightsAndFlushes::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::FLUSH);
// }

// // }  // namespace - could surround Project1Test in a namespace