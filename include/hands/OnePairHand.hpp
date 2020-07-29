#pragma once

#include "ExplicitHand.hpp"

class OnePairHand : public ExplicitHand
{
    public:
        OnePairHand(int id, const Cards& cards);
        ~OnePairHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};