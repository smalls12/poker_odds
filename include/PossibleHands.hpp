#pragma once

#include "Cards.hpp"
#include "Hands.hpp"
#include "Player.hpp"
#include "Deck.hpp"

class PossibleHands
{
    public:
        // copy the hand
        // copy the deck
        static Hands SummarizeAllPossibleHands(int id, Cards cards, std::vector<Cards> dealerPermutations);

};