#include "FullHouseHand.hpp"

FullHouseHand::FullHouseHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::FULL_HOUSE, validated)
{

}

bool FullHouseHand::operator<(const FullHouseHand& rhs) const noexcept
{
    // check the 3 of a kind
    if( *validated[0] < *rhs.validated[0] )
    {
       return true;
    }
    else if( *validated[0] > *rhs.validated[0] )
    {
        return false;
    }

    // check the pair
    if( *validated[3] < *rhs.validated[3] )
    {
        return true;
    }
    else if( *validated[3] > *rhs.validated[3] )
    {
        return false;
    }

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

bool FullHouseHand::operator>(const FullHouseHand& rhs) const noexcept
{
    // check the 3 of a kind
    if( *validated[0] > *rhs.validated[0] )
    {
       return true;
    }
    else if( *validated[0] < *rhs.validated[0] )
    {
        return false;
    }

    // check the pair
    if( *validated[3] > *rhs.validated[3] )
    {
        return true;
    }
    else if( *validated[3] < *rhs.validated[3] )
    {
        return false;
    }

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

bool FullHouseHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool FullHouseHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}