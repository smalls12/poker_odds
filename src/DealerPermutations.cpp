#include "DealerPermutations.hpp"

#include "spdlog/spdlog.h"

#include <algorithm>

std::vector<Cards> DealerPermutations::Simulate(Deck& deck, int cardsToDraw)
{
    // std::vector<Cards> allPossibleHands;
    
    // highest number of permutations for a valid game is 1712304
    // 2 players
    // 2 cards to start
    // 48 cards remaining in deck
    // 5 cards to draw
    // 48c5
    // allPossibleHands.reserve(1712304);


    // if( cardsToDraw > 2 )
    // {
    //     // can split the work
    //     std::vector<Cards> allPossibleHands_1 = Work(deck, std::string(cardsToDraw - (cardsToDraw % 2), 1));
    //     std::vector<Cards> allPossibleHands_2 = Work(deck, std::string(cardsToDraw, cardsToDraw - (cardsToDraw % 2)));

    //     allPossibleHands.insert( allPossibleHands.end(), allPossibleHands_1.begin(), allPossibleHands_1.end() );
    //     allPossibleHands.insert( allPossibleHands.end(), allPossibleHands_2.begin(), allPossibleHands_2.end() );
    // }
    
    // std::vector<Cards> allPossibleHands_1 = Work(deck, cardsToDraw);
    // allPossibleHands.insert( allPossibleHands.end(), allPossibleHands_1.begin(), allPossibleHands_1.end() );
    
    return Work(deck, cardsToDraw);
}

std::vector<Cards> DealerPermutations::Work(Deck& deck, int cardsToDraw)
{
    spdlog::get("console")->info("DealerPermutations::Work - start");

    std::vector<Cards> allPossibleHands;
    allPossibleHands.reserve(1712304);

    std::string bitmask(cardsToDraw, 1); // K leading 1's
    bitmask.resize(deck.size(), 0); // N-K trailing 0's

    // print integers and permute bitmask
    do
	{
		Cards cards;
        cards.reserve(cardsToDraw);
        for (unsigned int i = 0; i < deck.size(); ++i) // [0..N-1] integers
        {
            if (bitmask[i])
			{
				cards.push_back(deck[i]);
			}
        }

		allPossibleHands.push_back(cards);
    }
	while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    spdlog::get("console")->info("DealerPermutations::Work - done");

    return allPossibleHands;
}