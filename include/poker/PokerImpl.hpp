#pragma once

#include "Deck.hpp"
#include "Players.hpp"

class PokerImpl
{
    public:
        PokerImpl();
        ~PokerImpl();

        void Initialize(unsigned int numberOfPlayers);
        void DealCard();
        void CalculateOdds();
    
    private:
        Deck    m_deck;
        Players m_players;
        
};