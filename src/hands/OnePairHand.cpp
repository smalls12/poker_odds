#include "OnePairHand.hpp"

OnePairHand::OnePairHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::ONE_PAIR, validated)
{

}

bool OnePairHand::operator<(const OnePairHand& rhs) const noexcept
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

bool OnePairHand::operator>(const OnePairHand& rhs) const noexcept
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

bool OnePairHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool OnePairHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}