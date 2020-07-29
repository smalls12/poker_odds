#pragma once

#include "ExplicitHand.hpp"

class ThreeOfAKindHand : public ExplicitHand
{
    public:
        ThreeOfAKindHand(int id, const Cards& cards);
        ~ThreeOfAKindHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};