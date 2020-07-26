#pragma once

#include "Find.hpp"

#include <optional>

class FindAllPairs
{
    public:
        static std::optional<HandRank> FindRank(const Cards& cards) noexcept;
        static std::optional<ValidatedHand> FindRankWithValidatedCards(const Cards& cards) noexcept;
};