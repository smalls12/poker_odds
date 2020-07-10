#include "CalculateOdds.hpp"

#include "Cards.hpp"
#include "Hands.hpp"

#include "DealerPermutations.hpp"
#include "PossibleHands.hpp"
#include "TransposeHands.hpp"

#include "spdlog/spdlog.h"

#include <iostream>
#include <sstream>

void CalculateOdds::Calculate(Players& players, Deck& deck)
{
    // we have the players hands
    // we have the deck with the remaining cards
    // build out all the different dealer permutations
    std::vector<Cards> dealerPermutations = DealerPermutations::Simulate(deck, 5);

    // now take the dealer permutations and simulate the possible hands for each player
    std::vector<Hands> simulatedHands;
    simulatedHands.reserve(players.size());
    for(auto& player : players)
    {
        Hands possibleHands = PossibleHands::SummarizeAllPossibleHands(player->m_id, player->m_hand, dealerPermutations);
        simulatedHands.push_back(possibleHands);
    }

    // compare each simulated hand between players
    std::vector<Hands> transposedHands = TransposeHands::Transpose(simulatedHands);

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
    winners.reserve(transposedHands.size());
    for(auto& handsForComparison : transposedHands)
    {
        // sort first
        std::sort(handsForComparison.begin(), handsForComparison.end(), std::greater<Hand>());
        winners.push_back(handsForComparison[0]);
    }

    // for(auto& winner : winners)
    // {
    //     std::stringstream ss;
    //     ss << winner;
    //     std::cout << "Winning hand [ " << ss.str() << " ]" << std::endl;
    // }
    
}