#pragma once

#include "BaseHand.hpp"

class StraightHand : public BaseHand
{
    public:
        StraightHand(int id, const Cards& hand, const Cards& validated);
        ~StraightHand() = default;

        bool operator<(const StraightHand& rhs) const noexcept;
        bool operator>(const StraightHand& rhs) const noexcept;

        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;
};