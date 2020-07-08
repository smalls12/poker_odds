#include "FlushHand.hpp"

#include "spdlog/spdlog.h"

FlushHand::FlushHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::FLUSH, validated)
{

}

bool FlushHand::operator<(FlushHand rhs)
{
    spdlog::get("console")->info("FlushHand::FlushHand <");

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
    spdlog::get("console")->info("FlushHand::FlushHand >");

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