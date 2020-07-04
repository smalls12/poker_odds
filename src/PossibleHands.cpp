#include "PossibleHands.hpp"

#include "ValidateHand.hpp"
#include "HighCardHand.hpp"

#include <map>
#include <functional>

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

std::vector<Hand> PossibleHands::SummarizeAllPossibleHands(int id, std::vector<Card> cards, std::vector<std::vector<Card>> dealerPermutations)
{
    std::map<HandRank, std::function<Hand(int id, std::vector<Card> cards, std::vector<Card> validated)>> router{
        { HandRank::ROYAL_FLUSH, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::STRAIGHT_FLUSH, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::FOUR_OF_A_KIND, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::FULL_HOUSE, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::FLUSH, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::STRAIGHT, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::THREE_OF_A_KIND, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::TWO_PAIR, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::ONE_PAIR, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
        { HandRank::HIGH_CARD, [](int id, std::vector<Card> cards, std::vector<Card> validated){ return HighCardHand(id, cards, validated); } },
    };

    std::vector<Hand> possibleHands;
    for(auto& hand : dealerPermutations)
    {
        std::vector<Card> simulatedHand{cards};
        simulatedHand.insert(simulatedHand.begin(), hand.begin(), hand.end());

        // validate and find the highest hand ranking
        std::optional<ValidatedHand> result = ValidateHand::DetermineHandRank(simulatedHand);
        if( result )
        {
            possibleHands.push_back(router[(*result).rank](id, simulatedHand, (*result).cards));
        }       
    }

    return possibleHands;
}
