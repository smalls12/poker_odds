#pragma once

#include "Card.hpp"
#include "Deck.hpp"

#include <vector>

class DealerPermutations
{
    public:
        static std::vector<Cards> Simulate(Deck &deck, int cardsToDraw);
        static std::vector<Cards> Work(Deck &deck, int cardsToDraw);
    

};