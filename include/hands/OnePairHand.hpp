#pragma once

#include "BaseHand.hpp"

class OnePairHand : public BaseHand
{
    public:
        OnePairHand(int id, const Cards& hand, const Cards& validated);
        ~OnePairHand() = default;

        bool operator<(const OnePairHand& rhs) const noexcept;
        bool operator>(const OnePairHand& rhs) const noexcept;

        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;
};