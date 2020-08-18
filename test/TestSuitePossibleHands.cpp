#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Buffer.hpp"
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
TEST_F(TestSuitePossibleHands, DetermineHands_2Players)
{
	Players players;
	players.emplace_back(new Player(1));
	players[0]->AddCardToHand(new Card{ Rank::ACE, Suit::DIAMOND }, 0);
	players[0]->AddCardToHand(new Card{ Rank::ACE, Suit::CLUB }, 1);

	players.emplace_back(new Player(2));
	players[1]->AddCardToHand(new Card{ Rank::KING, Suit::DIAMOND }, 0);
	players[1]->AddCardToHand(new Card{ Rank::KING, Suit::SPADE }, 1);

	HandBuffer<2> cardPermutationsHandRankOnlyBuffer;

	CardBuffer<5> cards1{
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::TWO, Suit::DIAMOND },
		new Card{ Rank::TEN, Suit::HEART },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	CardBuffer<5> communityCards;

	PossibleHands possibleHands(players);
	possibleHands.Generate(cards1, communityCards, cardPermutationsHandRankOnlyBuffer);

	std::cout << cardPermutationsHandRankOnlyBuffer << std::endl;

	CardBuffer<5> cards2{
		new Card{ Rank::FOUR, Suit::CLUB },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::JACK, Suit::DIAMOND },
		new Card{ Rank::TEN, Suit::HEART },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	possibleHands.Generate(cards2, communityCards, cardPermutationsHandRankOnlyBuffer);

	std::cout << cardPermutationsHandRankOnlyBuffer << std::endl;
}

TEST_F(TestSuitePossibleHands, DetermineHands_4Players)
{
	Players players;
	players.emplace_back(new Player(1));
	players[0]->AddCardToHand(new Card{ Rank::ACE, Suit::CLUB }, 0);
	players[0]->AddCardToHand(new Card{ Rank::KING, Suit::CLUB }, 1);

	players.emplace_back(new Player(2));
	players[1]->AddCardToHand(new Card{ Rank::KING, Suit::SPADE }, 0);
	players[1]->AddCardToHand(new Card{ Rank::KING, Suit::SPADE }, 1);

	players.emplace_back(new Player(3));
	players[2]->AddCardToHand(new Card{ Rank::TEN, Suit::SPADE }, 0);
	players[2]->AddCardToHand(new Card{ Rank::SEVEN, Suit::HEART }, 1);

	players.emplace_back(new Player(4));
	players[3]->AddCardToHand(new Card{ Rank::JACK, Suit::DIAMOND }, 0);
	players[3]->AddCardToHand(new Card{ Rank::TWO, Suit::CLUB }, 1);

	HandBuffer<4> cardPermutationsHandRankOnlyBuffer;

	CardBuffer<5> cards1{
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::TWO, Suit::DIAMOND },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	CardBuffer<5> communityCards;

	PossibleHands possibleHands(players);
	possibleHands.Generate(cards1, communityCards, cardPermutationsHandRankOnlyBuffer);

	std::cout << cardPermutationsHandRankOnlyBuffer << std::endl;

	// sort first
	std::sort(cardPermutationsHandRankOnlyBuffer.begin(), cardPermutationsHandRankOnlyBuffer.end(),
	[](const Hand* const lhs, const Hand* const rhs){ return *lhs > *rhs; });

	std::cout << cardPermutationsHandRankOnlyBuffer << std::endl;

	CardBuffer<5> cards2{
		new Card{ Rank::FOUR, Suit::CLUB },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::JACK, Suit::DIAMOND },
		new Card{ Rank::TEN, Suit::HEART },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	possibleHands.Generate(cards2, communityCards, cardPermutationsHandRankOnlyBuffer);

	std::cout << cardPermutationsHandRankOnlyBuffer << std::endl;
}

// }  // namespace - could surround Project1Test in a namespace
