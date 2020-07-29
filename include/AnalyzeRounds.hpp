#pragma once

#include "Rounds.hpp"
#include "Hand.hpp"

#include "PlayerStatistics.hpp"

class AnalyzeRounds
{
    public:
        inline static std::map<PlayerRoundOutcome, std::function<void(int id, PlayerStatistics& playerStatistics)>> router{
            { PlayerRoundOutcome::WIN, [](int id, PlayerStatistics& playerStatistics){ playerStatistics[id].wins++; } },
            { PlayerRoundOutcome::TIE, [](int id, PlayerStatistics& playerStatistics){ playerStatistics[id].ties++; } },
            { PlayerRoundOutcome::LOSE, [](int id, PlayerStatistics& playerStatistics){ playerStatistics[id].losses++; } },
        };

        template<size_t N>
        inline static void Analyze(const HandBuffer<N>& hands, PlayerStatistics& playerStatistics) noexcept
        {
            if( hands[0] == hands[1] )
            {
                // we have a tie
                for( size_t x = 0; x < hands.size(); x++ )
                {
                    if( hands[x] == hands[0] )
                    {
                        router[PlayerRoundOutcome::TIE](hands[x]->mId, playerStatistics);
                    }
                    else
                    {
                        router[PlayerRoundOutcome::LOSE](hands[x]->mId, playerStatistics);
                    }
                }
            }
            else
            {
                router[PlayerRoundOutcome::WIN](hands[0]->mId, playerStatistics);
                for( size_t x = 1; x < hands.size(); x++ )
                {
                    router[PlayerRoundOutcome::LOSE](hands[x]->mId, playerStatistics);
                }
            }
        }

};