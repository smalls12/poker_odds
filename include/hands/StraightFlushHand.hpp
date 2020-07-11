#pragma once

#include "BaseHand.hpp"

class StraightFlushHand : public BaseHand
{
    public:
        StraightFlushHand(int id, Cards hand, Cards validated);
        ~StraightFlushHand() = default;

        bool operator<(const StraightFlushHand& rhs);
        bool operator>(const StraightFlushHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};