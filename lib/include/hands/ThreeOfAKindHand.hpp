#pragma once

#include "ExplicitHand.hpp"

class ThreeOfAKindHand : public ExplicitHand
{
    public:
        ThreeOfAKindHand(Player& player);
        ~ThreeOfAKindHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};