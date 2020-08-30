#include "HighCardHand.hpp"

HighCardHand::HighCardHand(Player& player)
:   ExplicitHand(player, HandRank::HIGH_CARD)
{

}

bool HighCardHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return false;
    }

    for(size_t x = 0; x < cards->size(); x++)
    {
        if( *(*cards)[x] < *(*rhs.cards)[x] )
        {
            return true;
        }
        else if( *(*cards)[x] > *(*rhs.cards)[x] )
        {
            return false;
        }
    }

    return false;
}

bool HighCardHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return false;
    }

    for(size_t x = 0; x < cards->size(); x++)
    {
        if( *(*cards)[x] > *(*rhs.cards)[x] )
        {
            return true;
        }
        else if( *(*cards)[x] < *(*rhs.cards)[x] )
        {
            return false;
        }
    }

    return false;
}