#pragma once

#include "Deck.hpp"
#include "Players.hpp"
#include "GamePlayState.hpp"

#include <map>
#include <functional>

class PokerImpl
{
    public:
        PokerImpl();
        ~PokerImpl();

        void Initialize(unsigned int numberOfPlayers);
        void NextState();

        friend std::ostream& operator<<(std::ostream & os, const PokerImpl& impl);

    private:
        void DealCardsToPlayers();
        void DealCommunityCard(Card** card);

        template<size_t N>
        void CalculateOdds(const CardBuffer<N>& communityCards) noexcept;

        template<size_t N>
        void PrintCommunityCards(const CardBuffer<N>& communityCards) const noexcept;

        Deck                m_deck;
        Players             m_players;

        CardBuffer<3>       mCommunityCardsFlop;
        CardBuffer<4>       mCommunityCardsTurn;
        CardBuffer<5>       mCommunityCardsRiver;

        GamePlayState       m_gamePlayState;

        std::map<GamePlayState, std::function<void()>> mNextGameState;
        
};