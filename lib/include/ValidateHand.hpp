#pragma once

#include "HandRank.hpp"

#include "FindHighCard.hpp"
#include "FindAllPairs.hpp"
#include "FindStraights.hpp"

#include <optional>

class ValidateHand
{
    public:
        template<size_t N>
        inline static HandRank DetermineHandRank(CardBuffer<N>& cards, bool flush) noexcept
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

            std::optional<HandRank> straight = FindStraights::FindRank(cards, flush);
            // std::optional<HandRank> straight = std::nullopt;

            if( straight )
            {
                if( pairs )
                {
                    return (((*straight) > (*pairs)) ? *straight : *pairs);
                }

                return *straight;
            }
            else if( pairs )
            {
                return *pairs;
            }   

            return HandRank::HIGH_CARD;
        }
};