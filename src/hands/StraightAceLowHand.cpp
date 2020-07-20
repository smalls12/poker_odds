#include "StraightAceLowHand.hpp"

StraightAceLowHand::StraightAceLowHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::STRAIGHT_ACE_LOW, validated)
{

}

bool StraightAceLowHand::operator<(const StraightAceLowHand& rhs) const noexcept
{
    (void)rhs;
    return false;
}

bool StraightAceLowHand::operator>(const StraightAceLowHand& rhs) const noexcept
{
    (void)rhs;
    return false;
}

bool StraightAceLowHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool StraightAceLowHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}