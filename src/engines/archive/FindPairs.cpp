#include "FindPairs.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

std::optional<ValidatedHand> FindPairs::Find(const Cards& cards) noexcept
{
    return Find(cards, cards.begin());
}

std::optional<ValidatedHand> FindPairs::Find(const Cards& cards, const Cards::const_iterator& start) noexcept
{
    // (void)start;
    // Cards temp(cards);
    
    Cards::const_iterator it1 = std::adjacent_find(start, cards.end(),
    [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
 
    Cards output;
    if (it1 != cards.end())
    {
        // at this point we know we have a pair
        output.emplace_back(*it1);
        // it1 = temp.erase(it1);
        it1++;

        // need to check for 3 of a kind
        Cards::const_iterator it2 = std::adjacent_find(it1, cards.end(),
        [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
        if (it2 != cards.end() && it2 == it1)
        {
            // at this point we know we have three of a kind
            output.emplace_back(*it2);
            // it2 = temp.erase(it2);
            it2++;

            // need to check for four of a kind
            Cards::const_iterator it3 = std::adjacent_find(it2, cards.end(),
            [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
            if (it3 != cards.end() && it3 == it2)
            {
                // at this point we know we have four of a kind
                return std::optional<ValidatedHand>{{HandRank::FOUR_OF_A_KIND, std::move(output)}};
            }

            output.emplace_back(*it2);
            // it2 = temp.erase(it2);
            it2++;

            // need to check for full house
            std::optional<ValidatedHand> result = FindPairs::Find(cards, it2);
            if( result )
            {
                if( (*result).rank == HandRank::ONE_PAIR )
                {
                    // found a full
                    // full house arranged three of a kind then the pair
                    // insert at the back
                    output.emplace_back((*result).cards[0]);
                    return std::optional<ValidatedHand>{{HandRank::FULL_HOUSE, std::move(output)}};
                }
            }

            return std::optional<ValidatedHand>{{HandRank::THREE_OF_A_KIND, std::move(output)}};
        }

        // it1 = temp.erase(it1);
        it1++;

        // need to check for full house and two pair
        std::optional<ValidatedHand> result = FindPairs::Find(cards, it1);
        if( result )
        {
            if ( (*result).rank == HandRank::THREE_OF_A_KIND )
            {
                // found three of a kind
                // full house arranged three of a kind then the pair
                // insert infront
                output.insert(output.begin(), (*result).cards[0]);
                return std::optional<ValidatedHand>{{HandRank::FULL_HOUSE, std::move(output)}};

            }
            else if( (*result).rank == HandRank::ONE_PAIR )
            {
                // found another pair
                output.emplace_back((*result).cards[0]);
                return std::optional<ValidatedHand>{{HandRank::TWO_PAIR, std::move(output)}};
            }
            else if( (*result).rank == HandRank::FULL_HOUSE )
            {
                // found another pair
                output.insert(output.begin(), (*result).cards[0]);
                return std::optional<ValidatedHand>{{HandRank::FULL_HOUSE, std::move(output)}};
            }
            else
            {
                // dunno
                std::cout << "dunno [ " << (*result).rank << " ]" << std::endl;
            }            
        }

        return std::optional<ValidatedHand>{{HandRank::ONE_PAIR, std::move(output)}};
    }
    
    return std::nullopt;
}