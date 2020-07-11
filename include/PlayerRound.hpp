#pragma once

#include "PlayerRoundOutcome.hpp"
#include "HandRank.hpp"

struct PlayerRound
{
    int id;
    PlayerRoundOutcome playerRoundOutcome;
    HandRank handRank;
};

inline std::ostream& operator<<(std::ostream & os, PlayerRound& playerRound)
{
    os << "[ ";
    os << "[ " << playerRound.id << " ]";
    os << "[ " << playerRound.playerRoundOutcome << " ]";
    os << "[ " << playerRound.handRank << " ]";
    os << " ]";
    
    return os;
}