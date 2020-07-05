#include "PossibleHands.hpp"

#include "ValidateHand.hpp"
#include "HandFactory.hpp"

std::vector<Hand> PossibleHands::SummarizeAllPossibleHands(int id, Cards cards, std::vector<Cards> dealerPermutations)
{
    std::vector<Hand> possibleHands;
    for(auto& hand : dealerPermutations)
    {
        std::vector<Card> simulatedHand{cards};
        simulatedHand.insert(simulatedHand.begin(), hand.begin(), hand.end());

        // validate and find the highest hand ranking
        ValidatedHand result = ValidateHand::DetermineHandRank(simulatedHand);
        possibleHands.push_back(HandFactory::Build(id, simulatedHand, result));      
    }

    return possibleHands;
}
