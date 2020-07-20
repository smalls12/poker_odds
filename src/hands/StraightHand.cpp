#include "StraightHand.hpp"

StraightHand::StraightHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::STRAIGHT, validated)
{

}

bool StraightHand::operator<(const StraightHand& rhs) const noexcept
{
    if( *cards[0] < *rhs.cards[0] )
    {
        return true;
    }

    return false;
}

bool StraightHand::operator>(const StraightHand& rhs) const noexcept
{
    if( *cards[0] > *rhs.cards[0] )
    {
        return true;
    }

    return false;
}

bool StraightHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool StraightHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}