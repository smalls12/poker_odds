#pragma once

#include "BaseHand.hpp"

class OnePairHand : public BaseHand
{
    public:
        OnePairHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~OnePairHand() = default;        
};