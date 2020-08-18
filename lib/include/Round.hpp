#pragma once

#include "PlayerRound.hpp"

#include <vector>

typedef std::vector<PlayerRound> Round;

inline std::ostream& operator<<(std::ostream & os, Round& round)
{
    for(auto& playerRound : round)
    {
        os << playerRound;
    }
    return os;
}