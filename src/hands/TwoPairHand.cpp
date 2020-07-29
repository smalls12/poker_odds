#include "TwoPairHand.hpp"

#include <iostream>

TwoPairHand::TwoPairHand(int id, const Cards& cards)
:   ExplicitHand(id, cards, HandRank::TWO_PAIR)
{

}

bool TwoPairHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( mRank < rhs.mRank )
    {
        return true;
    }

    if( mRank > rhs.mRank )
    {
        return false;
    }

    // if( *validated[0] < *rhs.validated[0] )
    // {
    //     return true;
    // }
    // else if( *validated[0] > *rhs.validated[0] )
    // {
    //     return false;
    // }
    
    // if( *validated[2] < *rhs.validated[0] )
    // {
    //     return true;
    // }
    // else if( *validated[2] > *rhs.validated[0] )
    // {
    //     return false;
    // }

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

bool TwoPairHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( mRank > rhs.mRank )
    {
        return true;
    }

    if( mRank < rhs.mRank )
    {
        return false;
    }

    // if( *validated[0] > *rhs.validated[0] )
    // {
    //     return true;
    // }
    // else if( *validated[0] < *rhs.validated[0] )
    // {
    //     return false;
    // }
    
    // if( *validated[1] > *rhs.validated[1] )
    // {
    //     return true;
    // }
    // else if( *validated[1] < *rhs.validated[1] )
    // {
    //     return false;
    // }

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