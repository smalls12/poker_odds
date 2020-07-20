#pragma once

#include "BaseHand.hpp"

class StraightFlushAceLowHand : public BaseHand
{
    public:
        StraightFlushAceLowHand(int id, const Cards& hand, const Cards& validated);
        ~StraightFlushAceLowHand() = default;

        bool operator<(const StraightFlushAceLowHand& rhs) const noexcept;
        bool operator>(const StraightFlushAceLowHand& rhs) const noexcept;

        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;
};