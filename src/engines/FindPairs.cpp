#include "FindPairs.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

std::optional<ValidatedHand> FindPairs::Find(Cards& cards)
{
    Cards temp(cards);
    
    Cards::iterator it1 = std::adjacent_find(temp.begin(), temp.end(),
    [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; });
 
    Cards output;
    output.reserve(5);
    if (it1 != temp.end())
    {
        // at this point we know we have a pair
        output.emplace_back(*it1);
        it1 = temp.erase(it1);

        // need to check for 3 of a kind
        Cards::iterator it2 = std::adjacent_find(it1, temp.end(),
        [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; });
        if (it2 != temp.end() && it2 == it1)
        {
            // at this point we know we have three of a kind
            output.emplace_back(*it2);
            it2 = temp.erase(it2);

            // need to check for four of a kind
            Cards possibleFourOfAKind(temp);
            Cards::iterator it3 = std::adjacent_find(it2, temp.end(),
            [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; });
            if (it3 != temp.end()  && it3 == it2)
            {
                return std::optional<ValidatedHand>{{HandRank::FOUR_OF_A_KIND, output}};
            }

            output.emplace_back(*it2);
            it2 = temp.erase(it2);

            // need to check for full house

            std::optional<ValidatedHand> result = FindPairs::Find(temp);
            if( result )
            {
                if( (*result).rank == HandRank::ONE_PAIR )
                {
                    // found a full house
                    output.insert(output.end(), (*result).cards.begin(), (*result).cards.end());
                    return std::optional<ValidatedHand>{{HandRank::FULL_HOUSE, output}};
                }
            }

            return std::optional<ValidatedHand>{{HandRank::THREE_OF_A_KIND, output}};
        }

        it1 = temp.erase(it1);

        // need to check for full house and two pair 

        std::optional<ValidatedHand> result = FindPairs::Find(temp);
        if( result )
        {
            if ( (*result).rank == HandRank::THREE_OF_A_KIND )
            {
                // found three of a kind
                output.insert(output.end(), (*result).cards.begin(), (*result).cards.end());
                return std::optional<ValidatedHand>{{HandRank::FULL_HOUSE, output}};

            }
            else if( (*result).rank == HandRank::ONE_PAIR )
            {
                // found another pair
                output.insert(output.end(), (*result).cards.begin(), (*result).cards.end());
                return std::optional<ValidatedHand>{{HandRank::TWO_PAIR, output}};
            }
            else
            {
                // dunno
            }            
        }

        return std::optional<ValidatedHand>{{HandRank::ONE_PAIR, output}};
    }
    
    return std::nullopt;
}