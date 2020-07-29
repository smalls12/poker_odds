#pragma once

#include "Card.hpp"
#include "Buffer.hpp"

#include <vector>
#include <array>

typedef std::vector<Card*> Cards;

template<size_t N>
using CardBuffer = Buffer<BaseCard*, N>;

inline std::ostream& operator<<(std::ostream & os, Cards& cards)
{
    for(auto& card : cards)
    {
        os << *card;
    }
    return os;
}
