#include "CalculateOdds.hpp"

#include "Cards.hpp"
#include "Hand.hpp"

#include "DealerPermutations.hpp"
#include "PossibleHands.hpp"
#include "TransposeHands.hpp"
#include "AnalyzeRounds.hpp"

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
        simulatedHands.emplace_back(possibleHands);
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

    Rounds rounds = AnalyzeRounds::Analyze(transposedHands);

    for(unsigned i = 0; i < 100; i++)
    {
        std::stringstream ss;
        ss << rounds[i];
        std::cout << "Round [ " << ss.str() << " ]" << std::endl;
    }
    
}