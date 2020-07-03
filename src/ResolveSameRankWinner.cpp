#include "ResolveSameRankWinner.hpp"

#include "FindPairs.hpp"

void ResolveSameRankWinner::Resolve(HandRank rank, std::vector<Card> cards_one, std::vector<Card> cards_two)
{
    switch(rank)
    {
        case HandRank::ROYAL_FLUSH:
        {
            break;
        }
        case HandRank::STRAIGHT_FLUSH:
        {
            break;
        }
        case HandRank::FOUR_OF_A_KIND:
        {
            break;
        }
        case HandRank::FULL_HOUSE:
        {
            break;
        }
        case HandRank::FLUSH:
        {
            break;
        }
        case HandRank::STRAIGHT:
        {
            break;
        }
        case HandRank::THREE_OF_A_KIND:
        {
            break;
        }
        case HandRank::TWO_PAIR:
        {
            break;
        }
        case HandRank::ONE_PAIR:
        {
            auto result_one = FindPairs::Find(cards_one);
            auto result_two = FindPairs::Find(cards_two);

            if( result_one && result_two)
            {
                // if( *result_one[0] < *result_two[0] )
                // {

                // }
            }

            break;
        }
        case HandRank::HIGH_CARD:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}