#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "PossibleHands.hpp"

class TestSuitePossibleHands : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuitePossibleHands() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuitePossibleHands() {
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
TEST_F(TestSuitePossibleHands, TestEquality)
{
	Hands possibleHands;

	Cards cards({
		new Card{ Rank::ACE, Suit::SPADE },
		new Card{ Rank::ACE, Suit::HEART }
	});

	std::vector<Cards> permutations({{
			new Card{ Rank::KING, Suit::SPADE },
			new Card{ Rank::QUEEN, Suit::HEART },
			new Card{ Rank::JACK, Suit::SPADE }},{
			new Card{ Rank::TEN, Suit::SPADE },
			new Card{ Rank::NINE, Suit::HEART },
			new Card{ Rank::EIGHT, Suit::SPADE }},{
			new Card{ Rank::SEVEN, Suit::SPADE },
			new Card{ Rank::SIX, Suit::HEART },
			new Card{ Rank::FIVE, Suit::SPADE }}});

	possibleHands = PossibleHands::SummarizeAllPossibleHands(0, cards, permutations);

	std::cout << possibleHands << std::endl;

}

// }  // namespace - could surround Project1Test in a namespace
