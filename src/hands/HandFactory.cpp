#include "HandFactory.hpp"

#include <map>
#include <functional>

// would benefit from a memory pool

std::map<HandRank, std::function<Hand*(int id, const Cards& cards)>> router{
    { HandRank::ROYAL_FLUSH, [](int id, const Cards& cards){ return new RoyalFlushHand(id, cards); } },
    { HandRank::STRAIGHT_FLUSH, [](int id, const Cards& cards){ return new StraightFlushHand(id, cards); } },
    { HandRank::STRAIGHT_FLUSH_ACE_LOW, [](int id, const Cards& cards){ return new StraightFlushAceLowHand(id, cards); } },
    { HandRank::FOUR_OF_A_KIND, [](int id, const Cards& cards){ return new FourOfAKindHand(id, cards); } },
    { HandRank::FULL_HOUSE, [](int id, const Cards& cards){ return new FullHouseHand(id, cards); } },
    { HandRank::FLUSH, [](int id, const Cards& cards){ return new FlushHand(id, cards); } },
    { HandRank::STRAIGHT, [](int id, const Cards& cards){ return new StraightHand(id, cards); } },
    { HandRank::STRAIGHT_ACE_LOW, [](int id, const Cards& cards){ return new StraightAceLowHand(id, cards); } },
    { HandRank::THREE_OF_A_KIND, [](int id, const Cards& cards){ return new ThreeOfAKindHand(id, cards); } },
    { HandRank::TWO_PAIR, [](int id, const Cards& cards){ return new TwoPairHand(id, cards); } },
    { HandRank::ONE_PAIR, [](int id, const Cards& cards){ return new OnePairHand(id, cards); } },
    { HandRank::HIGH_CARD, [](int id, const Cards& cards){ return new HighCardHand(id, cards); } },
};

Hand* HandFactory::Build(int id, HandRank handRank) noexcept
{
    return new BaseHand(id, handRank);
}

Hand* HandFactory::Build(int id, const Cards& cards, HandRank handRank) noexcept
{
    return router[handRank](id, cards);
}
