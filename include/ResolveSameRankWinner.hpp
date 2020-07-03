#pragma once

#include "HandRank.hpp"
#include "Card.hpp"
#include "ResolveSameRankWinner.hpp"

#include <vector>

class ResolveSameRankWinner
{
    public:
        static void Resolve(HandRank rank, std::vector<Card> cards_one, std::vector<Card> cards_two);
};