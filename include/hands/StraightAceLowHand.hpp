#pragma once

#include "BaseHand.hpp"

class StraightAceLowHand : public BaseHand
{
    public:
        StraightAceLowHand(int id, Cards hand, Cards validated);
        ~StraightAceLowHand() = default;

        bool operator<(const StraightAceLowHand& rhs);
        bool operator>(const StraightAceLowHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};