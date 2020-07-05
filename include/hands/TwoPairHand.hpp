#pragma once

#include "BaseHand.hpp"

class TwoPairHand : public BaseHand
{
    public:
        TwoPairHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~TwoPairHand() = default;        
};