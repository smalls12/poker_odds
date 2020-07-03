#include "CalculateOdds.hpp"

#include "PossibleHands.hpp"
#include "TransposeHands.hpp"

#include "spdlog/spdlog.h"

#include <iostream>
#include <sstream>

void CalculateOdds::Calculate(Players& players, Deck& deck)
{
    std::vector<std::vector<Hand>> hands;
    for(auto& player : players)
    {
        std::vector<Hand> possibleHands = PossibleHands::SummarizeAllPossibleHands(player->GetHand(), deck);
        hands.push_back(possibleHands);
    }

    std::vector<std::vector<Hand>> transposedHands = TransposeHands::Transpose(hands);

    // for(auto& handsForComparison : transposedHands)
    // {
    //     for(auto& evaluate : handsForComparison)
    //     {
    //         std::stringstream ss;
    //         ss << evaluate;
    //         std::cout << ss.str() << std::endl;
    //     }
    // }

    std::vector<Hand> winners;
    for(auto& handsForComparison : transposedHands)
    {
        // sort first
        std::sort(handsForComparison.begin(), handsForComparison.end());
        winners.push_back(handsForComparison[handsForComparison.size() - 1]);
    }

    for(auto& winner : winners)
    {
        std::stringstream ss;
        ss << winner;
        std::cout << "Winning hand [ " << ss.str() << " ]" << std::endl;
    }
    
}