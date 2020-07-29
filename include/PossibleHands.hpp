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
        template<size_t N>
        inline static void Generate(const Players& players, const CardBuffer<N>& cards) noexcept
        {
            // for(const auto& player : players)
            for( unsigned short x = 0; x < players.size(); x++ )
            {
                for( unsigned short y = 0; y < cards.size(); y++)
                {
                    players[x]->m_buffer[y + 2] = cards[y];
                }

                std::sort(std::begin(players[x]->m_buffer), std::end(players[x]->m_buffer),
                [](const Card* const lhs, const Card* const rhs){ return *lhs > *rhs; });

                // validate and find the highest hand ranking
                HandRank handRank = ValidateHand::DetermineHandRank(players[x]->m_buffer);
                
                // *players[x]->m_cardPermutationsHandRankOnlyBufferLocation = new BaseHand(players[x]->m_id, handRank);
                *players[x]->m_cardPermutationsHandRankOnlyBufferLocation = HandPool[x]->Reset(players[x]->m_id, handRank);
            }
        }

};