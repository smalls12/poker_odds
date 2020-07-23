#pragma once

#include "Deck.hpp"
#include "Players.hpp"
#include "GamePlayState.hpp"

class PokerImpl
{
    public:
        PokerImpl();
        ~PokerImpl();

        void Initialize(unsigned int numberOfPlayers);
        void NextState();

    private:
        void DealCard();
        void CalculateOdds();

        Deck                m_deck;
        Players             m_players;

        GamePlayState       m_gamePlayState;
        
};