#include "ResolveSameRankWinner.hpp"

#include "FindPairs.hpp"

#include <iostream>

void ResolveSameRankWinner::Resolve(Hand hand1, Hand hand2)
{
    (void)hand1;
    (void)hand2;
    
    // for(auto& card : hand1.cards)
    // {
    //     std::cout << card;
    // }

    // std::cout << " vs ";

    // for(auto& card : hand2.cards)
    // {
    //     std::cout << card;
    // }

    // std::cout << std::endl;

    // switch(rank.rank)
    // {
    //     case HandRank::ROYAL_FLUSH:
    //     {
    //         break;
    //     }
    //     case HandRank::STRAIGHT_FLUSH:
    //     {
    //         break;
    //     }
    //     case HandRank::FOUR_OF_A_KIND:
    //     {
    //         break;
    //     }
    //     case HandRank::FULL_HOUSE:
    //     {
    //         break;
    //     }
    //     case HandRank::FLUSH:
    //     {
    //         break;
    //     }
    //     case HandRank::STRAIGHT:
    //     {
    //         break;
    //     }
    //     case HandRank::THREE_OF_A_KIND:
    //     {
    //         break;
    //     }
    //     case HandRank::TWO_PAIR:
    //     {
    //         break;
    //     }
    //     case HandRank::ONE_PAIR:
    //     {
    //         auto result_one = FindPairs::Find(cards_one);
    //         auto result_two = FindPairs::Find(cards_two);

    //         if( result_one && result_two)
    //         {
    //             // if( *result_one[0] < *result_two[0] )
    //             // {

    //             // }
    //         }

    //         break;
    //     }
    //     case HandRank::HIGH_CARD:
    //     {
    //         break;
    //     }
    //     default:
    //     {
    //         break;
    //     }
    // }
}