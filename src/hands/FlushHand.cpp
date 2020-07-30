#include "FlushHand.hpp"

FlushHand::FlushHand(Player* player, const Cards& cards)
:   ExplicitHand(player, cards, HandRank::FLUSH)
{

}

bool FlushHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( mRank < rhs.mRank )
    {
        return true;
    }

    if( mRank > rhs.mRank )
    {
        return false;
    }

    // for(size_t x = 0; x < validated.size(); x++)
    // {
    //     if( *validated[x] < *rhs.validated[x] )
    //     {
    //         return true;
    //     }
    //     else if( *validated[x] > *rhs.validated[x] )
    //     {
    //         return false;
    //     }
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

bool FlushHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( mRank > rhs.mRank )
    {
        return true;
    }

    if( mRank < rhs.mRank )
    {
        return false;
    }

    // for(size_t x = 0; x < validated.size(); x++)
    // {
    //     if( *validated[x] > *rhs.validated[x] )
    //     {
    //         return true;
    //     }
    //     else if( *validated[x] < *rhs.validated[x] )
    //     {
    //         return false;
    //     }
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