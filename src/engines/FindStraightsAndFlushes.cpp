#include "FindStraightsAndFlushes.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

std::optional<ValidatedHand> FindStraightsAndFlushes::Find(std::vector<Card> cards)
{
    if( cards.size() < 5 )
    {
        return std::nullopt;
    }

    std::vector<Card> temp(cards);

    // default assumes we have a flush

    std::optional<ValidatedHand> currentHandRank = std::optional<ValidatedHand>{{HandRank::FLUSH, temp}};

    // see if this hand is a flush

    Suit initialCardSuit = temp[0].suit;

    for(auto& card : temp)
    {
        if( card.suit != initialCardSuit)
        {
            // at this point we know we don't have a flush

            currentHandRank = std::nullopt;
            break;
        }
    }

    // look for a straight

    for (unsigned int i=0; i<temp.size() - 1; i++)
    {
		if( temp[i+1].rank - temp[i].rank != 1 )
		{
            // at this point we know we don't have a straight

            // exit early indicating flush or no flush

            return currentHandRank;
		}
	}

    // at this point we know we have a straight

    if( currentHandRank )
    {
        // we have a flush as well

        // check for royal flush

        if( temp[0].rank == Rank::TEN )
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::ROYAL_FLUSH, temp}};
        }
        else
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT_FLUSH, temp}};
        }   
    }
    else
    {
        // there was no flush

        currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT, temp}};
    }

    return currentHandRank;
}