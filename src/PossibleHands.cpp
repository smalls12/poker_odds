#include "PossibleHands.hpp"

#include "ValidateHand.hpp"
#include "HandFactory.hpp"

#include <sstream>

std::vector<Hand> PossibleHands::SummarizeAllPossibleHands(int id, Cards& cards, std::vector<Cards>& dealerPermutations)
{
    std::vector<Hand> possibleHands;
    possibleHands.reserve(dealerPermutations.size());
    for(auto hand : dealerPermutations)
    {
        // Cards simulatedHand;
        // simulatedHand.reserve(7);

        hand.insert( hand.end(), cards.begin(), cards.end() );
        // simulatedHand.insert( simulatedHand.end(), hand.begin(), hand.end() );

        // sort first
        std::sort(hand.begin(), hand.end(),
        [](const Card* lhs, const Card* rhs){ return *lhs > *rhs; });

        // validate and find the highest hand ranking
        ValidatedHand result = ValidateHand::DetermineHandRank(hand);
        possibleHands.emplace_back(HandFactory::Build(id, hand, result));
    }

    return possibleHands;
}
