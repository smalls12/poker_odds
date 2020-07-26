#include "RoyalFlushHand.hpp"

RoyalFlushHand::RoyalFlushHand(int id, const Cards& hand)
:   BaseHand(id, std::move(hand), HandRank::ROYAL_FLUSH)
{

}

bool RoyalFlushHand::operator<(const BaseHand& rhs) const noexcept
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

bool RoyalFlushHand::operator>(const BaseHand& rhs) const noexcept
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