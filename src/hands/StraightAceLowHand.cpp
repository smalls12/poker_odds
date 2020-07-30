#include "StraightAceLowHand.hpp"

StraightAceLowHand::StraightAceLowHand(Player* player, const Cards& cards)
:   ExplicitHand(player, cards, HandRank::STRAIGHT_ACE_LOW)
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