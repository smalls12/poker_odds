#pragma once

#include "BaseHand.hpp"

class RoyalFlushHand : public BaseHand
{
    public:
        RoyalFlushHand(int id, const Cards& hand);
        ~RoyalFlushHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};