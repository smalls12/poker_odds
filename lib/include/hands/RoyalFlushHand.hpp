#pragma once

#include "ExplicitHand.hpp"

class RoyalFlushHand : public ExplicitHand
{
    public:
        RoyalFlushHand(Player& player);
        ~RoyalFlushHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};