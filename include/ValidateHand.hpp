#pragma once

#include "Find.hpp"
#include "Card.hpp"
#include "HandRank.hpp"

#include <optional>
#include <vector>

class ValidateHand
{
    public:
        static ValidatedHand DetermineHandRank(Cards& cards);
};