#include "RoyalFlushHand.hpp"

RoyalFlushHand::RoyalFlushHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::ROYAL_FLUSH, validated)
{

}

bool RoyalFlushHand::operator<(const RoyalFlushHand& rhs) const noexcept
{
    (void)rhs;
    return false;
}

bool RoyalFlushHand::operator>(const RoyalFlushHand& rhs) const noexcept
{
    (void)rhs;
    return false;
}

bool RoyalFlushHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool RoyalFlushHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}