#pragma once

#include "ExplicitHand.hpp"

class FourOfAKindHand : public ExplicitHand
{
    public:
        FourOfAKindHand(int id, const Cards& cards);
        ~FourOfAKindHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};