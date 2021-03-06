#pragma once

#include "Card.hpp"

class CardExactMatch : public Card
{
    // nothin extra
    // just different equals operator
};

inline bool operator==(const CardExactMatch& lhs, const CardExactMatch& rhs)
{    
    if( lhs.rank == rhs.rank )
    {
        if( lhs.suit == rhs.suit )
        {
            return true;
        }
        
        return false;
    }

    return false;
}
