#include "RoyalFlushHand.hpp"

RoyalFlushHand::RoyalFlushHand(Player& player)
:   ExplicitHand(player, HandRank::ROYAL_FLUSH)
{

}

bool RoyalFlushHand::operator<(const ExplicitHand& rhs) const noexcept
{
    return static_cast<ExplicitHand>(*this) < rhs;
}

bool RoyalFlushHand::operator>(const ExplicitHand& rhs) const noexcept
{
    return static_cast<ExplicitHand>(*this) > rhs;
}
