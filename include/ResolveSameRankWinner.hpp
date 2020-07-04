#pragma once

#include "RankEquality.hpp"
#include "Hand.hpp"

class ResolveSameRankWinner
{
    public:
        static RankEquality Resolve(Hand hand1, Hand hand2);
    
    private:
        static RankEquality ResolveOnePair(Hand hand1, Hand hand2);
};