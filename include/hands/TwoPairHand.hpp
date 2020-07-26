#pragma once

#include "BaseHand.hpp"

class TwoPairHand : public BaseHand
{
    public:
        TwoPairHand(int id, const Cards& hand);
        ~TwoPairHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};