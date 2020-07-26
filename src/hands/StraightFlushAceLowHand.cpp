#include "StraightFlushAceLowHand.hpp"

StraightFlushAceLowHand::StraightFlushAceLowHand(int id, const Cards& hand)
:   BaseHand(id, std::move(hand), HandRank::STRAIGHT_FLUSH_ACE_LOW)
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