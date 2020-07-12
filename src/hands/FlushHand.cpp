#include "FlushHand.hpp"

FlushHand::FlushHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::FLUSH, validated)
{

}

bool FlushHand::operator<(FlushHand rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool FlushHand::operator>(FlushHand rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool FlushHand::operator<(BaseHand rhs)
{
    return BaseHand::operator<(rhs);
}

bool FlushHand::operator>(BaseHand rhs)
{
    return BaseHand::operator>(rhs);
}