#pragma once

#include "ExplicitHand.hpp"

class RoyalFlushHand : public ExplicitHand
{
    public:
        RoyalFlushHand(Player* player, const Cards& cards);
        ~RoyalFlushHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};