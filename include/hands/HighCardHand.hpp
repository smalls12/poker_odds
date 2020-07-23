#pragma once

#include "BaseHand.hpp"

class HighCardHand : public BaseHand
{
    public:
        HighCardHand(int id, const Cards& hand, const Cards& validated);
        ~HighCardHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};