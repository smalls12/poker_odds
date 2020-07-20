#include "FlushHand.hpp"

FlushHand::FlushHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::FLUSH, validated)
{

}

bool FlushHand::operator<(const FlushHand& rhs) const noexcept
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool FlushHand::operator>(const FlushHand& rhs) const noexcept
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool FlushHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool FlushHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}