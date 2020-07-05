#include "ResolveSameRankWinner.hpp"

#include <map>
#include <functional>
#include <iostream>

RankEquality ResolveSameRankWinner::Resolve(Hand hand1, Hand hand2)
{    
    std::map<HandRank, std::function<RankEquality(Hand, Hand)>> router{
        { HandRank::ROYAL_FLUSH, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } },
        { HandRank::STRAIGHT_FLUSH, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } },
        { HandRank::FOUR_OF_A_KIND, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } },
        { HandRank::FULL_HOUSE, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } },
        { HandRank::FLUSH, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } },
        { HandRank::STRAIGHT, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } },
        { HandRank::THREE_OF_A_KIND, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } },
        { HandRank::TWO_PAIR, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } },
        { HandRank::ONE_PAIR, [](Hand hand1, Hand hand2) { return ResolveOnePair(hand1, hand2); } },
        { HandRank::HIGH_CARD, [](Hand hand1, Hand hand2){ (void)hand1; (void)hand2; return RankEquality::EQUAL; } }
    };

    return router[hand1.rank](hand1, hand2);
}

RankEquality ResolveSameRankWinner::ResolveOnePair(Hand hand1, Hand hand2)
{
    if(hand1.cards == hand2.cards)
    {
        return RankEquality::EQUAL;
    }

    // copy the full hand
    std::vector<Card> hand1_cards{hand1.cards};
    std::vector<Card> hand2_cards{hand2.cards};

    // remove respective one pair cards
    for(auto& card : hand1.validated)
    {
        hand1_cards.erase(std::remove(hand1_cards.begin(), hand1_cards.end(), card), hand1_cards.end());
    }

    // remove respective one pair cards
    for(auto& card : hand2.validated)
    {
        hand2_cards.erase(std::remove(hand2_cards.begin(), hand2_cards.end(), card), hand2_cards.end());
    }

    return hand1_cards > hand2_cards ? RankEquality::GREATER_THAN : RankEquality::LESSER_THAN;

}
