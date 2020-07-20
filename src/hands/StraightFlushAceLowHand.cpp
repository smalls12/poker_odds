#include "StraightFlushAceLowHand.hpp"

StraightFlushAceLowHand::StraightFlushAceLowHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::STRAIGHT_FLUSH_ACE_LOW, validated)
{

}

bool StraightFlushAceLowHand::operator<(const StraightFlushAceLowHand& rhs) const noexcept
{
    (void)rhs;
    return false;
}

bool StraightFlushAceLowHand::operator>(const StraightFlushAceLowHand& rhs) const noexcept
{
    (void)rhs;
    return false;
}

bool StraightFlushAceLowHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool StraightFlushAceLowHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}