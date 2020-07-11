#include "HighCardHand.hpp"

#include "spdlog/spdlog.h"

HighCardHand::HighCardHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::HIGH_CARD, validated)
{

}

bool HighCardHand::operator<(const HighCardHand& rhs)
{
    spdlog::get("console")->info("HighCardHand::HighCardHand <");

    // ranks are the same
    // compare each card in the validated hands
    return std::equal(  std::begin(cards), std::end(cards),
                        std::begin(rhs.cards), std::end(rhs.cards),
                        [](const Card* lhs, const Card* rhs){ return *lhs < *rhs; });
}

bool HighCardHand::operator>(const HighCardHand& rhs)
{
    spdlog::get("console")->info("HighCardHand::HighCardHand >");

    // ranks are the same
    // compare each card in the validated hands
    return std::equal(  std::begin(cards), std::end(cards),
                        std::begin(rhs.cards), std::end(rhs.cards),
                        [](const Card* lhs, const Card* rhs){ return *lhs > *rhs; });
}

bool HighCardHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool HighCardHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}