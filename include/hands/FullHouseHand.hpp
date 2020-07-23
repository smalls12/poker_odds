#pragma once

#include "BaseHand.hpp"

class FullHouseHand : public BaseHand
{
    public:
        FullHouseHand(int id, const Cards& hand, const Cards& validated);
        ~FullHouseHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};