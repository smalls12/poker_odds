#pragma once

#include "ExplicitHand.hpp"

class StraightAceLowHand : public ExplicitHand
{
    public:
        StraightAceLowHand(Player& player);
        ~StraightAceLowHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};