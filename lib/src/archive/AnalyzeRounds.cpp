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

// static std::map<PlayerRoundOutcome, std::function<void(int id, PlayerStatistics& playerStatistics)>> router{
//         { PlayerRoundOutcome::WIN, [](int id, PlayerStatistics& playerStatistics){ playerStatistics[id].wins++; } },
//         { PlayerRoundOutcome::TIE, [](int id, PlayerStatistics& playerStatistics){ playerStatistics[id].ties++; } },
//         { PlayerRoundOutcome::LOSE, [](int id, PlayerStatistics& playerStatistics){ playerStatistics[id].losses++; } },
//     };

// template<size_t N>
// void AnalyzeRounds::Analyze(const HandBuffer<N>& hands, PlayerStatistics& playerStatistics) noexcept
// {
//     if( hands[0] == hands[1] )
//     {
//         // we have a tie
//         for( size_t x = 0; x < hands.size(); x++ )
//         {
//             if( hands[x] == hands[0] )
//             {
//                 // round.emplace_back(PlayerRound{hands[x]->id, PlayerRoundOutcome::TIE, hands[x]->rank});
//                 router[PlayerRoundOutcome::TIE](hands[x]->id, playerStatistics);
//             }
//             else
//             {
//                 // round.emplace_back(PlayerRound{hands[x]->id, PlayerRoundOutcome::LOSE, hands[x]->rank});
//                 router[PlayerRoundOutcome::LOSE](hands[x]->id, playerStatistics);
//             }
//         }
//     }
//     else
//     {
//         // round.emplace_back(PlayerRound{hands[0]->id, PlayerRoundOutcome::WIN, hands[0]->rank});
//         router[PlayerRoundOutcome::WIN](hands[0]->id, playerStatistics);
//         for( size_t x = 1; x < hands.size(); x++ )
//         {
//             // round.emplace_back(PlayerRound{hands[x]->id, PlayerRoundOutcome::LOSE, hands[x]->rank});
//             router[PlayerRoundOutcome::LOSE](hands[x]->id, playerStatistics);
//         }
//     }
// }