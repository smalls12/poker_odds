#pragma once

#include "Rounds.hpp"
#include "Hand.hpp"

#include <vector>

class AnalyzeRounds
{
    public:
        static Rounds Analyze(std::vector<Hands>& roundHands);
};