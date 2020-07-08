#pragma once

#include "Card.hpp"
#include "Deck.hpp"

#include <vector>

class DealerPermutations
{
    public:
        static std::vector<std::vector<Card>> Simulate(Deck &deck, int cardsToDraw);
        static std::vector<std::vector<Card>> Work(Deck &deck, int cardsToDraw);
    

};