#include "FullHouseHand.hpp"

FullHouseHand::FullHouseHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::FULL_HOUSE, validated)
{

}

bool FullHouseHand::operator<(const FullHouseHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool FullHouseHand::operator>(const FullHouseHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool FullHouseHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool FullHouseHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}