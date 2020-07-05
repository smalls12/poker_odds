#pragma once

#include "BaseHand.hpp"

class ThreeOfAKindHand : public BaseHand
{
    public:
        ThreeOfAKindHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~ThreeOfAKindHand() = default;        
};