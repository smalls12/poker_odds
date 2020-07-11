#pragma once

#include "BaseHand.hpp"

class FourOfAKindHand : public BaseHand
{
    public:
        FourOfAKindHand(int id, Cards hand, Cards validated);
        ~FourOfAKindHand() = default;

        bool operator<(FourOfAKindHand rhs);
        bool operator>(FourOfAKindHand rhs);

        bool operator<(BaseHand rhs);
        bool operator>(BaseHand rhs);
};