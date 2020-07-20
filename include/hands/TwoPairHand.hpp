#pragma once

#include "BaseHand.hpp"

class TwoPairHand : public BaseHand
{
    public:
        TwoPairHand(int id, const Cards& hand, const Cards& validated);
        ~TwoPairHand() = default;

        bool operator<(const TwoPairHand& rhs) const noexcept;
        bool operator>(const TwoPairHand& rhs) const noexcept;

        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;
};