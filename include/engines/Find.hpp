#pragma once

#include "HandRank.hpp"
#include "Cards.hpp"

#include <vector>

struct ValidatedHand
{
    HandRank rank;
    Cards cards;
};