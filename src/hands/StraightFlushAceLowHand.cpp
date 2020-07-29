#include "StraightFlushAceLowHand.hpp"

StraightFlushAceLowHand::StraightFlushAceLowHand(int id, const Cards& cards)
:   ExplicitHand(id, cards, HandRank::STRAIGHT_FLUSH_ACE_LOW)
{

}

bool StraightFlushAceLowHand::operator<(const ExplicitHand& rhs) const noexcept
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

bool StraightFlushAceLowHand::operator>(const ExplicitHand& rhs) const noexcept
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