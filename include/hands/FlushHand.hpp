#pragma once

#include "ExplicitHand.hpp"

class FlushHand : public ExplicitHand
{
    public:
        FlushHand(Player* player, const Cards& cards);
        ~FlushHand() = default;

        bool operator<(const ExplicitHand& rhs) const noexcept override;
        bool operator>(const ExplicitHand& rhs) const noexcept override;
};