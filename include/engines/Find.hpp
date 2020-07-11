#pragma once

#include "HandRank.hpp"
#include "Card.hpp"

#include <vector>

struct ValidatedHand
{
    HandRank rank;
    Cards cards;
};