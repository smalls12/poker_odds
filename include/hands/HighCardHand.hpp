#pragma once

#include "ExplicitHand.hpp"

class HighCardHand : public ExplicitHand
{
    public:
        HighCardHand(Player* player, const Cards& cards);
        ~HighCardHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept;
        bool operator>(const ExplicitHand& rhs) const noexcept;
};