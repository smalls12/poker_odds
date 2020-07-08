#include "PossibleHands.hpp"

#include "ValidateHand.hpp"
#include "HandFactory.hpp"

#include "spdlog/spdlog.h"

std::vector<Hand> PossibleHands::SummarizeAllPossibleHands(int id, Cards cards, std::vector<Cards>& dealerPermutations)
{
    spdlog::get("console")->info("PossibleHands::SummarizeAllPossibleHands - start");

    std::vector<Hand> possibleHands;
    possibleHands.reserve(dealerPermutations.size());
    for(auto& hand : dealerPermutations)
    {
        std::vector<Card> simulatedHand;
        simulatedHand.reserve(7);

        simulatedHand.insert( simulatedHand.end(), cards.begin(), cards.end() );
        simulatedHand.insert( simulatedHand.end(), hand.begin(), hand.end() );

        // validate and find the highest hand ranking
        ValidatedHand result = ValidateHand::DetermineHandRank(simulatedHand);
        possibleHands.push_back(HandFactory::Build(id, simulatedHand, result));      
    }

    spdlog::get("console")->info("PossibleHands::SummarizeAllPossibleHands - done");

    return possibleHands;
}
