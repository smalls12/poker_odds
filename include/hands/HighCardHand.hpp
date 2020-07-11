#pragma once

#include "BaseHand.hpp"

class HighCardHand : public BaseHand
{
    public:
        HighCardHand(int id, Cards hand, Cards validated);
        ~HighCardHand() = default;

        bool operator<(const HighCardHand& rhs);
        bool operator>(const HighCardHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};