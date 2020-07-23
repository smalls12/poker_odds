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
// TEST_F(TestSuiteWinningHands, OnePairMatch)
// {
//     OnePairHand hand1 = new OnePairHand( 0,
//         {
//             new Card{ Rank::ACE, Suit::DIAMOND },
//             new Card{ Rank::TEN, Suit::SPADE },
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::SIX, Suit::SPADE },
//             new Card{ Rank::FOUR, Suit::DIAMOND },
//             new Card{ Rank::TWO, Suit::CLUB }
//         },
//         {
//             new Card{ Rank::TEN, Suit::SPADE },
//             new Card{ Rank::TEN, Suit::DIAMOND }
//         });
    
//     OnePairHand hand2 = new OnePairHand( 1,
//         {
//             new Card{ Rank::ACE, Suit::CLUB },
//             new Card{ Rank::TEN, Suit::HEART },
//             new Card{ Rank::TEN, Suit::CLUB },
//             new Card{ Rank::EIGHT, Suit::SPADE },
//             new Card{ Rank::SIX, Suit::DIAMOND },
//             new Card{ Rank::FOUR, Suit::CLUB },
//             new Card{ Rank::TWO, Suit::SPADE }
//         },
//         {
//             new Card{ Rank::TEN, Suit::SPADE },
//             new Card{ Rank::TEN, Suit::DIAMOND }
//         });
    
//     HighCardHand hand3 = new HighCardHand( 2,
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
//     EXPECT_TRUE(hand2 > hand3);

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

// TEST_F(TestSuiteWinningHands, TwoPairMatch)
// {
//     TwoPairHand hand1 = new TwoPairHand( 0,
//         {
//             new Card{ Rank::ACE, Suit::DIAMOND },
//             new Card{ Rank::TEN, Suit::SPADE },
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::EIGHT, Suit::SPADE },
//             new Card{ Rank::FOUR, Suit::DIAMOND },
//             new Card{ Rank::TWO, Suit::CLUB }
//         },
//         {
//             new Card{ Rank::TEN, Suit::SPADE },
//             new Card{ Rank::TEN, Suit::DIAMOND },
//             new Card{ Rank::EIGHT, Suit::DIAMOND },
//             new Card{ Rank::EIGHT, Suit::SPADE }
//         });
    
//     TwoPairHand hand2 = new TwoPairHand( 1,
//         {
//             new Card{ Rank::KING, Suit::CLUB },
//             new Card{ Rank::JACK, Suit::HEART },
//             new Card{ Rank::JACK, Suit::CLUB },
//             new Card{ Rank::EIGHT, Suit::CLUB },
//             new Card{ Rank::EIGHT, Suit::HEART },
//             new Card{ Rank::THREE, Suit::CLUB },
//             new Card{ Rank::TWO, Suit::SPADE }
//         },
//         {
//             new Card{ Rank::JACK, Suit::HEART },
//             new Card{ Rank::JACK, Suit::CLUB },
//             new Card{ Rank::EIGHT, Suit::CLUB },
//             new Card{ Rank::EIGHT, Suit::HEART }
//         });
    
//     HighCardHand hand3 = new HighCardHand( 2,
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

TEST_F(TestSuiteWinningHands, FullHouseMatch)
{
    FullHouseHand* hand1 = new FullHouseHand( 0,
        {
            new Card{ Rank::EIGHT, Suit::HEART },
            new Card{ Rank::EIGHT, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::DIAMOND },
            new Card{ Rank::SIX, Suit::DIAMOND },
            new Card{ Rank::SIX, Suit::DIAMOND },
            new Card{ Rank::SIX, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::CLUB }
        },
        {
            new Card{ Rank::SIX, Suit::DIAMOND },
            new Card{ Rank::SIX, Suit::DIAMOND },
            new Card{ Rank::SIX, Suit::DIAMOND },
            new Card{ Rank::EIGHT, Suit::HEART },
            new Card{ Rank::EIGHT, Suit::DIAMOND }
        });
    
    FullHouseHand* hand2 = new FullHouseHand( 1,
        {
            new Card{ Rank::TEN, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::SIX, Suit::CLUB },
            new Card{ Rank::SIX, Suit::CLUB },
            new Card{ Rank::TWO, Suit::SPADE }
        },
        {
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::EIGHT, Suit::CLUB },
            new Card{ Rank::SIX, Suit::CLUB },
            new Card{ Rank::SIX, Suit::CLUB }
        });
    
    OnePairHand* hand3 = new OnePairHand( 2,
        {
            new Card{ Rank::QUEEN, Suit::DIAMOND },
            new Card{ Rank::JACK, Suit::SPADE },
            new Card{ Rank::NINE, Suit::DIAMOND },
            new Card{ Rank::SEVEN, Suit::HEART },
            new Card{ Rank::FIVE, Suit::SPADE },
            new Card{ Rank::THREE, Suit::DIAMOND },
            new Card{ Rank::TWO, Suit::HEART }
        },
        {
            new Card{ Rank::ACE, Suit::DIAMOND }
        });

	Hands hands{ hand3, hand1, hand2 };

    EXPECT_TRUE(*hand1 > *hand2);
    EXPECT_TRUE(*hand1 > *hand3);

    std::sort(hands.begin(), hands.end(),
    [](const Hand* const lhs, const Hand* const rhs){ return *lhs > *rhs; });

    std::cout << "Hands\n" << hands << std::endl;
}

// }  // namespace - could surround Project1Test in a namespace
