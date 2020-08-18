#pragma once

#include "Cards.hpp"

#include <vector>

class HandDatabase
{
    public:
        HandDatabase();
        ~HandDatabase() = default;
    
    private:
        void BuildDatabase();
        void RankHandsInDatabase();

        std::vector<Cards>  m_allPossibleHands;

        std::vector<Cards>  m_royalFlushHands;
        std::vector<Cards>  m_straightFlushHands;
        std::vector<Cards>  m_straightFlushAceLowHands;
        std::vector<Cards>  m_fourOfAKindHands;
        std::vector<Cards>  m_fullHouseHands;
        std::vector<Cards>  m_flushHands;
        std::vector<Cards>  m_straightHands;
        std::vector<Cards>  m_straightAceLowHands;
        std::vector<Cards>  m_threeOfAKindHands;
        std::vector<Cards>  m_twoPairHands;
        std::vector<Cards>  m_onePairHands;
        std::vector<Cards>  m_highCardHands;
};