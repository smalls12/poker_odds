#pragma once

#include "ExplicitHand.hpp"

class StraightHand : public ExplicitHand
{
    public:
        StraightHand(Player* player, const Cards& cards);
        ~StraightHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};