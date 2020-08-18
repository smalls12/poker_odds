#pragma once

#include "Buffer.hpp"

#include <vector>

typedef std::vector<BaseHand*> Hands;

template<size_t S>
using HandBuffer = Buffer<ExplicitHand*, S>;

inline std::ostream& operator<<(std::ostream & os, const Hands& hands)
{
    for(auto& hand : hands)
    {
        os << *hand;
        os << "\n";
    }
    return os;
}

template<size_t M>
inline std::ostream& operator<<(std::ostream & os, const HandBuffer<M>& hands)
{  
    for(auto& hand : hands)
    {
        os << *hand;
    }
    return os;
}