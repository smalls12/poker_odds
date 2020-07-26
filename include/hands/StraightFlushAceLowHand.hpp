#pragma once

#include "BaseHand.hpp"

class StraightFlushAceLowHand : public BaseHand
{
    public:
        StraightFlushAceLowHand(int id, const Cards& hand);
        ~StraightFlushAceLowHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};