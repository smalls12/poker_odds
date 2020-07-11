#pragma once

#include "BaseHand.hpp"

class RoyalFlushHand : public BaseHand
{
    public:
        RoyalFlushHand(int id, Cards hand, Cards validated);
        ~RoyalFlushHand() = default;

        bool operator<(const RoyalFlushHand& rhs);
        bool operator>(const RoyalFlushHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};