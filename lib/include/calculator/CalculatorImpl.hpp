#pragma once

#include "Deck.hpp"
#include "Players.hpp"

class CalculatorImpl
{
    public:
        CalculatorImpl();
        ~CalculatorImpl();

        void Initialize(unsigned int numberOfPlayers);
        void NextState();

        friend std::ostream& operator<<(std::ostream & os, const CalculatorImpl& impl);

    private:
        template<size_t N>
        void CalculateOdds(const CardBuffer<N>& communityCards) noexcept;

        Deck                m_deck;
        Players             m_players;

        CardBuffer<3>       mCommunityCardsFlop;
        CardBuffer<4>       mCommunityCardsTurn;
        CardBuffer<5>       mCommunityCardsRiver;

};