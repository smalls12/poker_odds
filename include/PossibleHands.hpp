#pragma once

#include "Card.hpp"
#include "Hand.hpp"
#include "Players.hpp"

#include "ValidateHand.hpp"
#include "HandFactory.hpp"

static HandBuffer<4> HandPool{
    new BaseHand(),
    new BaseHand(),
    new BaseHand(),
    new BaseHand()
};

class PossibleHands
{
    public:
        template<size_t M, size_t N>
        inline static void Generate(const Players& players, const CardBuffer<M>& cards, HandBuffer<N>& hands) noexcept
        {
            for( unsigned short x = 0; x < players.size(); x++ )
            {
                players[x]->m_buffer[0] = players[x]->m_hand[0];
                players[x]->m_buffer[1] = players[x]->m_hand[1];

                for( unsigned short y = 0; y < cards.size(); y++)
                {
                    players[x]->m_buffer[y + 2] = cards[y];
                }

                // validate and find the highest hand ranking
                HandRank handRank = ValidateHand::DetermineHandRank(players[x]->m_buffer);

                hands[x] = HandPool[x]->Reset(players[x].get(), handRank);
            }
        }

};