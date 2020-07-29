#pragma once

#include "Buffer.hpp"

#include <vector>

typedef std::vector<BaseHand*> Hands;

template<size_t S>
using HandBuffer = Buffer<BaseHand*, S>;

inline std::ostream& operator<<(std::ostream & os, const Hands& hands)
{
    for(auto& hand : hands)
    {
        os << *hand;
        os << "\n";
    }
    return os;
}
