#pragma once

#include "Card.hpp"
#include "Hand.hpp"
#include "Players.hpp"
#include "Deck.hpp"

class PossibleHands
{
    public:
        // copy the hand
        // copy the deck
        static Hands SummarizeAllPossibleHands(int id, Cards& cards, std::vector<Cards>& dealerPermutations);
        static Hands SummarizeRoundHands(const Players& players, const Cards& cards) noexcept;
};