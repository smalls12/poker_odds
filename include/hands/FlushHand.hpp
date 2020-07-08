#pragma once

#include "BaseHand.hpp"

class FlushHand : public BaseHand
{
    public:
        FlushHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~FlushHand() = default;

        bool operator<(FlushHand rhs);
        bool operator>(FlushHand rhs);

        bool operator<(BaseHand rhs);
        bool operator>(BaseHand rhs);
};