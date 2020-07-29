#pragma once

#include "Card.hpp"
#include "Hand.hpp"
#include "Buffer.hpp"

class Player
{
    public:
        Player(int id);
        ~Player() = default;

        void setCardPermutationsHandRankOnlyBufferLocation(Hand** bufferLocation);
        void setCardPermutationsHandBufferLocation(Hand** bufferLocation);

        void AddCardToHand(Card* card);

        friend class Dealer;
        friend class CalculateOdds;
        friend class PossibleHands;

        friend std::ostream& operator<<(std::ostream & os, Player& player);

    private:
        int                     m_id;               // player id
        Cards                   m_hand;             // initial 2 cards dealt to player

        Cards                   m_cardPermutationsBuffer;           // stores the cards in a possible hand

        CardBuffer<7>           m_buffer;
        Hand**                  m_cardPermutationsHandRankOnlyBufferLocation;   // rank of the m_cardPermutationsBuffer

        Hand**                  m_cardPermutationsHandBufferLocation;       // fully qualified hand from m_cardPermutationsBuffer

        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
};