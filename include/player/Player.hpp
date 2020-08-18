#pragma once

#include "Card.hpp"

class BaseHand;
class ExplicitHand;

class Player
{
    public:
        Player(int id);
        ~Player();

        void AddCardToHand(Card* card, unsigned short location);

        friend class Dealer;
        friend class CalculateOdds;
        friend class PossibleHands;
        friend class AnalyzeRounds;
        friend class ExplicitHand;

        friend std::ostream& operator<<(std::ostream & os, const Player& player);
        // friend std::ostream& operator<<(std::ostream & os, const BaseHand& hand);
        // friend std::ostream& operator<<(std::ostream & os, const ExplicitHand& hand);

        int                     m_id;               // player id
        // Cards                   m_hand;             // initial 2 cards dealt to player

        CardBuffer<2>           m_hand;
        CardBuffer<7>           m_buffer;

};