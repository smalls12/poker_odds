#pragma once

#include "BaseHand.hpp"

class StraightHand : public BaseHand
{
    public:
        StraightHand(int id, Cards hand, Cards validated);
        ~StraightHand() = default;

        bool operator<(StraightHand rhs);
        bool operator>(StraightHand rhs);

        bool operator<(BaseHand rhs);
        bool operator>(BaseHand rhs);
};