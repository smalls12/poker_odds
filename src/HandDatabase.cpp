#include "HandDatabase.hpp"

#include "Deck.hpp"
#include "DeckBuilder.hpp"
#include "ValidateHand.hpp"

#include <algorithm>
#include <map>
#include <functional>
#include <sstream>
#include <iostream>

HandDatabase::HandDatabase()
:   m_allPossibleHands(),
    m_fourOfAKindHands(),
    m_fullHouseHands(),
    m_threeOfAKindHands(),
    m_twoPairHands(),
    m_onePairHands(),
    m_highCardHands()
{
    BuildDatabase();
    RankHandsInDatabase();
}

void HandDatabase::BuildDatabase()
{
    // build a 52 card deck
	Deck deck = DeckBuilder::Build();

    std::string bitmask(5, 1); // K leading 1's
    bitmask.resize(52, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do
	{
		std::vector<Card> cards;
        for (int i = 0; i < 52; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
			{
				cards.push_back(deck[i]);
				// std::cout << " " << i;
			}
        }
        // sort first
        std::sort(cards.begin(), cards.end());

		m_allPossibleHands.push_back(cards);
        // std::cout << std::endl;
    }
	while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    std::cout << "Total Possible Hands [ " << m_allPossibleHands.size() << " ]" << std::endl;
}

void HandDatabase::RankHandsInDatabase()
{
    std::map<HandRank, std::function<void(std::vector<Card> hand)>> router{
        { HandRank::FOUR_OF_A_KIND, [this](std::vector<Card> hand){ m_fourOfAKindHands.push_back(hand); } },
        { HandRank::FULL_HOUSE, [this](std::vector<Card> hand){ m_fullHouseHands.push_back(hand); } },
        { HandRank::THREE_OF_A_KIND, [this](std::vector<Card> hand){ m_threeOfAKindHands.push_back(hand); } },
        { HandRank::TWO_PAIR, [this](std::vector<Card> hand){ m_twoPairHands.push_back(hand); } },
        { HandRank::ONE_PAIR, [this](std::vector<Card> hand){ m_onePairHands.push_back(hand); } },
        { HandRank::HIGH_CARD, [this](std::vector<Card> hand){ m_highCardHands.push_back(hand); } }
    };

    for(auto& hand : m_allPossibleHands)
    {
        router[ValidateHand::DetermineHandRank(hand)](hand);
    }

    std::cout << "Hands with One Pair [ " << m_onePairHands.size() << " ]" << std::endl;
    std::cout << "Hands with Two Pair [ " << m_twoPairHands.size() << " ]" << std::endl;
    std::cout << "Hands with Three of a Kind [ " << m_threeOfAKindHands.size() << " ]" << std::endl;
    std::cout << "Hands with Full House [ " << m_fullHouseHands.size() << " ]" << std::endl;
    std::cout << "Hands with Four of a Kind [ " << m_fourOfAKindHands.size() << " ]" << std::endl;

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
