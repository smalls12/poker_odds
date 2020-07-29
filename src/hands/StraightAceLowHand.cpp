#include "StraightAceLowHand.hpp"

StraightAceLowHand::StraightAceLowHand(int id, const Cards& cards)
:   ExplicitHand(id, cards, HandRank::STRAIGHT_ACE_LOW)
{

}

bool StraightAceLowHand::operator<(const ExplicitHand& rhs) const noexcept
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

bool StraightAceLowHand::operator>(const ExplicitHand& rhs) const noexcept
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