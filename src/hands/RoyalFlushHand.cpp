#include "RoyalFlushHand.hpp"

RoyalFlushHand::RoyalFlushHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::ROYAL_FLUSH, validated)
{

}

bool RoyalFlushHand::operator<(const RoyalFlushHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool RoyalFlushHand::operator>(const RoyalFlushHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool RoyalFlushHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool RoyalFlushHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}