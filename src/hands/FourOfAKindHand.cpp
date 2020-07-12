#include "FourOfAKindHand.hpp"

FourOfAKindHand::FourOfAKindHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::FOUR_OF_A_KIND, validated)
{

}

bool FourOfAKindHand::operator<(FourOfAKindHand rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool FourOfAKindHand::operator>(FourOfAKindHand rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool FourOfAKindHand::operator<(BaseHand rhs)
{
    return BaseHand::operator<(rhs);
}

bool FourOfAKindHand::operator>(BaseHand rhs)
{
    return BaseHand::operator>(rhs);
}