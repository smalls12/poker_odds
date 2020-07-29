#include "CalculateOdds.hpp"

#include "Cards.hpp"
#include "Hand.hpp"

#include "PossibleHands.hpp"
#include "AnalyzeRounds.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>      // std::setprecision

void CalculateOdds::Calculate(Players& players, Deck& deck)
{
    HandBuffer<4> cardPermutationsHandRankOnlyBuffer;
	HandBuffer<4> cardPermutationsHandBuffer;

    for(unsigned short x = 0; x < players.size(); x++)
    {
        players[x]->setCardPermutationsHandRankOnlyBufferLocation(&cardPermutationsHandRankOnlyBuffer[x]);
        players[x]->setCardPermutationsHandBufferLocation(&cardPermutationsHandBuffer[x]);
    }

    PlayerStatistics playerStatistics;

    for(auto& player : players)
    {
        playerStatistics.insert(std::pair<int, Statistics>(player->m_id, {}));
    }

    std::string bitmask(5, 1); // K leading 1's
    bitmask.resize(deck.size(), 0); // N-K trailing 0's

    CardBuffer<5> cards;

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

        PossibleHands::Generate(players, cards);

        // sort first
        std::sort(cardPermutationsHandRankOnlyBuffer.begin(), cardPermutationsHandRankOnlyBuffer.end(),
        [](const Hand* const lhs, const Hand* const rhs){ return *lhs > *rhs; });

        AnalyzeRounds::Analyze(cardPermutationsHandRankOnlyBuffer, playerStatistics);

        // std::cout << cardPermutationsHandRankOnlyBuffer << std::endl;
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
