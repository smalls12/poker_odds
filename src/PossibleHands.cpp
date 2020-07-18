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

Hands PossibleHands::SummarizeRoundHands(Players& players, Cards& cards)
{
    std::vector<Hand> roundHands;
    roundHands.reserve(players.size());
    for(auto& player : players)
    {
        // build the hand for the player
        Cards playersPossibleHand;
        playersPossibleHand.reserve(7);
        playersPossibleHand.insert( playersPossibleHand.end(), player->m_hand.begin(), player->m_hand.end() );
        playersPossibleHand.insert( playersPossibleHand.end(), cards.begin(), cards.end() );

        // sort first
        std::sort(playersPossibleHand.begin(), playersPossibleHand.end(),
        [](const Card* lhs, const Card* rhs){ return *lhs > *rhs; });

        // validate and find the highest hand ranking
        ValidatedHand result = ValidateHand::DetermineHandRank(playersPossibleHand);

        roundHands.emplace_back(HandFactory::Build(player->m_id, playersPossibleHand, result));
    }
    
    return roundHands;
}