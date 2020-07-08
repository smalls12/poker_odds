#pragma once

#include "BaseHand.hpp"

class HighCardHand : public BaseHand
{
    public:
        HighCardHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~HighCardHand() = default;

        bool operator<(const HighCardHand& rhs);
        bool operator>(const HighCardHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};