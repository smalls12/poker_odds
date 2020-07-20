#include "StraightFlushHand.hpp"

StraightFlushHand::StraightFlushHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::STRAIGHT_FLUSH, validated)
{

}

bool StraightFlushHand::operator<(const StraightFlushHand& rhs) const noexcept
{
    if( *cards[0] < *rhs.cards[0] )
    {
        return true;
    }

    return false;
}

bool StraightFlushHand::operator>(const StraightFlushHand& rhs) const noexcept
{
    if( *cards[0] > *rhs.cards[0] )
    {
        return true;
    }

    return false;
}

bool StraightFlushHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool StraightFlushHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}