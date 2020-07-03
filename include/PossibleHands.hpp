#pragma once

#include "Hand.hpp"
#include "Player.hpp"
#include "Deck.hpp"

class PossibleHands
{
    public:
        // copy the hand
        // copy the deck
        static std::vector<Hand> SummarizeAllPossibleHands(Hand hand, Deck deck);
};