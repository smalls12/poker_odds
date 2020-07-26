#pragma once

#include "Find.hpp"
#include "Card.hpp"

#include <vector>
#include <optional>

class FindStraightsAndFlushes
{
    public:
        static std::optional<HandRank> FindRank(const Cards& cards) noexcept;
        static std::optional<ValidatedHand> FindRankWithValidatedCards(const Cards& cards) noexcept;

};