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

        int                     m_id;

        CardBuffer<2>           m_hand;
        CardBuffer<7>           m_buffer;

};