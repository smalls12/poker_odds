#pragma once

#include "BaseHand.hpp"

class StraightFlushAceLowHand : public BaseHand
{
    public:
        StraightFlushAceLowHand(int id, Cards hand, Cards validated);
        ~StraightFlushAceLowHand() = default;

        bool operator<(const StraightFlushAceLowHand& rhs);
        bool operator>(const StraightFlushAceLowHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};