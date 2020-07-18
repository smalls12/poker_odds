#include "AnalyzeRounds.hpp"

Rounds AnalyzeRounds::Analyze(std::vector<Hands>& roundHands)
{
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

    return winners;
}

Round AnalyzeRounds::Analyze(Hands& roundHand)
{
    // sort first
    std::sort(roundHand.begin(), roundHand.end(), std::greater<Hand>());

    Round round;
    Hands::iterator it = std::adjacent_find(roundHand.begin(), roundHand.end());
    if( it != roundHand.begin() )
    {
        // this means that there was only one winner
        it = roundHand.begin();
        round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::WIN, (*it).rank});
    }
    else
    {
        round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::TIE, (*it++).rank});
        round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::TIE, (*it).rank});
        while(it++ != roundHand.end())
        {
            round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::TIE, (*it).rank});
        }
    }

    while(++it != roundHand.end())
    {
        round.emplace_back(PlayerRound{(*it).id, PlayerRoundOutcome::LOSE, (*it).rank});
    }


    return round;
}