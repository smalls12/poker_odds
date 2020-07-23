#include "FlushHand.hpp"

FlushHand::FlushHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::FLUSH, validated)
{

}

bool FlushHand::operator<(const BaseHand& rhs) const noexcept
{
    if( rank < rhs.rank )
    {
        return true;
    }

    if( rank > rhs.rank )
    {
        return false;
    }

    for(size_t x = 0; x < validated.size(); x++)
    {
        if( *validated[x] < *rhs.validated[x] )
        {
            return true;
        }
        else if( *validated[x] > *rhs.validated[x] )
        {
            return false;
        }
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

bool FlushHand::operator>(const BaseHand& rhs) const noexcept
{
    if( rank > rhs.rank )
    {
        return true;
    }

    if( rank < rhs.rank )
    {
        return false;
    }

    for(size_t x = 0; x < validated.size(); x++)
    {
        if( *validated[x] > *rhs.validated[x] )
        {
            return true;
        }
        else if( *validated[x] < *rhs.validated[x] )
        {
            return false;
        }
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