#pragma once

#include "Players.hpp"
#include "Deck.hpp"

#include <memory>

class Dealer
{
    public:
        static void DealCards(Players& players, Deck& deck);
};