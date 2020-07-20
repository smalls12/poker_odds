#include "FourOfAKindHand.hpp"

FourOfAKindHand::FourOfAKindHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::FOUR_OF_A_KIND, validated)
{

}

bool FourOfAKindHand::operator<(const FourOfAKindHand& rhs) const noexcept
{
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

bool FourOfAKindHand::operator>(const FourOfAKindHand& rhs) const noexcept
{
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

bool FourOfAKindHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool FourOfAKindHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}