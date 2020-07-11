#include "AnalyzeRounds.hpp"

#include "spdlog/spdlog.h"

Rounds AnalyzeRounds::Analyze(std::vector<Hands>& roundHands)
{
    spdlog::get("console")->info("AnalyzeRounds::Analyze - start");

    Rounds winners;
    winners.reserve(roundHands.size());
    for(auto& handsForComparison : roundHands)
    {
        // sort first
        std::sort(handsForComparison.begin(), handsForComparison.end(), std::greater<Hand>());

        Round round;
        Hands::iterator it = std::adjacent_find(handsForComparison.begin(), handsForComparison.end());
        if( it != handsForComparison.begin() )
        {
            // this means that there was only one winner
            it = handsForComparison.begin();
            round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::WIN, (*it).rank});
        }
        else
        {
            round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::TIE, (*it++).rank});
            round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::TIE, (*it).rank});
            while(it++ != handsForComparison.end())
            {
                round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::TIE, (*it).rank});
            }
        }

        while(++it != handsForComparison.end())
        {
            round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::LOSE, (*it).rank});
        }


        winners.emplace_back(round);
    }

    spdlog::get("console")->info("AnalyzeRounds::Analyze - start");

    return winners;
}
