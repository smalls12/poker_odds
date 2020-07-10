#include "HandFactory.hpp"

#include <map>
#include <functional>

std::map<HandRank, std::function<Hand(int id, Cards cards, Cards validated)>> router{
    { HandRank::ROYAL_FLUSH, [](int id, Cards cards, Cards validated){ return RoyalFlushHand(id, cards, validated); } },
    { HandRank::STRAIGHT_FLUSH, [](int id, Cards cards, Cards validated){ return StraightFlushHand(id, cards, validated); } },
    { HandRank::FOUR_OF_A_KIND, [](int id, Cards cards, Cards validated){ return FourOfAKindHand(id, cards, validated); } },
    { HandRank::FULL_HOUSE, [](int id, Cards cards, Cards validated){ return FullHouseHand(id, cards, validated); } },
    { HandRank::FLUSH, [](int id, Cards cards, Cards validated){ return FlushHand(id, cards, validated); } },
    { HandRank::STRAIGHT, [](int id, Cards cards, Cards validated){ return StraightHand(id, cards, validated); } },
    { HandRank::THREE_OF_A_KIND, [](int id, Cards cards, Cards validated){ return ThreeOfAKindHand(id, cards, validated); } },
    { HandRank::TWO_PAIR, [](int id, Cards cards, Cards validated){ return TwoPairHand(id, cards, validated); } },
    { HandRank::ONE_PAIR, [](int id, Cards cards, Cards validated){ return OnePairHand(id, cards, validated); } },
    { HandRank::HIGH_CARD, [](int id, Cards cards, Cards validated){ return HighCardHand(id, cards, validated); } },
};

Hand HandFactory::Build(int id, Cards cards, ValidatedHand validatedHand)
{
    return router[validatedHand.rank](id, cards, validatedHand.cards);
}
