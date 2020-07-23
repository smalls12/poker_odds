#pragma once

#include "BaseHand.hpp"

class StraightAceLowHand : public BaseHand
{
    public:
        StraightAceLowHand(int id, const Cards& hand, const Cards& validated);
        ~StraightAceLowHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};