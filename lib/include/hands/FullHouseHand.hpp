#pragma once

#include "ExplicitHand.hpp"

class FullHouseHand : public ExplicitHand
{
    public:
        FullHouseHand(Player& player);
        ~FullHouseHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};