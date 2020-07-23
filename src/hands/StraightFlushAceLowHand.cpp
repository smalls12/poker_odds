#include "StraightFlushAceLowHand.hpp"

StraightFlushAceLowHand::StraightFlushAceLowHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::STRAIGHT_FLUSH_ACE_LOW, validated)
{

}

bool StraightFlushAceLowHand::operator<(const BaseHand& rhs) const noexcept
{
    if( rank < rhs.rank )
    {
        return true;
    }

    if( rank > rhs.rank )
    {
        return false;
    }

    return false;
}

bool StraightFlushAceLowHand::operator>(const BaseHand& rhs) const noexcept
{
    if( rank > rhs.rank )
    {
        return true;
    }

    if( rank < rhs.rank )
    {
        return false;
    }

    return false;
}