#include "ThreeOfAKindHand.hpp"

ThreeOfAKindHand::ThreeOfAKindHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::THREE_OF_A_KIND, validated)
{

}

bool ThreeOfAKindHand::operator<(const BaseHand& rhs) const noexcept
{
    if( rank < rhs.rank )
    {
        return true;
    }

    if( rank > rhs.rank )
    {
        return false;
    }

    if( *validated[0] < *rhs.validated[0] )
    {
        return true;
    }
    
    for(size_t x = 0; x < cards.size(); x++)
    {
        if( *cards[x] < *rhs.cards[x] )
        {
            return true;
        }
        else if( *cards[x] > *rhs.cards[x] )
        {
            return false;
        }
    }

    return false;
}

bool ThreeOfAKindHand::operator>(const BaseHand& rhs) const noexcept
{
    if( rank > rhs.rank )
    {
        return true;
    }

    if( rank < rhs.rank )
    {
        return false;
    }

    if( *validated[0] > *rhs.validated[0] )
    {
        return true;
    }
    
    for(size_t x = 0; x < cards.size(); x++)
    {
        if( *cards[x] > *rhs.cards[x] )
        {
            return true;
        }
        else if( *cards[x] < *rhs.cards[x] )
        {
            return false;
        }
    }

    return false;
}
