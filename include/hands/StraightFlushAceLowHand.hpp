#pragma once

#include "ExplicitHand.hpp"

class StraightFlushAceLowHand : public ExplicitHand
{
    public:
        StraightFlushAceLowHand(Player* player, const Cards& cards);
        ~StraightFlushAceLowHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};