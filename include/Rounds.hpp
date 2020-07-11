#pragma once

#include "Round.hpp"

#include <vector>

typedef std::vector<Round> Rounds;

inline std::ostream& operator<<(std::ostream & os, Rounds& rounds)
{
    for(auto& round : rounds)
    {
        os << round;
    }
    return os;
}