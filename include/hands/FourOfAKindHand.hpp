#pragma once

#include "ExplicitHand.hpp"

class FourOfAKindHand : public ExplicitHand
{
    public:
        FourOfAKindHand(Player* player, const Cards& cards);
        ~FourOfAKindHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};