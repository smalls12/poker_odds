#pragma once

#include "HandRank.hpp"
#include "Card.hpp"

#include <vector>
#include <optional>

class FindPairs
{
    public:
        static std::optional<HandRank> Find(std::vector<Card> cards);

};