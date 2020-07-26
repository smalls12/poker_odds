#include "FullHouseHand.hpp"

FullHouseHand::FullHouseHand(int id, const Cards& hand)
:   BaseHand(id, std::move(hand), HandRank::FULL_HOUSE)
{

}

bool FullHouseHand::operator<(const BaseHand& rhs) const noexcept
{
    if( rank < rhs.rank )
    {
        return true;
    }

    if( rank > rhs.rank )
    {
        return false;
    }

    // check the 3 of a kind
    // if( *validated[0] < *rhs.validated[0] )
    // {
    //     return true;
    // }
    // else if( *validated[0] > *rhs.validated[0] )
    // {
    //     return false;
    // }

    // check the pair
    // if( *validated[1] < *rhs.validated[1] )
    // {
    //     return true;
    // }
    // else if( *validated[1] > *rhs.validated[1] )
    // {
    //     return false;
    // }

    // check remaining cards
    for(size_t x = 0; x < cards.size(); x++)
    {
        if( *cards[x] < *rhs.cards[x] )
        {
            return true;
        }
        else if( *cards[x] > *rhs.cards[x] )
        {
            return false;
        }
    }
    
    return false;
}

bool FullHouseHand::operator>(const BaseHand& rhs) const noexcept
{
    if( rank > rhs.rank )
    {
        return true;
    }

    if( rank < rhs.rank )
    {
        return false;
    }

    // check the 3 of a kind
    // if( *validated[0] > *rhs.validated[0] )
    // {
    //     return true;
    // }
    // else if( *validated[0] < *rhs.validated[0] )
    // {
    //     return false;
    // }

    // check the pair
    // if( *validated[1] > *rhs.validated[1] )
    // {
    //     return true;
    // }
    // else if( *validated[1] < *rhs.validated[1] )
    // {
    //     return false;
    // }

    // check remaining cards
    for(size_t x = 0; x < cards.size(); x++)
    {
        if( *cards[x] > *rhs.cards[x] )
        {
            return true;
        }
        else if( *cards[x] < *rhs.cards[x] )
        {
            return false;
        }
    }

    return false;
}