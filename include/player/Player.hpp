#pragma once

#include "Card.hpp"

class BaseHand;
class ExplicitHand;

class Player
{
    public:
        Player(int id);
        ~Player() = default;

        void AddCardToHand(Card* card);

        friend class Dealer;
        friend class CalculateOdds;
        friend class PossibleHands;
        friend class AnalyzeRounds;

        friend std::ostream& operator<<(std::ostream & os, Player& player);

        friend std::ostream& operator<<(std::ostream & os, const BaseHand& hand);
        friend std::ostream& operator<<(std::ostream & os, const ExplicitHand& hand);

    private:
        int                     m_id;               // player id
        Cards                   m_hand;             // initial 2 cards dealt to player

        CardBuffer<7>           m_buffer;

        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
};