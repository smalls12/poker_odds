#pragma once

#include "Rank.hpp"
#include "Suit.hpp"

// Important clarification
//
// Two Cards are considered equal if the Ranks match
// Suit is not considered
//
// For an exact match, see CardExactMatch which inherits from
// card but will change the equals operator

class BaseCard
{
    public:
        bool operator==(const BaseCard& rhs) const;
        bool operator!=(const BaseCard& rhs) const;
        bool operator<(const BaseCard& rhs) const;
        bool operator>(const BaseCard& rhs) const;

        friend std::ostream& operator<<(std::ostream & os, BaseCard& hand);

        Rank rank;
        Suit suit;
};