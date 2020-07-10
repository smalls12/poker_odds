#include "RoyalFlushHand.hpp"

#include "spdlog/spdlog.h"

RoyalFlushHand::RoyalFlushHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::ROYAL_FLUSH, validated)
{

}

bool RoyalFlushHand::operator<(const RoyalFlushHand& rhs)
{
    spdlog::get("console")->info("RoyalFlushHand::RoyalFlushHand <");

    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool RoyalFlushHand::operator>(const RoyalFlushHand& rhs)
{
    spdlog::get("console")->info("RoyalFlushHand::RoyalFlushHand >");

    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool RoyalFlushHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool RoyalFlushHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}