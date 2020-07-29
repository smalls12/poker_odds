#pragma once

#include "Find.hpp"

#include <optional>

class FindAllPairs
{
    public:
        // template<class T>
        // static std::optional<HandRank> FindRank(const T& cards) noexcept;
        static std::optional<HandRank> FindRank(const std::array<Card*, 7>& cards) noexcept;
        static std::optional<HandRank> FindRank(const Cards& cards) noexcept;
        static std::optional<ValidatedHand> FindRankWithValidatedCards(const Cards& cards) noexcept;
};