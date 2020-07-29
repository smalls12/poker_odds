#pragma once

#include "Hand.hpp"
#include "Cards.hpp"
#include "Find.hpp"

class HandFactory
{
    public:
        static Hand* Build(int id, HandRank handRank) noexcept;
        static Hand* Build(int id, const Cards& cards, HandRank handRank) noexcept;
};