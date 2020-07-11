#pragma once

#include <ostream>
#include <map>
#include <functional>

enum PlayerRoundOutcome
{
    LOSE,
    TIE,
    WIN
};

inline std::ostream& operator<<(std::ostream & os, PlayerRoundOutcome& outcome)
{
    std::map<PlayerRoundOutcome, std::function<void(std::ostream & os)>> router{
        { PlayerRoundOutcome::LOSE, [](std::ostream & os){ os << "LOSE"; } },
        { PlayerRoundOutcome::TIE, [](std::ostream & os){ os << "TIE"; } },
        { PlayerRoundOutcome::WIN, [](std::ostream & os){ os << "WIN"; } }
    };

    router[outcome](os);
    return os;
}