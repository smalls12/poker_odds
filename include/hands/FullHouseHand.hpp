#pragma once

#include "BaseHand.hpp"

class FullHouseHand : public BaseHand
{
    public:
        FullHouseHand(int id, Cards hand, Cards validated);
        ~FullHouseHand() = default;

        bool operator<(const FullHouseHand& rhs);
        bool operator>(const FullHouseHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};