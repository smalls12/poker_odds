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

template<size_t M, size_t N>
inline void copy(const CardBuffer<M>& lhs, CardBuffer<N>& rhs)
{
    for(size_t x = 0; x < M; x++)
    {
        rhs[x] = lhs[x];
    }
}

template<size_t N>
inline std::ostream& operator<<(std::ostream & os, const CardBuffer<N>& cards)
{
    for(auto& card : cards)
    {
        os << *card;
    }
    return os;
}