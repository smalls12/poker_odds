#pragma once

#include "Players.hpp"
#include "GamePlayState.hpp"
#include "Deck.hpp"

#include "Cards.hpp"
#include "Hand.hpp"

#include "PossibleHands.hpp"
#include "AnalyzeRounds.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>      // std::setprecision

class CalculateOdds
{
    public:
        template<size_t N>
        inline static void Calculate(Players& players, const CardBuffer<N>& communityCards, Deck& deck) noexcept
        {
            HandBuffer<4> hands;

            PlayerStatistics playerStatistics;

            for(auto& player : players)
            {
                playerStatistics.insert(std::pair<int, Statistics>(player.m_id, {}));
            }

            std::string bitmask(5-N, 1); // K leading 1's
            bitmask.resize(deck.size(), 0); // N-K trailing 0's

            PossibleHands possibleHands(players);

            CardBuffer<5-N> cards;

            do
            {
                unsigned short index = 0;   
                for (unsigned short i = 0; i < deck.size(); ++i) // [0..N-1] integers
                {
                    if (bitmask[i])
                    {
                        cards[index++] = deck[i];
                    }
                }

                possibleHands.Generate(cards, communityCards, hands);

                // sort first
                std::sort(hands.begin(), hands.end(),
                [](const ExplicitHand* const lhs, const ExplicitHand* const rhs){ return *lhs > *rhs; });

                AnalyzeRounds::Analyze(hands, playerStatistics);
            }
            while (std::prev_permutation(bitmask.begin(), bitmask.end()));

            for (PlayerStatistics::iterator it=playerStatistics.begin(); it!=playerStatistics.end(); ++it)
            {
                size_t total = it->second.wins + it->second.ties + it->second.losses;

                std::cout
                << "Player ID [ " << it->first << " ]"
                << " WINS [ " << it->second.wins << " ( " << std::setprecision(5) << ( 100.0 * it->second.wins / total) << " ) ]"
                << " TIES [ " << it->second.ties << " ( " << std::setprecision(5) << ( 100.0 * it->second.ties / total) << " ) ]"
                << " LOSSES [ " << it->second.losses << " ( " << std::setprecision(5) << ( 100.0 * it->second.losses / total) << " ) ]"
                << std::endl;

            }
        }
};