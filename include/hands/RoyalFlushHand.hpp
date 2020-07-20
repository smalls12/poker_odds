#pragma once

#include "BaseHand.hpp"

class RoyalFlushHand : public BaseHand
{
    public:
        RoyalFlushHand(int id, const Cards& hand, const Cards& validated);
        ~RoyalFlushHand() = default;

        bool operator<(const RoyalFlushHand& rhs) const noexcept;
        bool operator>(const RoyalFlushHand& rhs) const noexcept;

        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;
};