#include "TwoPairHand.hpp"

#include <iostream>

TwoPairHand::TwoPairHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::TWO_PAIR, validated)
{

}

bool TwoPairHand::operator<(const TwoPairHand& rhs) const noexcept
{
    if( *validated[0] < *rhs.validated[0] )
    {
        return true;
    }
    else if( *validated[0] > *rhs.validated[0] )
    {
        return false;
    }
    
    if( *validated[2] < *rhs.validated[0] )
    {
        return true;
    }
    else if( *validated[2] > *rhs.validated[0] )
    {
        return false;
    }

    for(size_t x = 0; x < cards.size(); x++)
    {
        if( *cards[x] < *rhs.cards[x] )
        {
            return true;
        }
        else if( *cards[x] == *rhs.cards[x] )
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool TwoPairHand::operator>(const TwoPairHand& rhs) const noexcept
{
    if( *validated[0] > *rhs.validated[0] )
    {
        return true;
    }
    else if( *validated[0] < *rhs.validated[0] )
    {
        return false;
    }
    
    if( *validated[2] > *rhs.validated[2] )
    {
        return true;
    }
    else if( *validated[2] < *rhs.validated[2] )
    {
        return false;
    }

    for(size_t x = 0; x < cards.size(); x++)
    {
        if( *cards[x] > *rhs.cards[x] )
        {
            return true;
        }
        else if( *cards[x] == *rhs.cards[x] )
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool TwoPairHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool TwoPairHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}