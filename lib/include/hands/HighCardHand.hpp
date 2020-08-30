#pragma once

#include "ExplicitHand.hpp"

class HighCardHand : public ExplicitHand
{
    public:
        HighCardHand(Player& player);
        ~HighCardHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};