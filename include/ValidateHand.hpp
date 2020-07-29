#pragma once

#include "HandRank.hpp"

#include "FindHighCard.hpp"
#include "FindAllPairs.hpp"
#include "FindStraightsAndFlushes.hpp"

#include <optional>

class ValidateHand
{
    public:
        template<size_t N>
        inline static HandRank DetermineHandRank(const CardBuffer<N>& cards) noexcept
        {
            std::optional<HandRank> straightsAndFlushes = FindStraightsAndFlushes::FindRank(cards);
            std::optional<HandRank> pairs = FindAllPairs::FindRank(cards);

            if( straightsAndFlushes )
            {
                if( pairs )
                {
                    return (((*straightsAndFlushes) > (*pairs)) ? *straightsAndFlushes : *pairs);
                }

                return *straightsAndFlushes;
            }
            else if( pairs )
            {
                return *pairs;
            }
            
            return HandRank::HIGH_CARD;
        }
        
};