#pragma once

#include "BaseHand.hpp"

class StraightHand : public BaseHand
{
    public:
        StraightHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~StraightHand() = default;        
};