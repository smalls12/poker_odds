#pragma once

#include "ExplicitHand.hpp"

class StraightFlushHand : public ExplicitHand
{
    public:
        StraightFlushHand(Player* player);
        ~StraightFlushHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};