#include "StraightAceLowHand.hpp"

StraightAceLowHand::StraightAceLowHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::STRAIGHT_ACE_LOW, validated)
{

}

bool StraightAceLowHand::operator<(const StraightAceLowHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool StraightAceLowHand::operator>(const StraightAceLowHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool StraightAceLowHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool StraightAceLowHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}