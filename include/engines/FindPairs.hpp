#pragma once

#include "Find.hpp"
#include "Card.hpp"

#include <vector>
#include <optional>

class FindPairs
{
    public:
        static std::optional<ValidatedHand> Find(std::vector<Card> cards);

};