#include "FourOfAKindHand.hpp"

#include "spdlog/spdlog.h"

FourOfAKindHand::FourOfAKindHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::FOUR_OF_A_KIND, validated)
{

}

bool FourOfAKindHand::operator<(FourOfAKindHand rhs)
{
    spdlog::get("console")->info("FourOfAKindHand::FourOfAKindHand <");

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
    spdlog::get("console")->info("FourOfAKindHand::FourOfAKindHand >");

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