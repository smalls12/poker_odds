#include "HandDatabase.hpp"

#include "Deck.hpp"
#include "DeckBuilder.hpp"

#include "Find.hpp"
#include "ValidateHand.hpp"
#include "DealerPermutations.hpp"

#include "spdlog/spdlog.h"

#include <algorithm>
#include <map>
#include <functional>
#include <sstream>
#include <iostream>

HandDatabase::HandDatabase()
:   m_allPossibleHands(),
    m_royalFlushHands(),
    m_straightFlushHands(),
    m_fourOfAKindHands(),
    m_fullHouseHands(),
    m_flushHands(),
    m_straightHands(),
    m_threeOfAKindHands(),
    m_twoPairHands(),
    m_onePairHands(),
    m_highCardHands()
{
    auto start = std::chrono::steady_clock::now();
    BuildDatabase();
    auto end = std::chrono::steady_clock::now();
	spdlog::get("console")->info("Finished building database in [{}]ms", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    start = std::chrono::steady_clock::now();
    RankHandsInDatabase();
    end = std::chrono::steady_clock::now();
	spdlog::get("console")->info("Finished ranking database in [{}]ms", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
}

void HandDatabase::BuildDatabase()
{
    // build a 52 card deck
	Deck deck = DeckBuilder::Build();

    m_allPossibleHands = DealerPermutations::Simulate(deck, 5);

    spdlog::get("console")->info("Total Possible Hands [{}]", m_allPossibleHands.size()); 
}

void HandDatabase::RankHandsInDatabase()
{
    std::map<HandRank, std::function<void(std::vector<Card> hand)>> router{
        { HandRank::ROYAL_FLUSH, [this](std::vector<Card> hand){ m_royalFlushHands.push_back(hand); } },
        { HandRank::STRAIGHT_FLUSH, [this](std::vector<Card> hand){ m_straightFlushHands.push_back(hand); } },
        { HandRank::FOUR_OF_A_KIND, [this](std::vector<Card> hand){ m_fourOfAKindHands.push_back(hand); } },
        { HandRank::FULL_HOUSE, [this](std::vector<Card> hand){ m_fullHouseHands.push_back(hand); } },
        { HandRank::FLUSH, [this](std::vector<Card> hand){ m_flushHands.push_back(hand); } },
        { HandRank::STRAIGHT, [this](std::vector<Card> hand){ m_straightHands.push_back(hand); } },
        { HandRank::THREE_OF_A_KIND, [this](std::vector<Card> hand){ m_threeOfAKindHands.push_back(hand); } },
        { HandRank::TWO_PAIR, [this](std::vector<Card> hand){ m_twoPairHands.push_back(hand); } },
        { HandRank::ONE_PAIR, [this](std::vector<Card> hand){ m_onePairHands.push_back(hand); } },
        { HandRank::HIGH_CARD, [this](std::vector<Card> hand){ m_highCardHands.push_back(hand); } }
    };

    for(auto& hand : m_allPossibleHands)
    {
        std::optional<ValidatedHand> result = ValidateHand::DetermineHandRank(hand);
        
        if( result )
        {
            router[(*result).rank](hand);
        }
        
    }

    spdlog::get("console")->info("Hands with High Card [{}]",m_highCardHands.size());
    spdlog::get("console")->info("Hands with One Pair [{}]",m_onePairHands.size());
    spdlog::get("console")->info("Hands with Two Pair [{}]", m_twoPairHands.size());
    spdlog::get("console")->info("Hands with Three of a Kind [{}]", m_threeOfAKindHands.size());
    spdlog::get("console")->info("Hands with Straight [{}]", m_straightHands.size());
    spdlog::get("console")->info("Hands with Flush [{}]", m_flushHands.size());
    spdlog::get("console")->info("Hands with Full House [{}]", m_fullHouseHands.size());
    spdlog::get("console")->info("Hands with Four of a Kind [{}]", m_fourOfAKindHands.size());
    spdlog::get("console")->info("Hands with Straight Flush [{}]", m_straightFlushHands.size());
    spdlog::get("console")->info("Hands with Royal Flush [{}]", m_royalFlushHands.size());

    // for(auto& hand : m_onePairHands)
    // {
    //     for(auto& card : hand)
    //     {
    //         std::stringstream ss;
    //         ss << card;
    //         std::cout << ss.str();
    //     }

    //     std::cout << std::endl;
    // }

    
}
