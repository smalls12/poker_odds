#pragma once

#include "Card.hpp"
#include "HandRank.hpp"

#include <vector>

class ValidateHand
{
    public:
        static HandRank DetermineHandRank(std::vector<Card>& cards);
};