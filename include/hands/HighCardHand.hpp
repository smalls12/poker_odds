#pragma once

#include "Hand.hpp"

class HighCardHand : public Hand
{
    public:
        HighCardHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~HighCardHand() = default;
    
    private:
        HandRank rank;
        std::vector<Card> validated;
};