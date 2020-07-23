#include "RoyalFlushHand.hpp"

RoyalFlushHand::RoyalFlushHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::ROYAL_FLUSH, validated)
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