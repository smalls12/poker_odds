#pragma once

#include "BaseHand.hpp"

class StraightHand : public BaseHand
{
    public:
        StraightHand(int id, const Cards& hand);
        ~StraightHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};