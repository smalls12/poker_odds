#pragma once

#include <memory>

class PokerImpl;

class Poker
{
    public:
        Poker();
        ~Poker();

        void Initialize(unsigned int numberOfPlayers);
        void NextState();
    
    private:
        std::unique_ptr<PokerImpl>    m_pokerImpl;
        
};