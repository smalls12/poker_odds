#pragma once

#include <vector>

typedef std::vector<BaseHand*> Hands;

inline std::ostream& operator<<(std::ostream & os, const Hands& hands)
{
    for(auto& hand : hands)
    {
        os << *hand;
        os << "\n";
    }
    return os;
}