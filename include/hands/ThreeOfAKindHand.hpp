#pragma once

#include "BaseHand.hpp"

class ThreeOfAKindHand : public BaseHand
{
    public:
        ThreeOfAKindHand(int id, Cards hand, Cards validated);
        ~ThreeOfAKindHand() = default;

        bool operator<(ThreeOfAKindHand rhs);
        bool operator>(ThreeOfAKindHand rhs);

        bool operator<(BaseHand rhs);
        bool operator>(BaseHand rhs);
};