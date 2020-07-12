#include "StraightFlushHand.hpp"

StraightFlushHand::StraightFlushHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::STRAIGHT_FLUSH, validated)
{

}

bool StraightFlushHand::operator<(const StraightFlushHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool StraightFlushHand::operator>(const StraightFlushHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool StraightFlushHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool StraightFlushHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}