#include "FourOfAKindHand.hpp"

#include "FindAllPairs.hpp"

FourOfAKindHand::FourOfAKindHand(Player& player)
:   ExplicitHand(player, HandRank::FOUR_OF_A_KIND)
{

}

bool FourOfAKindHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return false;
    }

    CardBuffer<7>::const_iterator pair = FindAllPairs::FindPair(*cards, cards->begin(), 4);
    CardBuffer<7>::const_iterator rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 4);

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

bool FourOfAKindHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return false;
    }

    CardBuffer<7>::const_iterator pair = FindAllPairs::FindPair(*cards, cards->begin(), 4);
    CardBuffer<7>::const_iterator rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 4);

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
