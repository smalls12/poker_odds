#include "PossibleHands.hpp"

std::vector<Hand> PossibleHands::SummarizeAllPossibleHands(Hand hand, Deck deck)
{
    std::vector<Hand> possibleHands;
    for(auto& card : deck)
    {
        Hand possibleHand(hand);
        possibleHand.addCard(card);
        possibleHands.push_back(possibleHand);
    }

    return possibleHands;
}

std::vector<Hand> PossibleHands::SummarizeAllPossibleHands(Hand playersHand, std::vector<std::vector<Card>> dealerPermutations)
{
    std::vector<Hand> possibleHands;
    for(auto& hand : dealerPermutations)
    {
        Hand possibleHand(playersHand);
        for(auto& card : hand)
        {
            possibleHand.addCard(card);
        }
        
        possibleHands.push_back(possibleHand);
    }

    return possibleHands;
}
