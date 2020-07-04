#pragma once

#include "Card.hpp"

#include <vector>

typedef std::vector<Card> Deck;

inline std::ostream& operator<<(std::ostream & os, Deck& deck)
{
    for(auto& card : deck)
    {
        os << card;
    }
    return os;
}