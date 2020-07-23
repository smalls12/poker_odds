#pragma once

#include "BaseHand.hpp"

class StraightFlushHand : public BaseHand
{
    public:
        StraightFlushHand(int id, const Cards& hand, const Cards& validated);
        ~StraightFlushHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};