#include "ThreeOfAKindHand.hpp"

ThreeOfAKindHand::ThreeOfAKindHand(int id, const Cards& cards)
:   ExplicitHand(id, cards, HandRank::THREE_OF_A_KIND)
{

}

bool ThreeOfAKindHand::operator<(const ExplicitHand& rhs) const noexcept
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

bool ThreeOfAKindHand::operator>(const ExplicitHand& rhs) const noexcept
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
