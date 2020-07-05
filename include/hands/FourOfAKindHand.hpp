#pragma once

#include "BaseHand.hpp"

class FourOfAKindHand : public BaseHand
{
    public:
        FourOfAKindHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~FourOfAKindHand() = default;        
};