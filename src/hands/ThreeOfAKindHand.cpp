#include "ThreeOfAKindHand.hpp"

#include "FindAllPairs.hpp"

ThreeOfAKindHand::ThreeOfAKindHand(Player* player)
:   ExplicitHand(player, HandRank::THREE_OF_A_KIND)
{

}

bool ThreeOfAKindHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return false;
    }

    CardBuffer<7>::const_iterator pair = FindAllPairs::FindPair(*cards, cards->begin(), 3);
    CardBuffer<7>::const_iterator rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 3);

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

bool ThreeOfAKindHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return false;
    }

    CardBuffer<7>::const_iterator pair = FindAllPairs::FindPair(*cards, cards->begin(), 3);
    CardBuffer<7>::const_iterator rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 3);

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
