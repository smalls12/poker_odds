#include "DealerPermutations.hpp"

#include <algorithm>

std::vector<std::vector<Card>> DealerPermutations::Simulate(Deck& deck, int cardsToDraw)
{
    std::vector<std::vector<Card>> allPossibleHands;

    // if( cardsToDraw > 2 )
    // {
    //     // can split the work
    //     std::vector<std::vector<Card>> allPossibleHands_1 = Work(deck, std::string(cardsToDraw - (cardsToDraw % 2), 1));
    //     std::vector<std::vector<Card>> allPossibleHands_2 = Work(deck, std::string(cardsToDraw, cardsToDraw - (cardsToDraw % 2)));

    //     allPossibleHands.insert( allPossibleHands.end(), allPossibleHands_1.begin(), allPossibleHands_1.end() );
    //     allPossibleHands.insert( allPossibleHands.end(), allPossibleHands_2.begin(), allPossibleHands_2.end() );
    // }
    
    std::vector<std::vector<Card>> allPossibleHands_1 = Work(deck, std::string(cardsToDraw, 1));
    allPossibleHands.insert( allPossibleHands.end(), allPossibleHands_1.begin(), allPossibleHands_1.end() );
    
    return allPossibleHands;
}

std::vector<std::vector<Card>> DealerPermutations::Work(Deck& deck, std::string bitmask)
{
    std::vector<std::vector<Card>> allPossibleHands;

    // std::string bitmask(cardsToDraw, 1); // K leading 1's
    bitmask.resize(deck.size(), 0); // N-K trailing 0's

    // print integers and permute bitmask
    do
	{
		std::vector<Card> cards;
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

    return allPossibleHands;
}