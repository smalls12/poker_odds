#include "FullHouseHand.hpp"

#include "spdlog/spdlog.h"

FullHouseHand::FullHouseHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::FULL_HOUSE, validated)
{

}

bool FullHouseHand::operator<(const FullHouseHand& rhs)
{
    spdlog::get("console")->info("FullHouseHand::FullHouseHand <");

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
    spdlog::get("console")->info("FullHouseHand::FullHouseHand >");

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