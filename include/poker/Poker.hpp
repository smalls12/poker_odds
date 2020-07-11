#pragma once

#include <memory>

class PokerImpl;

class Poker
{
    public:
        Poker();
        ~Poker();

        void Initialize(unsigned int numberOfPlayers);
        void DealCard();
        void CalculateOdds();
    
    private:
        std::unique_ptr<PokerImpl>    m_pokerImpl;
        
};