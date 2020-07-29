#include "FindStraightsAndFlushes.hpp"

#include <algorithm>

std::optional<HandRank> FindStraightsAndFlushes::FindRank(const std::array<Card*, 7>& cards) noexcept
{
    // default assumes we have a flush

    std::optional<HandRank> currentHandRank = std::optional<HandRank>{HandRank::FLUSH};

    // see if this hand is a flush

    Suit initialCardSuit = cards[0]->suit;

    // for (size_t i = 0; i < 7; i++)
    // {
        
    // }

    for (unsigned short x = 0; x < 7; x++ )
    {
        if( cards[0]->suit != initialCardSuit)
        {
            // at this point we know we don't have a flush

            currentHandRank = std::nullopt;
            break;
        }
    }

    // for(auto& card : *cards)
    // {
    //     if( card->suit != initialCardSuit)
    //     {
    //         // at this point we know we don't have a flush

    //         currentHandRank = std::nullopt;
    //         break;
    //     }
    // }

    // look for a straight

    if( cards[0]->rank == Rank::ACE )
    {
        // ace is first
        // could be ace low or ace high
        if( !( (cards[1]->rank == Rank::KING && cards[2]->rank == Rank::QUEEN && cards[3]->rank == Rank::JACK && cards[4]->rank == Rank::TEN) ||
               (cards[1]->rank == Rank::FIVE && cards[2]->rank == Rank::FOUR && cards[3]->rank == Rank::THREE && cards[4]->rank == Rank::TWO) ))
        {
            return currentHandRank;
        }

    }
    else
    {
        for (unsigned int i=0; i< 6; i++)
        {
            if( cards[i]->rank - cards[i+1]->rank != 1 )
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

        if( cards[4]->rank == Rank::TEN )
        {
            currentHandRank = std::optional<HandRank>{HandRank::ROYAL_FLUSH};
        }
        else if( cards[4]->rank == Rank::TWO )
        {
            currentHandRank = std::optional<HandRank>{HandRank::STRAIGHT_FLUSH_ACE_LOW};
        }
        else
        {
            currentHandRank = std::optional<HandRank>{HandRank::STRAIGHT_FLUSH};
        }   
    }
    else
    {
        // there was no flush
        if( cards[4]->rank == Rank::TWO )
        {
            currentHandRank = std::optional<HandRank>{HandRank::STRAIGHT_ACE_LOW};
        }
        else
        {
            currentHandRank = std::optional<HandRank>{HandRank::STRAIGHT};
        }
    }

    return currentHandRank;
}

std::optional<HandRank> FindStraightsAndFlushes::FindRank(const Cards& cards) noexcept
{
    // default assumes we have a flush

    std::optional<HandRank> currentHandRank = std::optional<HandRank>{HandRank::FLUSH};

    // see if this hand is a flush

    Suit initialCardSuit = cards[0]->suit;

    // for (size_t i = 0; i < 7; i++)
    // {
        
    // }

    for(auto& card : cards)
    {
        if( card->suit != initialCardSuit)
        {
            // at this point we know we don't have a flush

            currentHandRank = std::nullopt;
            break;
        }
    }

    // look for a straight

    if( cards[0]->rank == Rank::ACE )
    {
        // ace is first
        // could be ace low or ace high
        if( !( (cards[1]->rank == Rank::KING && cards[2]->rank == Rank::QUEEN && cards[3]->rank == Rank::JACK && cards[4]->rank == Rank::TEN) ||
               (cards[1]->rank == Rank::FIVE && cards[2]->rank == Rank::FOUR && cards[3]->rank == Rank::THREE && cards[4]->rank == Rank::TWO) ))
        {
            return currentHandRank;
        }

    }
    else
    {
        for (unsigned int i=0; i<cards.size() - 1; i++)
        {
            if( cards[i]->rank - cards[i+1]->rank != 1 )
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

        if( cards[4]->rank == Rank::TEN )
        {
            currentHandRank = std::optional<HandRank>{HandRank::ROYAL_FLUSH};
        }
        else if( cards[4]->rank == Rank::TWO )
        {
            currentHandRank = std::optional<HandRank>{HandRank::STRAIGHT_FLUSH_ACE_LOW};
        }
        else
        {
            currentHandRank = std::optional<HandRank>{HandRank::STRAIGHT_FLUSH};
        }   
    }
    else
    {
        // there was no flush
        if( cards[4]->rank == Rank::TWO )
        {
            currentHandRank = std::optional<HandRank>{HandRank::STRAIGHT_ACE_LOW};
        }
        else
        {
            currentHandRank = std::optional<HandRank>{HandRank::STRAIGHT};
        }
    }

    return currentHandRank;
}

std::optional<ValidatedHand> FindStraightsAndFlushes::FindRankWithValidatedCards(const Cards& cards) noexcept
{
    // default assumes we have a flush

    std::optional<ValidatedHand> currentHandRank = std::optional<ValidatedHand>{{HandRank::FLUSH, cards[0], nullptr}};

    // see if this hand is a flush

    Suit initialCardSuit = cards[0]->suit;

    // for (size_t i = 0; i < 7; i++)
    // {
        
    // }

    for(auto& card : cards)
    {
        if( card->suit != initialCardSuit)
        {
            // at this point we know we don't have a flush

            currentHandRank = std::nullopt;
            break;
        }
    }

    // look for a straight

    if( cards[0]->rank == Rank::ACE )
    {
        // ace is first
        // could be ace low or ace high
        if( !( (cards[1]->rank == Rank::KING && cards[2]->rank == Rank::QUEEN && cards[3]->rank == Rank::JACK && cards[4]->rank == Rank::TEN) ||
               (cards[1]->rank == Rank::FIVE && cards[2]->rank == Rank::FOUR && cards[3]->rank == Rank::THREE && cards[4]->rank == Rank::TWO) ))
        {
            return currentHandRank;
        }

    }
    else
    {
        for (unsigned int i=0; i<cards.size() - 1; i++)
        {
            if( cards[i]->rank - cards[i+1]->rank != 1 )
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

        if( cards[4]->rank == Rank::TEN )
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::ROYAL_FLUSH, cards[0], nullptr}};
        }
        else if( cards[4]->rank == Rank::TWO )
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT_FLUSH_ACE_LOW, cards[0], nullptr}};
        }
        else
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT_FLUSH, cards[0], nullptr}};
        }   
    }
    else
    {
        // there was no flush
        if( cards[4]->rank == Rank::TWO )
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT_ACE_LOW, cards[0], nullptr}};
        }
        else
        {
            currentHandRank = std::optional<ValidatedHand>{{HandRank::STRAIGHT, cards[0], nullptr}};
        }
    }

    return currentHandRank;
}