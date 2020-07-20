#pragma once

#include "BaseHand.hpp"

class HighCardHand : public BaseHand
{
    public:
        HighCardHand(int id, const Cards& hand, const Cards& validated);
        ~HighCardHand() = default;

        bool operator<(const HighCardHand& rhs) const noexcept;
        bool operator>(const HighCardHand& rhs) const noexcept;

        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;
};