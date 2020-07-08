#include "TwoPairHand.hpp"

#include "spdlog/spdlog.h"

TwoPairHand::TwoPairHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::TWO_PAIR, validated)
{

}

bool TwoPairHand::operator<(TwoPairHand rhs)
{
    spdlog::get("console")->info("TwoPairHand::TwoPairHand <");

    // ranks are the same
    // compare each card in the validated hands
    if( cards < rhs.cards )
    {
        return true;
    }

    return false;
}

bool TwoPairHand::operator>(TwoPairHand rhs)
{
    spdlog::get("console")->info("TwoPairHand::TwoPairHand >");

    // ranks are the same
    // compare each card in the validated hands
    if( cards > rhs.cards )
    {
        return true;
    }

    return false;
}

bool TwoPairHand::operator<(BaseHand rhs)
{
    return BaseHand::operator<(rhs);
}

bool TwoPairHand::operator>(BaseHand rhs)
{
    return BaseHand::operator>(rhs);
}