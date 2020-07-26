#include "StraightAceLowHand.hpp"

StraightAceLowHand::StraightAceLowHand(int id, const Cards& hand)
:   BaseHand(id, std::move(hand), HandRank::STRAIGHT_ACE_LOW)
{

}

bool StraightAceLowHand::operator<(const BaseHand& rhs) const noexcept
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

bool StraightAceLowHand::operator>(const BaseHand& rhs) const noexcept
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