#pragma once

#include "ExplicitHand.hpp"

class StraightHand : public ExplicitHand
{
    public:
        StraightHand(Player* player);
        ~StraightHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};