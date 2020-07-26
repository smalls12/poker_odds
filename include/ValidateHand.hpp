#pragma once

#include "Find.hpp"
#include "Card.hpp"
#include "HandRank.hpp"

#include <optional>
#include <vector>

class ValidateHand
{
    public:
        static HandRank DetermineHandRank(const Cards& cards) noexcept;
        static ValidatedHand DetermineHandRankWithValidatedCards(const Cards& cards) noexcept;
};