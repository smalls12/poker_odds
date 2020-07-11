#include "StraightFlushAceLowHand.hpp"

StraightFlushAceLowHand::StraightFlushAceLowHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::STRAIGHT_FLUSH_ACE_LOW, validated)
{

}

bool StraightFlushAceLowHand::operator<(const StraightFlushAceLowHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool StraightFlushAceLowHand::operator>(const StraightFlushAceLowHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool StraightFlushAceLowHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool StraightFlushAceLowHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}