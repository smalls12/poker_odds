#pragma once

#include "BaseHand.hpp"

class ThreeOfAKindHand : public BaseHand
{
    public:
        ThreeOfAKindHand(int id, const Cards& hand, const Cards& validated);
        ~ThreeOfAKindHand() = default;

        bool operator<(const ThreeOfAKindHand& rhs) const noexcept;
        bool operator>(const ThreeOfAKindHand& rhs) const noexcept;

        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;
};