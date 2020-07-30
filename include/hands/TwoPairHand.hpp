#pragma once

#include "ExplicitHand.hpp"

class TwoPairHand : public ExplicitHand
{
    public:
        TwoPairHand(Player* player, const Cards& cards);
        ~TwoPairHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};