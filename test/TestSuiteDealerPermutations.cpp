#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "DeckBuilder.hpp"
#include "DealerPermutations.hpp"

#include "spdlog/spdlog.h"

#include <chrono>

class TestSuiteDealerPermutations : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteDealerPermutations() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteDealerPermutations() {
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
TEST_F(TestSuiteDealerPermutations, TestDealerPermutations_3c2)
{
	// Deck deck = DeckBuilder::Build();
	Cards deck{ {Rank::ACE, Suit::CLUB}, {Rank::TEN, Suit::DIAMOND}, {Rank::FOUR, Suit::SPADE} };
    std::vector<Cards> hands = DealerPermutations::Simulate(deck, 2);

	// for(auto& hand : hands)
	// {
	// 	std::cout << "=================================" << std::endl;

	// 	for(auto& card : hand)
	// 	{
	// 		std::cout << card << std::endl;
	// 	}
	// }
}

TEST_F(TestSuiteDealerPermutations, TestDealerPermutations_4c3)
{
	// Deck deck = DeckBuilder::Build();
	Cards deck{ {Rank::ACE, Suit::CLUB}, {Rank::TEN, Suit::DIAMOND}, {Rank::FOUR, Suit::SPADE}, {Rank::TWO, Suit::HEART} };
    std::vector<Cards> hands = DealerPermutations::Simulate(deck, 3);

	// for(auto& hand : hands)
	// {
	// 	std::cout << "=================================" << std::endl;

	// 	for(auto& card : hand)
	// 	{
	// 		std::cout << card << std::endl;
	// 	}
	// }
}

TEST_F(TestSuiteDealerPermutations, TestDealerPermutations_48c5)
{
	Deck deck = DeckBuilder::Build();

	deck.pop_back();
	deck.pop_back();
	deck.pop_back();
	deck.pop_back();

	auto start = std::chrono::steady_clock::now();
    std::vector<Cards> hands = DealerPermutations::Simulate(deck, 5);
    auto end = std::chrono::steady_clock::now();
	spdlog::get("console")->info("Finished building database in [{}]ms", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());


	// for(auto& hand : hands)
	// {
	// 	std::cout << "=================================" << std::endl;

	// 	for(auto& card : hand)
	// 	{
	// 		std::cout << card << std::endl;
	// 	}
	// }
}

// }  // namespace - could surround Project1Test in a namespace