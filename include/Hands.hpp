#pragma once

#include "Hand.hpp"

#include <vector>

typedef std::vector<Hand> Hands;

inline std::ostream& operator<<(std::ostream & os, Hands& hands)
{
    for(auto& hand : hands)
    {
        os << hand;
    }
    return os;
}