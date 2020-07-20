#pragma once

#include "Hand.hpp"
#include "Cards.hpp"
#include "Find.hpp"

class HandFactory
{
    public:
        static Hand Build(int id, const Cards& cards, const ValidatedHand& validatedHand) noexcept;
};