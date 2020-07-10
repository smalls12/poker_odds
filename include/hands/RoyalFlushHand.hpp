#pragma once

#include "BaseHand.hpp"

class RoyalFlushHand : public BaseHand
{
    public:
        RoyalFlushHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~RoyalFlushHand() = default;

        bool operator<(const RoyalFlushHand& rhs);
        bool operator>(const RoyalFlushHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};