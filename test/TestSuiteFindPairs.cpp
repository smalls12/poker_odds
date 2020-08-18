#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "FindAllPairs.hpp"

#include <chrono>

class TestSuiteFindPairs : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteFindPairs() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteFindPairs() {
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
TEST_F(TestSuiteFindPairs, FindPair_v1)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::KING, Suit::HEART },
		new Card{ Rank::TEN, Suit::SPADE },
		new Card{ Rank::SEVEN, Suit::HEART },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::DIAMOND }
	};

	CardBuffer<7>::const_iterator iter = FindAllPairs::FindPair(cards, cards.begin(), 2);

	EXPECT_TRUE(*iter == cards[1]);
}

TEST_F(TestSuiteFindPairs, FindPair_v2)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::KING, Suit::HEART },
		new Card{ Rank::TEN, Suit::SPADE },
		new Card{ Rank::SEVEN, Suit::HEART },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::DIAMOND }
	};

	CardBuffer<7>::const_iterator iter = FindAllPairs::FindPair(cards, cards.begin(), 2);

	EXPECT_TRUE(*iter == cards[2]);
}

TEST_F(TestSuiteFindPairs, FindPair_v3)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::JACK, Suit::HEART },
		new Card{ Rank::TEN, Suit::SPADE },
		new Card{ Rank::SEVEN, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::THREE, Suit::DIAMOND }
	};

	CardBuffer<7>::const_iterator iter = FindAllPairs::FindPair(cards, cards.begin(), 2);

	EXPECT_TRUE(*iter == cards[6]);
}

TEST_F(TestSuiteFindPairs, FindTwoPair_v1)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::JACK, Suit::HEART },
		new Card{ Rank::JACK, Suit::SPADE },
		new Card{ Rank::SEVEN, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::THREE, Suit::DIAMOND }
	};

	CardBuffer<7>::const_iterator iter = FindAllPairs::FindPair(cards, cards.begin(), 2);

	EXPECT_TRUE(*iter == cards[3]);

	iter = FindAllPairs::FindPair(cards, iter, 2);

	EXPECT_TRUE(*iter == cards[6]);
}

TEST_F(TestSuiteFindPairs, FindThreeOfAKind_v1)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::HEART },
		new Card{ Rank::TEN, Suit::SPADE },
		new Card{ Rank::SEVEN, Suit::HEART },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::DIAMOND }
	};

	CardBuffer<7>::const_iterator iter = FindAllPairs::FindPair(cards, cards.begin(), 3);

	EXPECT_TRUE(*iter == cards[2]);
}

TEST_F(TestSuiteFindPairs, FindThreeOfAKind_v2)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::KING, Suit::HEART },
		new Card{ Rank::KING, Suit::SPADE },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::DIAMOND }
	};

	CardBuffer<7>::const_iterator iter = FindAllPairs::FindPair(cards, cards.begin(), 3);

	EXPECT_TRUE(*iter == cards[4]);
}

TEST_F(TestSuiteFindPairs, FindFullHouse_v1)
{
	CardBuffer<7> cards{
		new Card{ Rank::ACE, Suit::DIAMOND },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::HEART },
		new Card{ Rank::KING, Suit::DIAMOND },
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::DIAMOND },
		new Card{ Rank::SEVEN, Suit::CLUB }
	};

	CardBuffer<7>::const_iterator iter = FindAllPairs::FindPair(cards, cards.begin(), 3);

	EXPECT_TRUE(*iter == cards[2]);

	iter = FindAllPairs::FindPair(cards, cards.begin(), 2);

	EXPECT_TRUE(*iter == cards[4]);
}

// TEST_F(TestSuiteFindPairs, FindFullHouse_v1)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::ACE, Suit::CLUB },
// 		new Card{ Rank::KING, Suit::HEART },
// 		new Card{ Rank::KING, Suit::SPADE },
// 		new Card{ Rank::QUEEN, Suit::HEART },
// 		new Card{ Rank::QUEEN, Suit::SPADE },
// 		new Card{ Rank::QUEEN, Suit::HEART }
// 	}};

// 	auto start = std::chrono::steady_clock::now();
// 	std::optional<ValidatedHand> result = FindPairs::Find(cards);
// 	auto end = std::chrono::steady_clock::now();
// 	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
	
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::FULL_HOUSE);
// }

// TEST_F(TestSuiteFindPairs, FindFullHouse_v2)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::ACE, Suit::CLUB },
// 		new Card{ Rank::KING, Suit::CLUB },
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::KING, Suit::HEART }
// 	}};

// 	std::optional<ValidatedHand> result = FindPairs::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::FULL_HOUSE);
	
// 	for(auto& card : (*result).cards)
// 	{
// 		std::cout << card << std::endl;
// 	}
// }

// TEST_F(TestSuiteFindPairs, FindFullHouse_v3)
// {
// 	Cards cards{{
// 		new Card{ Rank::SEVEN, Suit::DIAMOND },
// 		new Card{ Rank::SEVEN, Suit::CLUB },
// 		new Card{ Rank::FIVE, Suit::DIAMOND },
// 		new Card{ Rank::FIVE, Suit::CLUB },
// 		new Card{ Rank::TWO, Suit::HEART },
// 		new Card{ Rank::TWO, Suit::DIAMOND },
// 		new Card{ Rank::TWO, Suit::CLUB }
// 	}};

// 	std::optional<ValidatedHand> result = FindPairs::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::FULL_HOUSE);
	
// 	std::cout << *result << std::endl;
// }

// TEST_F(TestSuiteFindPairs, FindThreeOfAKind)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::ACE, Suit::CLUB },
// 		new Card{ Rank::ACE, Suit::HEART },
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::QUEEN, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindPairs::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::THREE_OF_A_KIND);


// 	Cards temp({
// 		new Card{ Rank::ACE, Suit::DIAMOND }, 
// 		new Card{ Rank::ACE, Suit::CLUB }, 
// 		new Card{ Rank::ACE, Suit::HEART }
// 	});
	
// 	EXPECT_TRUE(std::equal(std::begin((*result).cards), std::end((*result).cards),
//                 std::begin(temp), std::end(temp),
//                 [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; }));
// }

// TEST_F(TestSuiteFindPairs, FindTwoPair)
// {
// 	Cards cards{{
// 		new Card{ Rank::ACE, Suit::DIAMOND },
// 		new Card{ Rank::ACE, Suit::CLUB },
// 		new Card{ Rank::KING, Suit::HEART },
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::QUEEN, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindPairs::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::TWO_PAIR);
// }

// TEST_F(TestSuiteFindPairs, FindOnePair)
// {
// 	Cards cards{{
// 		new Card{ Rank::TWO, Suit::DIAMOND },
// 		new Card{ Rank::ACE, Suit::CLUB },
// 		new Card{ Rank::ACE, Suit::HEART },
// 		new Card{ Rank::KING, Suit::DIAMOND },
// 		new Card{ Rank::QUEEN, Suit::DIAMOND }
// 	}};

// 	std::optional<ValidatedHand> result = FindPairs::Find(cards);
// 	EXPECT_TRUE(result);
// 	EXPECT_TRUE((*result).rank == HandRank::ONE_PAIR);
// }

// }  // namespace - could surround Project1Test in a namespace