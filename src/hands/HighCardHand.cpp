#include "HighCardHand.hpp"

HighCardHand::HighCardHand(int id, const Cards& hand, const Cards& validated)
:   BaseHand(id, hand, HandRank::HIGH_CARD, validated)
{

}

bool HighCardHand::operator<(const HighCardHand& rhs) const noexcept
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
        else if( *cards[x] == *rhs.cards[x] )
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool HighCardHand::operator>(const HighCardHand& rhs) const noexcept
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
        else if( *cards[x] == *rhs.cards[x] )
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool HighCardHand::operator<(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator<(rhs);
}

bool HighCardHand::operator>(const BaseHand& rhs) const noexcept
{
    return BaseHand::operator>(rhs);
}