#include "RoyalFlushHand.hpp"

RoyalFlushHand::RoyalFlushHand(int id, const Cards& cards)
:   ExplicitHand(id, cards, HandRank::ROYAL_FLUSH)
{

}

bool RoyalFlushHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( mRank < rhs.mRank )
    {
        return true;
    }

    if( mRank > rhs.mRank )
    {
        return false;
    }

    return false;
}

bool RoyalFlushHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( mRank > rhs.mRank )
    {
        return true;
    }

    if( mRank < rhs.mRank )
    {
        return false;
    }

    return false;
}