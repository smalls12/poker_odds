#pragma once

#include "Hand.hpp"
#include "Cards.hpp"
#include "Find.hpp"

class HandFactory
{
    public:
        static Hand* Build(Player* player, HandRank handRank) noexcept;
        static Hand* Build(Player* player, const Cards& cards, HandRank handRank) noexcept;
};