#include "FindRuns.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

std::optional<HandRank> FindRuns::Find(std::vector<Card> cards)
{
    std::vector<Card> temp(cards);
    std::vector<Card>::iterator it1 = std::adjacent_find(temp.begin(), temp.end(), std::greater<Card>());
 
    if (it1 == temp.end())
    {
        // at this point we know we have a straight

        return std::optional<HandRank>{HandRank::STRAIGHT};
    }

    return std::nullopt;
}