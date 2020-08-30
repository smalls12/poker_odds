#include "OnePairHand.hpp"

#include "FindAllPairs.hpp"

OnePairHand::OnePairHand(Player& player)
:   ExplicitHand(player, HandRank::ONE_PAIR)
{

}

bool OnePairHand::operator<(const ExplicitHand& rhs) const noexcept
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

bool OnePairHand::operator>(const ExplicitHand& rhs) const noexcept
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
