#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Deck.hpp"
#include "DeckBuilder.hpp"

class TestSuitePermutations : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuitePermutations() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuitePermutations() {
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
TEST_F(TestSuitePermutations, TestPermutations_52c5)
{
    // build a 52 card deck
	Deck deck = DeckBuilder::Build();

	// construct output
	std::vector<Cards> outputs;
	outputs.reserve(2598960);

    std::string bitmask(5, 1); // K leading 1's
    bitmask.resize(52, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do
	{
		Cards hand;
		hand.reserve(5);
        for (int i = 0; i < 52; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
			{
				hand.push_back(deck[i]);
				// std::cout << " " << i;
			}
        }
		outputs.push_back(hand);
        // std::cout << std::endl;
    }
	while (std::prev_permutation(bitmask.begin(), bitmask.end()));

	outputs.shrink_to_fit();

	std::cout << outputs.size() << std::endl;
}

TEST_F(TestSuitePermutations, TestPermutations_48c5)
{
    // build a 52 card deck
	Deck deck = DeckBuilder::Build();

	// draw 4 cards
	deck.pop_back();
	deck.pop_back();
	deck.pop_back();
	deck.pop_back();

	// construct output
	std::vector<Cards> outputs;
	outputs.reserve(2598960);

    std::string bitmask(5, 1); // K leading 1's
    bitmask.resize(48, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do
	{
		Cards hand;
		hand.reserve(5);
        for (int i = 0; i < 48; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
			{
				// hand.push_back(deck[i]);
				// std::cout << " " << i;
			}
        }
		outputs.push_back(hand);
        // std::cout << std::endl;
    }
	while (std::prev_permutation(bitmask.begin(), bitmask.end()));

	outputs.shrink_to_fit();

	std::cout << outputs.size() << std::endl;
}

TEST_F(TestSuitePermutations, TestPermutations_46c5)
{
    // build a 52 card deck
	Deck deck = DeckBuilder::Build();

	// draw 4 cards
	deck.pop_back();
	deck.pop_back();
	deck.pop_back();
	deck.pop_back();
	deck.pop_back();
	deck.pop_back();

	// construct output
	std::vector<Cards> outputs;
	outputs.reserve(2598960);

    std::string bitmask(5, 1); // K leading 1's
    bitmask.resize(46, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do
	{
		Cards hand;
		hand.reserve(5);
        for (int i = 0; i < 46; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
			{
				// hand.push_back(deck[i]);
				// std::cout << " " << i;
			}
        }
		outputs.push_back(hand);
        // std::cout << std::endl;
    }
	while (std::prev_permutation(bitmask.begin(), bitmask.end()));

	outputs.shrink_to_fit();

	std::cout << outputs.size() << std::endl;
}

// }  // namespace - could surround Project1Test in a namespace
