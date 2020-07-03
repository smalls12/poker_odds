#pragma once

#include "Card.hpp"

#include <vector>

class HandDatabase
{
    public:
        HandDatabase();
        ~HandDatabase() = default;
    
    private:
        void BuildDatabase();
        void RankHandsInDatabase();

        std::vector<std::vector<Card>>  m_allPossibleHands;

        std::vector<std::vector<Card>>  m_fourOfAKindHands;
        std::vector<std::vector<Card>>  m_fullHouseHands;
        std::vector<std::vector<Card>>  m_threeOfAKindHands;
        std::vector<std::vector<Card>>  m_twoPairHands;
        std::vector<std::vector<Card>>  m_onePairHands;
        std::vector<std::vector<Card>>  m_highCardHands;
};