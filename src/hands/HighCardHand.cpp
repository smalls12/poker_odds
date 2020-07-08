#include "HighCardHand.hpp"

#include "spdlog/spdlog.h"

HighCardHand::HighCardHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::HIGH_CARD, validated)
{

}

bool HighCardHand::operator<(const HighCardHand& rhs)
{
    spdlog::get("console")->info("HighCardHand::HighCardHand <");

    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool HighCardHand::operator>(const HighCardHand& rhs)
{
    spdlog::get("console")->info("HighCardHand::HighCardHand >");

    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool HighCardHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool HighCardHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}