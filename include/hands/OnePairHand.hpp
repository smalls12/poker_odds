#pragma once

#include "BaseHand.hpp"

class OnePairHand : public BaseHand
{
    public:
        OnePairHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~OnePairHand() = default;

        bool operator<(const OnePairHand& rhs);
        bool operator>(const OnePairHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};