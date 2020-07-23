#pragma once

#include "Rounds.hpp"
#include "Hand.hpp"

#include <vector>

class AnalyzeRounds
{
    public:
        static Round Analyze(const Hands& roundHand) noexcept;

};