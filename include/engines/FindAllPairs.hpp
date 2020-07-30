#pragma once

#include "Find.hpp"

#include <optional>

static std::map<HandRank, std::function<HandRank(int)>> router{
    {HandRank::HIGH_CARD, [](int newPair){
        switch(newPair)
        {
            case 2:
            {
                return HandRank::TWO_PAIR;
            }
            case 3:
            {
                return HandRank::THREE_OF_A_KIND;
            }
            case 4:
            {
                return HandRank::FOUR_OF_A_KIND;
            }
            default:
            {
                return HandRank::HIGH_CARD;
            }
        }
    }},
    {HandRank::ONE_PAIR, [](int newPair){
        switch(newPair)
        {
            case 2:
            {
                return HandRank::TWO_PAIR;
            }
            case 3:
            {
                return HandRank::FULL_HOUSE;
            }
            case 4:
            {
                return HandRank::FOUR_OF_A_KIND;
            }
            default:
            {
                return HandRank::ONE_PAIR;
            }
        }
    }},
    {HandRank::TWO_PAIR, [](int newPair){
        switch(newPair)
        {
            case 3:
            {
                return HandRank::FULL_HOUSE;
            }
            default:
            {
                return HandRank::TWO_PAIR;
            }
        }
    }},
    {HandRank::THREE_OF_A_KIND, [](int newPair){
        switch(newPair)
        {
            case 2:
            {
                return HandRank::FULL_HOUSE;
            }
            case 3:
            {
                return HandRank::FULL_HOUSE;
            }
            case 4:
            {
                return HandRank::FOUR_OF_A_KIND;
            }
            default:
            {
                return HandRank::THREE_OF_A_KIND;
            }
        }
    }},
    {HandRank::FULL_HOUSE, [](int newPair){
        switch(newPair)
        {
            default:
            {
                return HandRank::FULL_HOUSE;
            }
        }
    }},
    {HandRank::FOUR_OF_A_KIND, [](int newPair){
        switch(newPair)
        {
            default:
            {
                return HandRank::FOUR_OF_A_KIND;
            }
        }
    }}
};

class FindAllPairs
{
    public:
        // template<size_t N>
        // inline static typename CardBuffer<N>::const_iterator FindIterator(const CardBuffer<N>& cards, typename CardBuffer<N>::const_iterator& start)
        // {
        //     typename CardBuffer<N>::const_iterator it = std::adjacent_find(start, cards.end(),
        //     [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });

        //     if (it != cards.end() && it == start)
        //     {
        //         it = std::adjacent_find(++it, cards.end(),
        //         [](const Card* const lhs, const Card* const rhs){ return *lhs != *rhs; });

        //         if (it != cards.end() )
        //         {
        //             it++;
        //         }
        //     }

        //     return it;
        // }

        template<size_t N>
        inline static typename std::optional<HandRank> FindRank(const CardBuffer<N>& cards) noexcept
        {
            HandRank currentHandRank = HandRank::HIGH_CARD;

            typename CardBuffer<N>::const_iterator pair_start = std::adjacent_find(cards.begin(), cards.end(),
            [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
    
            while( pair_start != cards.end() )
            {
                typename CardBuffer<N>::const_iterator pair_end = std::adjacent_find(pair_start + 1, cards.end(),
                [](const Card* const lhs, const Card* const rhs){ return *lhs != *rhs; });

                if (pair_end != cards.end() )
                {
                    pair_end++;
                }

                // std::cout << "hi" << std::endl;
                int cardsInSequence = std::distance(pair_start, pair_end);
                // std::cout << cardsInSequence << std::endl;

                if( cardsInSequence > 1 )
                {
                    // std::cout << "what" << std::endl;
                    currentHandRank = router[currentHandRank](cardsInSequence);
                    if( currentHandRank == HandRank::FOUR_OF_A_KIND )
                    {
                        break;
                    }
                    else if( currentHandRank == HandRank::FULL_HOUSE )
                    {
                        break;
                    }
                }

                pair_start = std::next(pair_start, cardsInSequence);
                
                
                pair_start = std::adjacent_find(pair_start, cards.end(),
                [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
            }

            return std::optional<HandRank>{currentHandRank};
        }
};