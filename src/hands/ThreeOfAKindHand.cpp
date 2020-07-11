#include "ThreeOfAKindHand.hpp"

#include "spdlog/spdlog.h"

ThreeOfAKindHand::ThreeOfAKindHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::THREE_OF_A_KIND, validated)
{

}

bool ThreeOfAKindHand::operator<(ThreeOfAKindHand rhs)
{
    spdlog::get("console")->info("ThreeOfAKindHand::ThreeOfAKindHand <");

    // ranks are the same
    // compare each card in the validated hands
    return std::equal(  std::begin(cards), std::end(cards),
                        std::begin(rhs.cards), std::end(rhs.cards),
                        [](const Card* lhs, const Card* rhs){ return *lhs < *rhs; });
}

bool ThreeOfAKindHand::operator>(ThreeOfAKindHand rhs)
{
    spdlog::get("console")->info("ThreeOfAKindHand::ThreeOfAKindHand >");

    // ranks are the same
    // compare each card in the validated hands
    return std::equal(  std::begin(cards), std::end(cards),
                        std::begin(rhs.cards), std::end(rhs.cards),
                        [](const Card* lhs, const Card* rhs){ return *lhs > *rhs; });
}

bool ThreeOfAKindHand::operator<(BaseHand rhs)
{
    return BaseHand::operator<(rhs);
}

bool ThreeOfAKindHand::operator>(BaseHand rhs)
{
    return BaseHand::operator>(rhs);
}
