#pragma once

#include "BaseHand.hpp"

class FourOfAKindHand : public BaseHand
{
    public:
        FourOfAKindHand(int id, const Cards& hand);
        ~FourOfAKindHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};