#pragma once

#include "HandRank.hpp"
#include "Card.hpp"

#include <vector>
#include <optional>

class FindRuns
{
    public:
        static std::optional<HandRank> Find(std::vector<Card> cards);

};