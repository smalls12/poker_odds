#pragma once

#include "Find.hpp"
#include "Cards.hpp"

#include <vector>
#include <optional>

class FindHighCard
{
    public:
        static std::optional<ValidatedHand> Find(Cards& cards);

};