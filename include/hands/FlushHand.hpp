#pragma once

#include "BaseHand.hpp"

class FlushHand : public BaseHand
{
    public:
        FlushHand(int id, const Cards& hand, const Cards& validated);
        ~FlushHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;
};