#pragma once

#include "BaseHand.hpp"

class TwoPairHand : public BaseHand
{
    public:
        TwoPairHand(int id, Cards hand, Cards validated);
        ~TwoPairHand() = default;

        bool operator<(TwoPairHand rhs);
        bool operator>(TwoPairHand rhs);

        bool operator<(BaseHand rhs);
        bool operator>(BaseHand rhs);
};