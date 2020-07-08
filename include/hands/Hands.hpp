#pragma once

#include "BaseHand.hpp"

#include "spdlog/spdlog.h"

#include <vector>

typedef std::vector<BaseHand> Hands;

inline std::ostream& operator<<(std::ostream & os, Hands& hands)
{
    spdlog::get("console")->info("Hand");

    for(auto& hand : hands)
    {
        os << hand;
        os << "\n";
    }
    return os;
}