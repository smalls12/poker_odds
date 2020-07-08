#include "OnePairHand.hpp"

#include "spdlog/spdlog.h"

OnePairHand::OnePairHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::ONE_PAIR, validated)
{

}

bool OnePairHand::operator<(const OnePairHand& rhs)
{
    spdlog::get("console")->info("OnePairHand::OnePairHand <");

    // ranks are the same
    // compare each card in the validated hands
    if( validated < rhs.validated )
    {
        // rhs is the higher one pair
        return true;
    }
    else if( validated == rhs.validated )
    {
        // same pair
        if( cards < rhs.cards )
        {
            // rhs has higher kicker cards
            return true;
        }
        else if( cards == rhs.cards )
        {
            // hands match perfectly
        }        
    }

    return false;
}

bool OnePairHand::operator>(const OnePairHand& rhs)
{
    spdlog::get("console")->info("OnePairHand::OnePairHand >");

    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool OnePairHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool OnePairHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}