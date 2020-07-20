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

Round AnalyzeRounds::Analyze(const Hands& roundHand) noexcept
{
    Round round;

    if( roundHand[0] == roundHand[1] )
    {
        // we have a tie
        for( size_t x = 0; x < roundHand.size(); x++ )
        {
            if( roundHand[x] == roundHand[0] )
            {
                round.emplace_back(PlayerRound{roundHand[x].id, PlayerRoundOutcome::TIE, roundHand[x].rank});
            }
            else
            {
                round.emplace_back(PlayerRound{roundHand[x].id, PlayerRoundOutcome::LOSE, roundHand[x].rank});
            }
        }
    }
    else
    {
        round.emplace_back(PlayerRound{roundHand[0].id, PlayerRoundOutcome::WIN, roundHand[0].rank});
        for( size_t x = 1; x < roundHand.size(); x++ )
        {
            round.emplace_back(PlayerRound{roundHand[x].id, PlayerRoundOutcome::LOSE, roundHand[x].rank});
        }
    }

    return round;
}