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

        friend std::ostream& operator<<(std::ostream & os, const Poker& poker);
    
    private:
        std::unique_ptr<PokerImpl>    m_pokerImpl;
        
};