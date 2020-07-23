#include "AnalyzeRounds.hpp"

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
                round.emplace_back(PlayerRound{roundHand[x]->id, PlayerRoundOutcome::TIE, roundHand[x]->rank});
            }
            else
            {
                round.emplace_back(PlayerRound{roundHand[x]->id, PlayerRoundOutcome::LOSE, roundHand[x]->rank});
            }
        }
    }
    else
    {
        round.emplace_back(PlayerRound{roundHand[0]->id, PlayerRoundOutcome::WIN, roundHand[0]->rank});
        for( size_t x = 1; x < roundHand.size(); x++ )
        {
            round.emplace_back(PlayerRound{roundHand[x]->id, PlayerRoundOutcome::LOSE, roundHand[x]->rank});
        }
    }

    return round;
}