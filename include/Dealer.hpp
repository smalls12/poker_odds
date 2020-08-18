#pragma once

#include "Players.hpp"
#include "Deck.hpp"

#include <memory>

class Dealer
{
    public:
        inline static void DealCards(Card** card, Deck& deck)
        {
            *card = deck.back();            
            deck.pop_back();
        }
};