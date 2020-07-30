#pragma once

#include "ExplicitHand.hpp"

class OnePairHand : public ExplicitHand
{
    public:
        OnePairHand(Player* player, const Cards& cards);
        ~OnePairHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};