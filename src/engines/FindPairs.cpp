#include "FindPairs.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

std::optional<HandRank> FindPairs::Find(std::vector<Card> cards)
{
    std::vector<Card> temp(cards);
    std::vector<Card>::iterator it1 = std::adjacent_find(temp.begin(), temp.end());
 
    if (it1 != temp.end())
    {
        // at this point we know we have a pair
        it1 = temp.erase(it1);

        // need to check for 3 of a kind
        std::vector<Card>::iterator it2 = std::adjacent_find(it1, temp.end());
        if (it2 != temp.end() && it2 == it1)
        {
            // at this point we know we have three of a kind
            it2 = temp.erase(it2);

            // need to check for four of a kind
            std::vector<Card> possibleFourOfAKind(temp);
            std::vector<Card>::iterator it3 = std::adjacent_find(it2, temp.end());
            if (it3 != temp.end()  && it3 == it2)
            {
                return std::optional<HandRank>{HandRank::FOUR_OF_A_KIND};
            }

            it2 = temp.erase(it2);

            // need to check for full house

            std::optional<HandRank> result = FindPairs::Find(temp);
            if( result )
            {
                if( *result == HandRank::ONE_PAIR )
                {
                    // found a full house
                    return std::optional<HandRank>{HandRank::FULL_HOUSE};
                }
            }

            return std::optional<HandRank>{HandRank::THREE_OF_A_KIND};
        }

        it1 = temp.erase(it1);

        // need to check for two pair

        std::optional<HandRank> result = FindPairs::Find(temp);
        if( result )
        {
            if( *result == HandRank::ONE_PAIR )
            {
                // found another pair
                return std::optional<HandRank>{HandRank::TWO_PAIR};
            }
        }

        return std::optional<HandRank>{HandRank::ONE_PAIR};
    }
    
    return std::nullopt;
}