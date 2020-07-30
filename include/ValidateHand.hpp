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
        inline static HandRank DetermineHandRank(CardBuffer<N>& cards) noexcept
        {
            std::sort(std::begin(cards), std::end(cards),
            [](const Card* const lhs, const Card* const rhs){ return *lhs > *rhs; });

            std::optional<HandRank> pairs = FindAllPairs::FindRank(cards);
            if( pairs )
            {
                if( *pairs == HandRank::FOUR_OF_A_KIND || *pairs == HandRank::FULL_HOUSE )
                {
                    // impossible to get a run
                    // and a flush would only be a lower ranking hand
                    return *pairs;
                }
            }

            // std::sort(std::begin(cards), std::end(cards),
            // [](const Card* const lhs, const Card* const rhs){ return (*lhs).suit > (*rhs).suit; });
            
            std::optional<HandRank> straightsAndFlushes = FindStraightsAndFlushes::FindRank(cards);

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