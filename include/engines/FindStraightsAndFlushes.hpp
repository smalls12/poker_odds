#pragma once

#include "Find.hpp"
#include "Card.hpp"

#include <vector>
#include <optional>

class FindStraightsAndFlushes
{
    public:
        static std::optional<ValidatedHand> Find(Cards& cards);

};