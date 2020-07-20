#pragma once

#include "BaseHand.hpp"

class FourOfAKindHand : public BaseHand
{
    public:
        FourOfAKindHand(int id, const Cards& hand, const Cards& validated);
        ~FourOfAKindHand() = default;

        bool operator<(const FourOfAKindHand& rhs) const noexcept;
        bool operator>(const FourOfAKindHand& rhs) const noexcept;

        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;
};