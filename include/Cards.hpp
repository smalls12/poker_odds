#pragma once

#include "Card.hpp"

#include <vector>

typedef std::vector<Card> Cards;

inline std::ostream& operator<<(std::ostream & os, Cards& cards)
{
    for(auto& card : cards)
    {
        os << card;
    }
    return os;
}