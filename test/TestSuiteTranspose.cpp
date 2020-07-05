#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Cards.hpp"
#include "Hands.hpp"
#include "HandFactory.hpp"
#include "ValidateHand.hpp"
#include "TransposeHands.hpp"
#include "HighCardHand.hpp"

class TestSuiteTranspose : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteTranspose() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteTranspose() {
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
TEST_F(TestSuiteTranspose, TestTransposing_2x3)
{
    std::vector<Cards> cards1{ { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB }, { Rank::ACE, Suit::HEART } }, { { Rank::KING, Suit::DIAMOND }, { Rank::KING, Suit::CLUB }, { Rank::KING, Suit::HEART } }, { { Rank::QUEEN, Suit::DIAMOND }, { Rank::QUEEN, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } };
    std::vector<Cards> cards2{ { { Rank::JACK, Suit::DIAMOND }, { Rank::JACK, Suit::CLUB }, { Rank::JACK, Suit::HEART } }, { { Rank::TEN, Suit::DIAMOND }, { Rank::TEN, Suit::CLUB }, { Rank::TEN, Suit::HEART } }, { { Rank::NINE, Suit::DIAMOND }, { Rank::NINE, Suit::CLUB }, { Rank::NINE, Suit::HEART } } };

    Hands hands1;
    Hands hands2;

    for(auto& cards : cards1)
    {
        hands1.push_back(HandFactory::Build(0, cards, ValidateHand::DetermineHandRank(cards)));
    }

    for(auto& cards : cards2)
    {
        hands2.push_back(HandFactory::Build(1, cards, ValidateHand::DetermineHandRank(cards)));
    }

    std::vector<Hands> hands{hands1, hands2};
    std::vector<Hands> transposedHands = TransposeHands::Transpose(hands);

	EXPECT_TRUE(transposedHands[0][0] == HighCardHand(0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB }, { Rank::ACE, Suit::HEART } }, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB }, { Rank::ACE, Suit::HEART } }));
	EXPECT_TRUE(transposedHands[0][1] == HighCardHand(1, { { Rank::JACK, Suit::DIAMOND }, { Rank::JACK, Suit::CLUB }, { Rank::JACK, Suit::HEART } }, { { Rank::JACK, Suit::DIAMOND }, { Rank::JACK, Suit::CLUB }, { Rank::JACK, Suit::HEART } }));

    EXPECT_TRUE(transposedHands[1][0] == HighCardHand(0, { { Rank::KING, Suit::DIAMOND }, { Rank::KING, Suit::CLUB }, { Rank::KING, Suit::HEART } }, { { Rank::KING, Suit::DIAMOND }, { Rank::KING, Suit::CLUB }, { Rank::KING, Suit::HEART } }));
	EXPECT_TRUE(transposedHands[1][1] == HighCardHand(1, { { Rank::TEN, Suit::DIAMOND }, { Rank::TEN, Suit::CLUB }, { Rank::TEN, Suit::HEART } }, { { Rank::TEN, Suit::DIAMOND }, { Rank::TEN, Suit::CLUB }, { Rank::TEN, Suit::HEART } }));

    EXPECT_TRUE(transposedHands[2][0] == HighCardHand(0, { { Rank::QUEEN, Suit::DIAMOND }, { Rank::QUEEN, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } }, { { Rank::QUEEN, Suit::DIAMOND }, { Rank::QUEEN, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } }));
	EXPECT_TRUE(transposedHands[2][1] == HighCardHand(1, { { Rank::NINE, Suit::DIAMOND }, { Rank::NINE, Suit::CLUB }, { Rank::NINE, Suit::HEART } }, { { Rank::NINE, Suit::DIAMOND }, { Rank::NINE, Suit::CLUB }, { Rank::NINE, Suit::HEART } }));

    for(auto& handsForComparison : transposedHands)
    {
        for(auto& evaluate : handsForComparison)
        {
            std::stringstream ss;
            ss << evaluate;
            std::cout << ss.str() << std::endl;
        }
    }
}

TEST_F(TestSuiteTranspose, TestTransposing_3x3)
{
    // std::vector<Hand> hand1{ { 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB }, { Rank::ACE, Suit::HEART } } }, { 0, { { Rank::KING, Suit::DIAMOND }, { Rank::KING, Suit::CLUB }, { Rank::KING, Suit::HEART } } }, { 0, { { Rank::QUEEN, Suit::DIAMOND }, { Rank::QUEEN, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } } };
    // std::vector<Hand> hand2{ { 1, { { Rank::JACK, Suit::DIAMOND }, { Rank::JACK, Suit::CLUB }, { Rank::JACK, Suit::HEART } } }, { 1,  { { Rank::TEN, Suit::DIAMOND }, { Rank::TEN, Suit::CLUB }, { Rank::TEN, Suit::HEART } } }, { 1, { { Rank::NINE, Suit::DIAMOND }, { Rank::NINE, Suit::CLUB }, { Rank::NINE, Suit::HEART } } } };
    // std::vector<Hand> hand3{ { 2, { { Rank::EIGHT, Suit::DIAMOND }, { Rank::EIGHT, Suit::CLUB }, { Rank::EIGHT, Suit::HEART } } }, { 2,  { { Rank::SEVEN, Suit::DIAMOND }, { Rank::SEVEN, Suit::CLUB }, { Rank::SEVEN, Suit::HEART } } }, { 2, { { Rank::SIX, Suit::DIAMOND }, { Rank::SIX, Suit::CLUB }, { Rank::SIX, Suit::HEART } } } };

    // std::vector<std::vector<Hand>> hands{ hand1, hand2, hand3 };

    // std::vector<std::vector<Hand>> transposedHands = TransposeHands::Transpose(hands);

	// EXPECT_TRUE(transposedHands[0][0] == Hand({ 0, { { Rank::ACE, Suit::DIAMOND }, { Rank::ACE, Suit::CLUB }, { Rank::ACE, Suit::HEART } } }));
	// EXPECT_TRUE(transposedHands[0][1] == Hand({ 1, { { Rank::JACK, Suit::DIAMOND }, { Rank::JACK, Suit::CLUB }, { Rank::JACK, Suit::HEART } } }));
	// EXPECT_TRUE(transposedHands[0][2] == Hand({ 1, { { Rank::EIGHT, Suit::DIAMOND }, { Rank::EIGHT, Suit::CLUB }, { Rank::EIGHT, Suit::HEART } } }));

    // EXPECT_TRUE(transposedHands[1][0] == Hand({ 0, { { Rank::KING, Suit::DIAMOND }, { Rank::KING, Suit::CLUB }, { Rank::KING, Suit::HEART } } }));
	// EXPECT_TRUE(transposedHands[1][1] == Hand({ 1, { { Rank::TEN, Suit::DIAMOND }, { Rank::TEN, Suit::CLUB }, { Rank::TEN, Suit::HEART } } }));
	// EXPECT_TRUE(transposedHands[1][2] == Hand({ 1, { { Rank::SEVEN, Suit::DIAMOND }, { Rank::SEVEN, Suit::CLUB }, { Rank::SEVEN, Suit::HEART } } }));

    // EXPECT_TRUE(transposedHands[2][0] == Hand({ 0, { { Rank::QUEEN, Suit::DIAMOND }, { Rank::QUEEN, Suit::CLUB }, { Rank::QUEEN, Suit::HEART } } }));
	// EXPECT_TRUE(transposedHands[2][1] == Hand({ 1, { { Rank::NINE, Suit::DIAMOND }, { Rank::NINE, Suit::CLUB }, { Rank::NINE, Suit::HEART } } }));
	// EXPECT_TRUE(transposedHands[2][2] == Hand({ 1, { { Rank::SIX, Suit::DIAMOND }, { Rank::SIX, Suit::CLUB }, { Rank::SIX, Suit::HEART } } }));

    // for(auto& handsForComparison : transposedHands)
    // {
    //     for(auto& evaluate : handsForComparison)
    //     {
    //         std::stringstream ss;
    //         ss << evaluate;
    //         std::cout << ss.str() << std::endl;
    //     }
    // }
}

// }  // namespace - could surround Project1Test in a namespace