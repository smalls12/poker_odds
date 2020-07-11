#include "TwoPairHand.hpp"

#include "spdlog/spdlog.h"

TwoPairHand::TwoPairHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::TWO_PAIR, validated)
{

}

bool TwoPairHand::operator<(TwoPairHand rhs)
{
    spdlog::get("console")->info("TwoPairHand::TwoPairHand <");

    // ranks are the same
    // compare each card in the validated hands
    return std::equal(  std::begin(cards), std::end(cards),
                        std::begin(rhs.cards), std::end(rhs.cards),
                        [](const Card* lhs, const Card* rhs){ return *lhs < *rhs; });
}

bool TwoPairHand::operator>(TwoPairHand rhs)
{
    spdlog::get("console")->info("TwoPairHand::TwoPairHand >");

    // ranks are the same
    // compare each card in the validated hands
    return std::equal(  std::begin(cards), std::end(cards),
                        std::begin(rhs.cards), std::end(rhs.cards),
                        [](const Card* lhs, const Card* rhs){ return *lhs > *rhs; });
}

bool TwoPairHand::operator<(BaseHand rhs)
{
    return BaseHand::operator<(rhs);
}

bool TwoPairHand::operator>(BaseHand rhs)
{
    return BaseHand::operator>(rhs);
}