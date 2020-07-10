#pragma once

#include "BaseHand.hpp"

class FullHouseHand : public BaseHand
{
    public:
        FullHouseHand(int id, std::vector<Card> hand, std::vector<Card> validated);
        ~FullHouseHand() = default;

        bool operator<(const FullHouseHand& rhs);
        bool operator>(const FullHouseHand& rhs);

        bool operator<(const BaseHand& rhs);
        bool operator>(const BaseHand& rhs);
};