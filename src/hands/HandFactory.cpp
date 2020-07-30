#include "HandFactory.hpp"

#include <map>
#include <functional>

// would benefit from a memory pool

std::map<HandRank, std::function<Hand*(Player* player, const Cards& cards)>> router{
    { HandRank::ROYAL_FLUSH, [](Player* player, const Cards& cards){ return new RoyalFlushHand(player, cards); } },
    { HandRank::STRAIGHT_FLUSH, [](Player* player, const Cards& cards){ return new StraightFlushHand(player, cards); } },
    { HandRank::STRAIGHT_FLUSH_ACE_LOW, [](Player* player, const Cards& cards){ return new StraightFlushAceLowHand(player, cards); } },
    { HandRank::FOUR_OF_A_KIND, [](Player* player, const Cards& cards){ return new FourOfAKindHand(player, cards); } },
    { HandRank::FULL_HOUSE, [](Player* player, const Cards& cards){ return new FullHouseHand(player, cards); } },
    { HandRank::FLUSH, [](Player* player, const Cards& cards){ return new FlushHand(player, cards); } },
    { HandRank::STRAIGHT, [](Player* player, const Cards& cards){ return new StraightHand(player, cards); } },
    { HandRank::STRAIGHT_ACE_LOW, [](Player* player, const Cards& cards){ return new StraightAceLowHand(player, cards); } },
    { HandRank::THREE_OF_A_KIND, [](Player* player, const Cards& cards){ return new ThreeOfAKindHand(player, cards); } },
    { HandRank::TWO_PAIR, [](Player* player, const Cards& cards){ return new TwoPairHand(player, cards); } },
    { HandRank::ONE_PAIR, [](Player* player, const Cards& cards){ return new OnePairHand(player, cards); } },
    { HandRank::HIGH_CARD, [](Player* player, const Cards& cards){ return new HighCardHand(player, cards); } },
};

Hand* HandFactory::Build(Player* player, HandRank handRank) noexcept
{
    return new BaseHand(player, handRank);
}

Hand* HandFactory::Build(Player* player, const Cards& cards, HandRank handRank) noexcept
{
    return router[handRank](player, cards);
}
