#include "ThreeOfAKindHand.hpp"

#include "spdlog/spdlog.h"

ThreeOfAKindHand::ThreeOfAKindHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::THREE_OF_A_KIND, validated)
{

}

bool ThreeOfAKindHand::operator<(ThreeOfAKindHand rhs)
{
    spdlog::get("console")->info("ThreeOfAKindHand::ThreeOfAKindHand <");

    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool ThreeOfAKindHand::operator>(ThreeOfAKindHand rhs)
{
    spdlog::get("console")->info("ThreeOfAKindHand::ThreeOfAKindHand >");

    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool ThreeOfAKindHand::operator<(BaseHand rhs)
{
    return BaseHand::operator<(rhs);
}

bool ThreeOfAKindHand::operator>(BaseHand rhs)
{
    return BaseHand::operator>(rhs);
}
