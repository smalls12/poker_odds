#include "StraightFlushAceLowHand.hpp"

StraightFlushAceLowHand::StraightFlushAceLowHand(Player* player, const Cards& cards)
:   ExplicitHand(player, cards, HandRank::STRAIGHT_FLUSH_ACE_LOW)
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