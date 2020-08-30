#pragma once

#include "ExplicitHand.hpp"

class FlushHand : public ExplicitHand
{
    public:
        FlushHand(Player& player);
        ~FlushHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};