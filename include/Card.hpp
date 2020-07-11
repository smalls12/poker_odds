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

struct Card
{
    Rank rank;
    Suit suit;
};

inline bool operator==(const Card& lhs, const Card& rhs)
{
    if( lhs.rank == rhs.rank )
    {
        return true;
    }

    return false;
}

inline bool operator!=(const Card& lhs, const Card& rhs)
{
    return !(lhs == rhs);
}

inline bool operator<(const Card& lhs, const Card& rhs)
{   
    // suits are ranked equally
    // only compare the rank
    if( lhs.rank < rhs.rank )
    {
        return true;
    }

    return false;
}

inline bool operator>(const Card& lhs, const Card& rhs)
{
    return !(lhs < rhs);
}

inline std::ostream& operator<<(std::ostream & os, Card& card)
{
    os << "[ [ ";
    os << card.rank;
    os << " ][ ";
    os << card.suit;
    os << " ] ]";

    return os;
}
