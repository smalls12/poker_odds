#pragma once

#include "Find.hpp"
#include "Card.hpp"

#include <vector>
#include <optional>

class FindHighCard
{
    public:
        static std::optional<ValidatedHand> Find(Cards& cards);

};