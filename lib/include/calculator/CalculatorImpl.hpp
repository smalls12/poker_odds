#pragma once

#include "Deck.hpp"
#include "Players.hpp"

class CalculatorImpl
{
    public:
        CalculatorImpl();
        ~CalculatorImpl();

        void Initialize(const std::vector<Player>& players);
        
        template<size_t N>
        void CalculateOdds(const CardBuffer<N>& communityCards) noexcept;

        friend std::ostream& operator<<(std::ostream & os, const CalculatorImpl& impl);

    private:
        Deck                m_deck;
        Players             m_players;

};