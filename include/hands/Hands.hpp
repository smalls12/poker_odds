#pragma once

#include "BaseHand.hpp"

#include <vector>

typedef std::vector<BaseHand> Hands;

inline std::ostream& operator<<(std::ostream & os, Hands& hands)
{
    for(auto& hand : hands)
    {
        os << hand;
    }
    return os;
}