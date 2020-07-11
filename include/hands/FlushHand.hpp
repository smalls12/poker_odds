#pragma once

#include "BaseHand.hpp"

class FlushHand : public BaseHand
{
    public:
        FlushHand(int id, Cards hand, Cards validated);
        ~FlushHand() = default;

        bool operator<(FlushHand rhs);
        bool operator>(FlushHand rhs);

        bool operator<(BaseHand rhs);
        bool operator>(BaseHand rhs);
};