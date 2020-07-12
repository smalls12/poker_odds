#include "StraightHand.hpp"

StraightHand::StraightHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::STRAIGHT, validated)
{

}

bool StraightHand::operator<(StraightHand rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool StraightHand::operator>(StraightHand rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool StraightHand::operator<(BaseHand rhs)
{
    return BaseHand::operator<(rhs);
}

bool StraightHand::operator>(BaseHand rhs)
{
    return BaseHand::operator>(rhs);
}