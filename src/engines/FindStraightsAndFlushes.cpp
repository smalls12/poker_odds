#include "FindStraightsAndFlushes.hpp"

#include <algorithm>

std::optional<ValidatedHand> FindStraightsAndFlushes::Find(const Cards& cards) noexcept
{
    if( cards.size() < 5 )
    {
        return std::nullopt;
    }

    Cards temp(cards);

    // default assumes we have a flush

    std::optional<ValidatedHand> currentHandRank = std::optional<ValidatedHand>{{HandRank::FLUSH, temp}};

    // see if this hand is a flush

    Suit initialCardSuit = temp[0]->suit;

    for(auto& card : temp)
    {
        // if( card == nullptr )
        // {
        //     spdlog::get("console")->info("FindStraightsAndFlushes::Find - nullptr");
        // }

        if( card->suit != initialCardSuit)
        {
            // at this point we know we don't have a flush

            currentHandRank = std::nullopt;
            break;
        }
    }

    // look for a straight

    if( temp[0]->rank == Rank::ACE )
    {
        // ace is first
        // could be ace low or ace high
        if( !( (temp[1]->rank == Rank::KING && temp[2]->rank == Rank::QUEEN && temp[3]->rank == Rank::JACK && temp[4]->rank == Rank::TEN) ||
               (temp[1]->rank == Rank::FIVE && temp[2]->rank == Rank::FOUR && temp[3]->rank == Rank::THREE && temp[4]->rank == Rank::TWO) ))
        {
            return currentHandRank;
        }

    }
    else
    {
        for (unsigned int i=0; i<temp.size() - 1; i++)
        {
            if( temp[i]->rank - temp[i+1]->rank != 1 )
            {
                // at this point we know we don't have a straight

                // exit early indicating flush or no flush

                return currentHandRank;
            }
        }
    }

    // at this point we know we have a straight

    if( currentHandRank )
    {
        // we have a flush as well

        // check for royal flush

        if( temp[4]->rank == Rank::TEN )
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::ROYAL_FLUSH, temp}};
        }
        else if( temp[4]->rank == Rank::TWO )
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT_FLUSH_ACE_LOW, temp}};
        }
        else
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT_FLUSH, temp}};
        }   
    }
    else
    {
        // there was no flush
        if( temp[4]->rank == Rank::TWO )
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT_ACE_LOW, temp}};
        }
        else
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT, temp}};
        }
    }

    return currentHandRank;
}