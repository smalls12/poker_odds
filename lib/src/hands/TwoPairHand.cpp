#include "TwoPairHand.hpp"

#include "FindAllPairs.hpp"

TwoPairHand::TwoPairHand(Player& player)
:   ExplicitHand(player, HandRank::TWO_PAIR)
{

}

bool TwoPairHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return false;
    }

    CardBuffer<7>::const_iterator pair = FindAllPairs::FindPair(*cards, cards->begin(), 2);
    CardBuffer<7>::const_iterator rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 2);

    if( *(*pair) < *(*rhs_pair) )
    {
        return true;
    }

    if( *(*pair) > *(*rhs_pair) )
    {
        return false;
    }

    pair = FindAllPairs::FindPair(*cards, pair, 2);
    rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs_pair, 2);

    if( *(*pair) < *(*rhs_pair) )
    {
        return true;
    }

    if( *(*pair) > *(*rhs_pair) )
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

bool TwoPairHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return false;
    }

    CardBuffer<7>::const_iterator pair = FindAllPairs::FindPair(*cards, cards->begin(), 2);
    CardBuffer<7>::const_iterator rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 2);

    if( *(*pair) > *(*rhs_pair) )
    {
        return true;
    }

    if( *(*pair) < *(*rhs_pair) )
    {
        return false;
    }

    pair = FindAllPairs::FindPair(*cards, pair, 2);
    rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs_pair, 2);

    if( *(*pair) > *(*rhs_pair) )
    {
        return true;
    }

    if( *(*pair) < *(*rhs_pair) )
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
