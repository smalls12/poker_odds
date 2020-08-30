#pragma once

#include "ExplicitHand.hpp"

class OnePairHand : public ExplicitHand
{
    public:
        OnePairHand(Player& player);
        ~OnePairHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};