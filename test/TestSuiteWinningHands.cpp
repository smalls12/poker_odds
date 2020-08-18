#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Hand.hpp"

class TestSuiteWinningHands : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	TestSuiteWinningHands() {
		// You can do set-up work for each test here.
	}

	virtual ~TestSuiteWinningHands() {
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
TEST_F(TestSuiteWinningHands, SortRank_v1)
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

	HighCardHand hand1(nullptr);
	hand1.Reset(&cards1);

    CardBuffer<7> cards2{
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	HighCardHand hand2(nullptr);
	hand2.Reset(&cards2);

    CardBuffer<7> cards3{
		new Card{ Rank::NINE, Suit::CLUB },
		new Card{ Rank::NINE, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	OnePairHand hand3(nullptr);
	hand3.Reset(&cards3);

    CardBuffer<7> cards4{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	TwoPairHand hand4(nullptr);
	hand4.Reset(&cards4);

    HandBuffer<4> hands{
        &hand2,
        &hand1,
        &hand3,
        &hand4
    };
    
    // sort first
    std::sort(hands.begin(), hands.end(),
    [](const Hand* const lhs, const Hand* const rhs){ return *lhs > *rhs; });

    std::cout << hands << std::endl;
}

TEST_F(TestSuiteWinningHands, SortRank_v2)
{
    CardBuffer<7> cards1{
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	HighCardHand hand1(nullptr);
	hand1.Reset(&cards1);

    CardBuffer<7> cards2{
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	HighCardHand hand2(nullptr);
	hand2.Reset(&cards2);

    CardBuffer<7> cards3{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::NINE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	HighCardHand hand3(nullptr);
	hand3.Reset(&cards3);

    CardBuffer<7> cards4{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	TwoPairHand hand4(nullptr);
	hand4.Reset(&cards4);

    HandBuffer<4> hands{
        &hand2,
        &hand1,
        &hand3,
        &hand4
    };
    
    // sort first
    std::sort(hands.begin(), hands.end(),
    [](const Hand* const lhs, const Hand* const rhs){ return *lhs > *rhs; });

    std::cout << hands << std::endl;
}

TEST_F(TestSuiteWinningHands, SortRank_v3)
{
    CardBuffer<7> cards1{
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	auto hand1 = new HighCardHand(nullptr);
	hand1->Reset(&cards1);

    CardBuffer<7> cards2{
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	auto hand2 = new HighCardHand(nullptr);
	hand2->Reset(&cards2);

    CardBuffer<7> cards3{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::NINE, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	auto hand3 = new HighCardHand(nullptr);
	hand3->Reset(&cards3);

    CardBuffer<7> cards4{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SIX, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	auto hand4 = new HighCardHand(nullptr);
	hand4->Reset(&cards4);

    HandBuffer<4> hands{
        hand2,
        hand1,
        hand3,
        hand4
    };
    
    // sort first
    std::sort(hands.begin(), hands.end(),
    [](const ExplicitHand* const lhs, const ExplicitHand* const rhs){ return *lhs > *rhs; });

    std::cout << hands << std::endl;
}

TEST_F(TestSuiteWinningHands, SortRank_v4)
{
    CardBuffer<7> cards1{
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	auto hand1 = new HighCardHand(nullptr);
	hand1->Reset(&cards1);

    CardBuffer<7> cards2{
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	auto hand2 = new HighCardHand(nullptr);
	hand2->Reset(&cards2);

    CardBuffer<7> cards3{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	auto hand3 = new TwoPairHand(nullptr);
	hand3->Reset(&cards3);

    CardBuffer<7> cards4{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART }
	};

	auto hand4 = new TwoPairHand(nullptr);
	hand4->Reset(&cards4);

    HandBuffer<4> hands{
        hand2,
        hand1,
        hand3,
        hand4
    };
    
    // sort first
    std::sort(hands.begin(), hands.end(),
    [](const ExplicitHand* const lhs, const ExplicitHand* const rhs){ return *lhs > *rhs; });

    std::cout << hands << std::endl;
}

TEST_F(TestSuiteWinningHands, SortRank_v5)
{
    CardBuffer<7> cards1{
		new Card{ Rank::KING, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	Player* player1 = new Player(1);
	player1->AddCardToHand(cards1[0], 0);
	player1->AddCardToHand(cards1[1], 1);

	auto hand1 = new HighCardHand(player1);
	hand1->Reset(&cards1);

    CardBuffer<7> cards2{
		new Card{ Rank::QUEEN, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::SIX, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::HEART },
		new Card{ Rank::TWO, Suit::HEART }
	};

	Player* player2 = new Player(1);
	player2->AddCardToHand(cards2[0], 0);
	player2->AddCardToHand(cards2[1], 1);

	auto hand2 = new HighCardHand(player2);
	hand2->Reset(&cards2);

    CardBuffer<7> cards3{
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::SEVEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::CLUB },
		new Card{ Rank::TWO, Suit::CLUB }
	};

	Player* player3 = new Player(1);
	player3->AddCardToHand(cards3[0], 0);
	player3->AddCardToHand(cards3[1], 1);

	auto hand3 = new FlushHand(player3);
	hand3->Reset(&cards3, {Suit::CLUB});

    CardBuffer<7> cards4{
		new Card{ Rank::ACE, Suit::CLUB },
		new Card{ Rank::JACK, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
		new Card{ Rank::TEN, Suit::CLUB },
        new Card{ Rank::FIVE, Suit::SPADE },
		new Card{ Rank::FOUR, Suit::HEART },
		new Card{ Rank::THREE, Suit::CLUB }
	};

	Player* player4 = new Player(1);
	player4->AddCardToHand(cards4[0], 0);
	player4->AddCardToHand(cards4[1], 1);

	auto hand4 = new FlushHand(player4);
	hand4->Reset(&cards4, {Suit::CLUB});

    HandBuffer<4> hands{
        hand2,
        hand1,
        hand3,
        hand4
    };
    
    // sort first
    std::sort(hands.begin(), hands.end(),
    [](const ExplicitHand* const lhs, const ExplicitHand* const rhs){ return *lhs > *rhs; });

    std::cout << hands << std::endl;
}

// TEST_F(TestSuiteWinningHands, TwoPairMatch)
// {
//     Cards cards1{
//         new Card{ Rank::ACE, Suit::DIAMOND },
//         new Card{ Rank::TEN, Suit::SPADE },
//         new Card{ Rank::TEN, Suit::DIAMOND },
//         new Card{ Rank::EIGHT, Suit::DIAMOND },
//         new Card{ Rank::EIGHT, Suit::SPADE },
//         new Card{ Rank::FOUR, Suit::DIAMOND },
//         new Card{ Rank::TWO, Suit::CLUB }
//     };

//     TwoPairHand* hand1 = new TwoPairHand( 0, cards1 );
    
//     Cards cards2{
//         new Card{ Rank::KING, Suit::CLUB },
//         new Card{ Rank::JACK, Suit::HEART },
//         new Card{ Rank::JACK, Suit::CLUB },
//         new Card{ Rank::EIGHT, Suit::CLUB },
//         new Card{ Rank::EIGHT, Suit::HEART },
//         new Card{ Rank::THREE, Suit::CLUB },
//         new Card{ Rank::TWO, Suit::SPADE }
//     };

//     TwoPairHand* hand2 = new TwoPairHand( 1, cards2 );
    
//     Cards cards3{
//         new Card{ Rank::QUEEN, Suit::DIAMOND },
//         new Card{ Rank::JACK, Suit::SPADE },
//         new Card{ Rank::NINE, Suit::DIAMOND },
//         new Card{ Rank::SEVEN, Suit::HEART },
//         new Card{ Rank::FIVE, Suit::SPADE },
//         new Card{ Rank::THREE, Suit::DIAMOND },
//         new Card{ Rank::TWO, Suit::HEART }
//     };

//     HighCardHand* hand3 = new HighCardHand( 2, cards3 );

// 	Hands hands{ hand3, hand1, hand2 };

//     EXPECT_TRUE(*hand2 > *hand1);
//     EXPECT_TRUE(*hand1 > *hand3);

//     // sort first
//     std::sort(hands.begin(), hands.end(),
//     [](const Hand* const lhs, const Hand* const rhs){ return *lhs > *rhs; });
// }

// TEST_F(TestSuiteWinningHands, FlushMatch)
// {
//     FlushHand hand1 = new FlushHand( 0,
//         {
//             new Card{ Rank::ACE, Suit::HEART },
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::SIX, Suit::DIAMOND },
//             new Card{ Rank::FOUR, Suit::DIAMOND },
//             new Card{ Rank::THREE, Suit::DIAMOND },
//             new Card{ Rank::TWO, Suit::CLUB }
//         },
//         {
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::SIX, Suit::DIAMOND },
//             new Card{ Rank::FOUR, Suit::DIAMOND },
//             new Card{ Rank::THREE, Suit::DIAMOND }
//         });
    
//     FlushHand hand2 = new FlushHand( 1,
//         {
//             new Card{ Rank::KING, Suit::CLUB },
//             new Card{ Rank::JACK, Suit::CLUB },
//             new Card{ Rank::NINE, Suit::CLUB },
//             new Card{ Rank::SEVEN, Suit::CLUB },
//             new Card{ Rank::FIVE, Suit::CLUB },
//             new Card{ Rank::THREE, Suit::CLUB },
//             new Card{ Rank::TWO, Suit::SPADE }
//         },
//         {
//             new Card{ Rank::KING, Suit::CLUB },
//             new Card{ Rank::JACK, Suit::CLUB },
//             new Card{ Rank::NINE, Suit::CLUB },
//             new Card{ Rank::SEVEN, Suit::CLUB },
//             new Card{ Rank::FIVE, Suit::CLUB }
//         });
    
//     OnePairHand hand3 = new OnePairHand( 2,
//         {
//             new Card{ Rank::QUEEN, Suit::DIAMOND },
//             new Card{ Rank::JACK, Suit::SPADE },
//             new Card{ Rank::NINE, Suit::DIAMOND },
//             new Card{ Rank::SEVEN, Suit::HEART },
//             new Card{ Rank::FIVE, Suit::SPADE },
//             new Card{ Rank::THREE, Suit::DIAMOND },
//             new Card{ Rank::TWO, Suit::HEART }
//         },
//         {
//             new Card{ Rank::ACE, Suit::DIAMOND }
//         });

// 	Hands hands{ hand3, hand1, hand2 };

//     EXPECT_TRUE(hand2 > hand1);
//     EXPECT_TRUE(hand1 > hand3);

//     std::sort(hands.begin(), hands.end(), std::greater<Hand>());
//     Hands::iterator it1 = std::adjacent_find(hands.begin(), hands.end());
//     if( it1 != hands.begin() )
//     {
//         // this means that there was only one winner
        
//     }
//     else
//     {
//         std::cout << "multiple winners" << std::endl;
//     }
// }

// TEST_F(TestSuiteWinningHands, StraightMatch)
// {
//     StraightHand hand1 = new StraightHand( 0,
//         {
//             new Card{ Rank::ACE, Suit::HEART },
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::NINE, Suit::HEART },
//             new Card{ Rank::EIGHT, Suit::CLUB },
//             new Card{ Rank::SEVEN, Suit::DIAMOND },
//             new Card{ Rank::SIX, Suit::DIAMOND },
//             new Card{ Rank::TWO, Suit::CLUB }
//         },
//         {
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::NINE, Suit::HEART },
//             new Card{ Rank::EIGHT, Suit::CLUB },
//             new Card{ Rank::SEVEN, Suit::DIAMOND },
//             new Card{ Rank::SIX, Suit::DIAMOND }
//         });
    
//     StraightHand hand2 = new StraightHand( 1,
//         {
//             new Card{ Rank::KING, Suit::CLUB },
//             new Card{ Rank::QUEEN, Suit::CLUB },
//             new Card{ Rank::TEN, Suit::CLUB },
//             new Card{ Rank::NINE, Suit::SPADE },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::SEVEN, Suit::CLUB },
//             new Card{ Rank::SIX, Suit::SPADE }
//         },
//         {
//             new Card{ Rank::TEN, Suit::CLUB },
//             new Card{ Rank::NINE, Suit::SPADE },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::SEVEN, Suit::CLUB },
//             new Card{ Rank::SIX, Suit::CLUB }
//         });
    
//     OnePairHand hand3 = new OnePairHand( 2,
//         {
//             new Card{ Rank::QUEEN, Suit::DIAMOND },
//             new Card{ Rank::JACK, Suit::SPADE },
//             new Card{ Rank::NINE, Suit::DIAMOND },
//             new Card{ Rank::SEVEN, Suit::HEART },
//             new Card{ Rank::FIVE, Suit::SPADE },
//             new Card{ Rank::THREE, Suit::DIAMOND },
//             new Card{ Rank::TWO, Suit::HEART }
//         },
//         {
//             new Card{ Rank::ACE, Suit::DIAMOND }
//         });

// 	Hands hands{ hand3, hand1, hand2 };

//     EXPECT_TRUE(hand1 > hand2);
//     EXPECT_TRUE(hand1 > hand3);

//     std::sort(hands.begin(), hands.end(), std::greater<Hand>());
//     Hands::iterator it1 = std::adjacent_find(hands.begin(), hands.end());
//     if( it1 != hands.begin() )
//     {
//         // this means that there was only one winner
        
//     }
//     else
//     {
//         std::cout << "multiple winners" << std::endl;
//     }
// }

// TEST_F(TestSuiteWinningHands, Tie)
// {
//     StraightHand hand1 = new StraightHand( 0,
//         {
//             new Card{ Rank::ACE, Suit::HEART },
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::NINE, Suit::HEART },
//             new Card{ Rank::EIGHT, Suit::CLUB },
//             new Card{ Rank::SEVEN, Suit::DIAMOND },
//             new Card{ Rank::SIX, Suit::DIAMOND },
//             new Card{ Rank::TWO, Suit::CLUB }
//         },
//         {
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::NINE, Suit::HEART },
//             new Card{ Rank::EIGHT, Suit::CLUB },
//             new Card{ Rank::SEVEN, Suit::DIAMOND },
//             new Card{ Rank::SIX, Suit::DIAMOND }
//         });
    
//     StraightHand hand2 = new StraightHand( 1,
//         {
//             new Card{ Rank::ACE, Suit::CLUB },
//             new Card{ Rank::TEN, Suit::CLUB },
//             new Card{ Rank::NINE, Suit::SPADE },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::SEVEN, Suit::CLUB },
//             new Card{ Rank::SIX, Suit::SPADE },
//             new Card{ Rank::TWO, Suit::CLUB }
//         },
//         {
//             new Card{ Rank::TEN, Suit::CLUB },
//             new Card{ Rank::NINE, Suit::SPADE },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::SEVEN, Suit::CLUB },
//             new Card{ Rank::SIX, Suit::CLUB }
//         });
    
//     OnePairHand hand3 = new OnePairHand( 2,
//         {
//             new Card{ Rank::QUEEN, Suit::DIAMOND },
//             new Card{ Rank::JACK, Suit::SPADE },
//             new Card{ Rank::NINE, Suit::DIAMOND },
//             new Card{ Rank::SEVEN, Suit::HEART },
//             new Card{ Rank::FIVE, Suit::SPADE },
//             new Card{ Rank::THREE, Suit::DIAMOND },
//             new Card{ Rank::TWO, Suit::HEART }
//         },
//         {
//             new Card{ Rank::ACE, Suit::DIAMOND }
//         });

// 	Hands hands{ hand3, hand1, hand2 };

//     EXPECT_TRUE(hand1 == hand2);
//     EXPECT_TRUE(hand1 > hand3);
// }

// TEST_F(TestSuiteWinningHands, FullHouseMatch)
// {
//     Cards cards1{
//         new Card{ Rank::EIGHT, Suit::HEART },
//         new Card{ Rank::EIGHT, Suit::DIAMOND },
//         new Card{ Rank::SEVEN, Suit::DIAMOND },
//         new Card{ Rank::SIX, Suit::DIAMOND },
//         new Card{ Rank::SIX, Suit::DIAMOND },
//         new Card{ Rank::SIX, Suit::DIAMOND },
//         new Card{ Rank::TWO, Suit::CLUB }
//     };

//     FullHouseHand* hand1 = new FullHouseHand( 0, cards1 );

//     Cards cards2{
//         new Card{ Rank::TEN, Suit::CLUB },
//         new Card{ Rank::EIGHT, Suit::CLUB },
//         new Card{ Rank::EIGHT, Suit::CLUB },
//         new Card{ Rank::EIGHT, Suit::CLUB },
//         new Card{ Rank::SIX, Suit::CLUB },
//         new Card{ Rank::SIX, Suit::CLUB },
//         new Card{ Rank::TWO, Suit::SPADE }
//     };

//     FullHouseHand* hand2 = new FullHouseHand( 1, cards2 );
    
//     Cards cards3{
//         new Card{ Rank::QUEEN, Suit::DIAMOND },
//         new Card{ Rank::JACK, Suit::SPADE },
//         new Card{ Rank::NINE, Suit::DIAMOND },
//         new Card{ Rank::SEVEN, Suit::HEART },
//         new Card{ Rank::FIVE, Suit::SPADE },
//         new Card{ Rank::THREE, Suit::DIAMOND },
//         new Card{ Rank::TWO, Suit::HEART }
//     };

//     OnePairHand* hand3 = new OnePairHand( 2, cards3 );

// 	Hands hands{ hand3, hand1, hand2 };

//     EXPECT_TRUE(*hand1 > *hand2);
//     EXPECT_TRUE(*hand1 > *hand3);

//     std::sort(hands.begin(), hands.end(),
//     [](const Hand* const lhs, const Hand* const rhs){ return *lhs > *rhs; });

//     std::cout << "Hands\n" << hands << std::endl;
// }

// }  // namespace - could surround Project1Test in a namespace
