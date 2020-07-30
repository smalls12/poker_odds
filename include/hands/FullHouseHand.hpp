#pragma once

#include "ExplicitHand.hpp"

class FullHouseHand : public ExplicitHand
{
    public:
        FullHouseHand(Player* player, const Cards& cards);
        ~FullHouseHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};