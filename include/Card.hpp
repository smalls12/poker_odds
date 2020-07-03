#pragma once

#include "Rank.hpp"
#include "Suit.hpp"

struct Card
{
    Rank rank;
    Suit suit;
};

inline bool operator==(const Card& lhs, const Card& rhs)
{
    if( lhs.rank == rhs.rank )
    {
        // if( lhs.suit == rhs.suit )
        // {
        //     return true;
        // }
        
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
