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