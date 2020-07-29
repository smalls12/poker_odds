#include "PossibleHands.hpp"

#include "ValidateHand.hpp"
#include "HandFactory.hpp"

#include <sstream>

Hands PossibleHands::SummarizeAllPossibleHands(int id, Cards& cards, std::vector<Cards>& dealerPermutations)
{
    Hands possibleHands;
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
        HandRank handRank = ValidateHand::DetermineHandRank(hand);
        possibleHands.emplace_back(HandFactory::Build(id, hand, handRank));
    }

    return possibleHands;
}

Hands PossibleHands::SummarizeRoundHands(const Players& players, const Cards& cards) noexcept
{
    Hands roundHands;
    roundHands.reserve(players.size());
    
    for(const auto& player : players)
    {
        // build the hand for the player
        Cards playersPossibleHand;
        playersPossibleHand.reserve(7);
        playersPossibleHand.insert( playersPossibleHand.end(), player->m_hand.begin(), player->m_hand.end() );
        playersPossibleHand.insert( playersPossibleHand.end(), cards.begin(), cards.end() );

        // sort first
        std::sort(playersPossibleHand.begin(), playersPossibleHand.end(),
        [](const Card* const lhs, const Card* const rhs){ return *lhs > *rhs; });

        // validate and find the highest hand ranking
        HandRank handRank = ValidateHand::DetermineHandRank(playersPossibleHand);

        roundHands.emplace_back(HandFactory::Build(player->m_id, std::move(playersPossibleHand), handRank));
    }
    
    return roundHands;
}
