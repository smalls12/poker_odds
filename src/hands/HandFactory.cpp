#include "HandFactory.hpp"

#include <map>
#include <functional>

std::map<HandRank, std::function<Hand(int id, const Cards& cards, const Cards& validated)>> router{
    { HandRank::ROYAL_FLUSH, [](int id, const Cards& cards, const Cards& validated){ return RoyalFlushHand(id, cards, validated); } },
    { HandRank::STRAIGHT_FLUSH, [](int id, const Cards& cards, const Cards& validated){ return StraightFlushHand(id, cards, validated); } },
    { HandRank::STRAIGHT_FLUSH_ACE_LOW, [](int id, const Cards& cards, const Cards& validated){ return StraightFlushAceLowHand(id, cards, validated); } },
    { HandRank::FOUR_OF_A_KIND, [](int id, const Cards& cards, const Cards& validated){ return FourOfAKindHand(id, cards, validated); } },
    { HandRank::FULL_HOUSE, [](int id, const Cards& cards, const Cards& validated){ return FullHouseHand(id, cards, validated); } },
    { HandRank::FLUSH, [](int id, const Cards& cards, const Cards& validated){ return FlushHand(id, cards, validated); } },
    { HandRank::STRAIGHT, [](int id, const Cards& cards, const Cards& validated){ return StraightHand(id, cards, validated); } },
    { HandRank::STRAIGHT_ACE_LOW, [](int id, const Cards& cards, const Cards& validated){ return StraightAceLowHand(id, cards, validated); } },
    { HandRank::THREE_OF_A_KIND, [](int id, const Cards& cards, const Cards& validated){ return ThreeOfAKindHand(id, cards, validated); } },
    { HandRank::TWO_PAIR, [](int id, const Cards& cards, const Cards& validated){ return TwoPairHand(id, cards, validated); } },
    { HandRank::ONE_PAIR, [](int id, const Cards& cards, const Cards& validated){ return OnePairHand(id, cards, validated); } },
    { HandRank::HIGH_CARD, [](int id, const Cards& cards, const Cards& validated){ return HighCardHand(id, cards, validated); } },
};

Hand HandFactory::Build(int id, const Cards& cards, const ValidatedHand& validatedHand) noexcept
{
    return router[validatedHand.rank](id, cards, validatedHand.cards);
}
