#include "CalculateOdds.hpp"

#include "Cards.hpp"
#include "Hand.hpp"

#include "PossibleHands.hpp"
#include "TransposeHands.hpp"
#include "AnalyzeRounds.hpp"

#include <iostream>
#include <sstream>

void CalculateOdds::Calculate(Players& players, Deck& deck)
{
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

        winners.emplace_back(AnalyzeRounds::Analyze(roundHands));
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
}
