#include "CalculateOdds.hpp"

#include "Cards.hpp"
#include "Hand.hpp"

#include "PossibleHands.hpp"
#include "AnalyzeRounds.hpp"

#include <iostream>
#include <sstream>

struct Statistics
{
    int wins;
    int ties;
    int losses;
    HandRank highHandRank;
};

typedef std::map<int, Statistics> PlayerStatistics;

void CalculateOdds::Calculate(Players& players, Deck& deck)
{
    PlayerStatistics playerStatistics;

    for(auto& player : players)
    {
        playerStatistics.insert(std::pair<int, Statistics>(player->m_id, {}));
    }

    std::map<PlayerRoundOutcome, std::function<void(const PlayerRound& playerRound, PlayerStatistics& playerStatistics)>> router{
        { PlayerRoundOutcome::WIN, [](const PlayerRound& playerRound, PlayerStatistics& playerStatistics){ playerStatistics[playerRound.id].wins++; } },
        { PlayerRoundOutcome::TIE, [](const PlayerRound& playerRound, PlayerStatistics& playerStatistics){ playerStatistics[playerRound.id].ties++; } },
        { PlayerRoundOutcome::LOSE, [](const PlayerRound& playerRound, PlayerStatistics& playerStatistics){ playerStatistics[playerRound.id].losses++; } },
    };

    Rounds winners;
    winners.reserve(1712304);

    std::string bitmask(5, 1); // K leading 1's
    bitmask.resize(deck.size(), 0); // N-K trailing 0's

    // print integers and permute bitmask
    do
	{
		Cards cards;
        cards.reserve(5);
        for (unsigned int i = 0; i < deck.size(); ++i) // [0..N-1] integers
        {
            if (bitmask[i])
			{
				cards.emplace_back(deck[i]);
			}
        }

        Hands roundHands = PossibleHands::SummarizeRoundHands(players, cards);

        // sort first
        std::sort(roundHands.begin(), roundHands.end(), std::greater<Hand>());

        // winners.emplace_back(AnalyzeRounds::Analyze(roundHands));
        for(auto& player : AnalyzeRounds::Analyze(roundHands))
        {
            router[player.playerRoundOutcome](player, playerStatistics);
        }
    }
	while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    // std::cout << "Size [ " << winners.size() << " ]" << std::endl;

    // for(unsigned i = 0; i < winners.size(); i++)
    // {
    //     if( winners[i][0].playerRoundOutcome == PlayerRoundOutcome::TIE )
    //     {
    //         std::stringstream ss;
    //         ss << winners[i];
    //         std::cout << "Round [ " << ss.str() << " ]" << std::endl;
    //     }
    // }

    for (PlayerStatistics::iterator it=playerStatistics.begin(); it!=playerStatistics.end(); ++it)
    {
        int total = it->second.wins + it->second.ties + it->second.losses;

        std::cout
        << "Player ID [ " << it->first << " ]"
        << " WINS [ " << it->second.wins << " ( " << double(it->second.wins / total) << " ) ]"
        << " TIES [ " << it->second.ties << " ( " << double(it->second.ties / total) << " ) ]"
        << " LOSSES [ " << it->second.losses << " ( " << double(it->second.losses / total) << " ) ]"
        << std::endl;

    }
}
